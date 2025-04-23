#pragma once
#include <span>
#include <string>
#include <vector>

#include <based/string.hpp>

#include "hemplate/attribute.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class element;

template<typename T>
concept is_element = std::derived_from<T, element>;

class HEMPLATE_EXPORT element : public attribute_list
{
public:
  enum class Type : uint8_t
  {
    Atomic,
    Boolean,
    Comment,
    Xml,
    Transparent,
  };

  const attribute_list& attributes() const { return *this; }

private:
  using attribute_list::empty;

  template<based::string_literal Tag, element::Type MyType>
  friend class element_builder;

  bool* m_state;
  Type m_type;
  std::string m_tag;

  std::vector<element> m_children;
  std::string m_data;

  explicit element(bool& state,
                   Type type,
                   std::string_view tag,
                   const is_element auto&... children)
      : m_state(&state)
      , m_type(type)
      , m_tag(tag)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view tag,
                   std::string_view data)
      : m_state(&state)
      , m_type(type)
      , m_tag(tag)
      , m_data(data)
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view tag,
                   std::span<const element> children)
      : m_state(&state)
      , m_type(type)
      , m_tag(tag)
      , m_children(children.begin(), children.end())
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view tag,
                   attribute_list attributes,
                   const is_element auto&... children)
      : attribute_list(std::move(attributes))
      , m_state(&state)
      , m_type(type)
      , m_tag(tag)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view tag,
                   attribute_list attributes,
                   std::string_view data)
      : attribute_list(std::move(attributes))
      , m_state(&state)
      , m_type(type)
      , m_tag(tag)
      , m_data(data)
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view tag,
                   attribute_list attributes,
                   std::span<const element> children)
      : attribute_list(std::move(attributes))
      , m_state(&state)
      , m_type(type)
      , m_tag(tag)
      , m_children(children.begin(), children.end())
  {
  }

  void render_atomic(std::ostream& out, std::size_t indent_value) const;
  void render_boolean(std::ostream& out, std::size_t indent_value) const;
  void render_comment(std::ostream& out, std::size_t indent_value) const;
  void render_xml(std::ostream& out, std::size_t indent_value) const;
  void render_children(std::ostream& out, std::size_t indent_value) const;
  void render(std::ostream& out, std::size_t indent_value) const;

public:
  friend std::ostream& operator<<(std::ostream& out, const element& element)
  {
    element.render(out, 0);
    return out;
  }

  element& add(const element& elem)
  {
    m_children.emplace_back(elem);
    return *this;
  }

  bool get_state() const { return *m_state; }
  bool tgl_state() const { return *m_state = !*m_state; }
};

template<based::string_literal Tag, element::Type MyType>
class HEMPLATE_EXPORT element_builder : public element
{
  static bool m_state;  // NOLINT

public:
  template<typename... Args>
  explicit element_builder(Args&&... args)
      // NOLINTNEXTLINE *-no-array-decay
      : element(m_state, MyType, Tag.data(), std::forward<Args>(args)...)
  {
  }
};

template<based::string_literal Tag, element::Type Type>
bool element_builder<Tag, Type>::m_state = false;  // NOLINT

}  // namespace hemplate
