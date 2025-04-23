#pragma once

#include <span>
#include <string>
#include <vector>

#include "hemplate/attribute.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT element
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

private:
  bool* m_state;
  Type m_type;
  std::string m_name;

  attribute_list m_attributes;
  std::vector<element> m_children;
  std::string m_data;

  explicit element(bool& state,
                   Type type,
                   std::string_view name,
                   const std::derived_from<element> auto&... children)
      : m_state(&state)
      , m_type(type)
      , m_name(name)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(
      bool& state,
      Type type,
      std::string_view name,  // NOLINT *-easily-swappable-parameters
      std::string_view data)
      : m_state(&state)
      , m_type(type)
      , m_name(name)
      , m_data(data)
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view name,
                   std::span<const element> children)
      : m_state(&state)
      , m_type(type)
      , m_name(name)
      , m_children(children.begin(), children.end())
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view name,
                   attribute_list attributes,
                   const std::derived_from<element> auto&... children)
      : m_state(&state)
      , m_type(type)
      , m_name(name)
      , m_attributes(std::move(attributes))
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view name,
                   attribute_list attributes,
                   std::string_view data)
      : m_state(&state)
      , m_type(type)
      , m_name(name)
      , m_attributes(std::move(attributes))
      , m_data(data)
  {
  }

  explicit element(bool& state,
                   Type type,
                   std::string_view name,
                   attribute_list attributes,
                   std::span<const element> children)
      : m_state(&state)
      , m_type(type)
      , m_name(name)
      , m_attributes(std::move(attributes))
      , m_children(children.begin(), children.end())
  {
  }

  template<typename Tag, element::Type MyType>
  friend class element_builder;

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

  element& add(const element& elem);

  element& set(const std::string& name);
  element& set(const std::string& name, const std::string& value);

  bool get_state() const { return *m_state; }
  bool tgl_state() const { return *m_state = !*m_state; }
};

template<typename Tag, element::Type MyType>
class HEMPLATE_EXPORT element_builder : public element
{
  static bool m_state;  // NOLINT

public:
  explicit element_builder(std::string_view data)
      : element(m_state, MyType, Tag::get_name(), data)
  {
  }

  explicit element_builder(const std::derived_from<element> auto&... children)
      : element(m_state, MyType, Tag::get_name(), children...)
  {
  }

  explicit element_builder(std::span<const element> children)
      : element(m_state, MyType, Tag::get_name(), children)
  {
  }

  explicit element_builder(attribute_list attributes, std::string_view data)
      : element(m_state, MyType, Tag::get_name(), std::move(attributes), data)
  {
  }

  explicit element_builder(attribute_list attributes,
                           const std::derived_from<element> auto&... children)
      : element(m_state,
                MyType,
                Tag::get_name(),
                std::move(attributes),
                children...)
  {
  }

  explicit element_builder(attribute_list attributes,
                           std::span<const element> children)
      : element(
            m_state, MyType, Tag::get_name(), std::move(attributes), children)
  {
  }
};

template<typename Tag, element::Type Type>
bool element_builder<Tag, Type>::m_state = false;  // NOLINT

}  // namespace hemplate
