#pragma once

#include <span>
#include <sstream>
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
    Special,
    Transparent,
  };

  const attribute_list& attributes() const { return *this; }

private:
  template<based::string_literal Tag, element::Type MyType>
  friend class element_builder;

  Type m_type;
  std::string m_tag;

  std::vector<element> m_children;
  std::string m_data;

  explicit element(
      Type type, std::string_view tag, const is_element auto&... children
  )
      : m_type(type)
      , m_tag(tag)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(Type type, std::string_view tag, std::string_view data)
      : m_type(type)
      , m_tag(tag)
      , m_data(data)
  {
  }

  explicit element(
      Type type, std::string_view tag, std::span<const element> children
  )
      : m_type(type)
      , m_tag(tag)
      , m_children(children.begin(), children.end())
  {
  }

  explicit element(
      Type type,
      std::string_view tag,
      attribute_list attributes,
      const is_element auto&... children
  )
      : attribute_list(std::move(attributes))
      , m_type(type)
      , m_tag(tag)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(
      Type type,
      std::string_view tag,
      attribute_list attributes,
      std::string_view data
  )
      : attribute_list(std::move(attributes))
      , m_type(type)
      , m_tag(tag)
      , m_data(data)
  {
  }

  explicit element(
      Type type,
      std::string_view tag,
      attribute_list attributes,
      std::span<const element> children
  )
      : attribute_list(std::move(attributes))
      , m_type(type)
      , m_tag(tag)
      , m_children(children.begin(), children.end())
  {
  }

  void render_atomic(std::ostream& out, std::size_t indent_value) const;
  void render_boolean(std::ostream& out, std::size_t indent_value) const;
  void render_comment(std::ostream& out, std::size_t indent_value) const;
  void render_special(std::ostream& out, std::size_t indent_value) const;
  void render_children(std::ostream& out, std::size_t indent_value) const;
  void render(std::ostream& out, std::size_t indent_value) const;

public:
  explicit operator std::string() const
  {
    std::stringstream ss;
    ss << *this;
    return ss.str();
  }

  friend std::ostream& operator<<(std::ostream& out, const element& element)
  {
    element.render(out, 0);
    return out;
  }
};

template<based::string_literal Tag, element::Type MyType>
class HEMPLATE_EXPORT element_builder : public element
{
public:
  // NOLINTBEGIN *-no-array-decay
  template<typename... Args>
  explicit element_builder(Args&&... args)
      : element(MyType, Tag.data(), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
  explicit element_builder(attribute_list list, Args&&... args)
      : element(
            MyType, Tag.data(), std::move(list), std::forward<Args>(args)...
        )
  {
  }
  // NOLINTEND *-no-array-decay
};

}  // namespace hemplate
