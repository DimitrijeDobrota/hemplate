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

class HEMPLATE_EXPORT element
{
public:
  enum class Type : uint8_t
  {
    Atomic,
    Boolean,
  };

  template<based::string_literal Tag, Type MyType>
  friend class element_builder;

private:
  std::string m_otag;
  std::string m_ctag;

  std::vector<element> m_children;
  std::string m_data;

  void render_children(std::ostream& out, std::size_t indent_value) const;
  void render(std::ostream& out, std::size_t indent_value) const;

  explicit element(
      std::string_view open_tag,
      std::string_view close_tag,
      const is_element auto&... children
  )
      : m_otag(open_tag)
      , m_ctag(close_tag)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(
      std::string_view open_tag,
      std::string_view close_tag,
      std::span<const element> children
  )
      : m_otag(open_tag)
      , m_ctag(close_tag)
      , m_children(std::begin(children), std::end(children))
  {
  }

public:
  // NOLINTBEGIN *-explicit-constructor
  element(std::string_view data)
      : m_data(data)
  {
  }

  element(const is_element auto&... children)
      : m_children(std::initializer_list<element> {children...})
  {
  }

  element(std::span<const element> children)
      : m_children(std::begin(children), std::end(children))
  {
  }
  // NOLINTEND *-explicit-constructor

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
class element_builder;

template<based::string_literal Tag>
class HEMPLATE_EXPORT element_builder<Tag, element::Type::Boolean>
    : public element
{
  static auto close() { return std::format("</{}>", Tag.data()); }
  static auto open(const attribute_list& attrs = {})
  {
    return attrs.empty() ? std::format("<{}>", Tag.data())
                         : std::format("<{} {}>", Tag.data(), attrs);
  }

public:
  template<typename... Args>
  explicit element_builder(Args&&... args)
      : element(open(), close(), element(std::forward<Args>(args))...)
  {
  }

  explicit element_builder(std::span<const element> children)
      : element(open(), close(), children)
  {
  }
  template<typename... Args>
  explicit element_builder(const attribute_list& attrs, Args&&... args)
      : element(open(attrs), close(), element(std::forward<Args>(args))...)
  {
  }

  explicit element_builder(
      const attribute_list& attrs, std::span<const element> children
  )
      : element(open(attrs), close(), children)
  {
  }
};

template<based::string_literal Tag>
using element_boolean = element_builder<Tag, element::Type::Boolean>;

template<based::string_literal Tag>
class HEMPLATE_EXPORT element_builder<Tag, element::Type::Atomic>
    : public element
{
  static auto open(const attribute_list& attrs = {})
  {
    return attrs.empty() ? std::format("<{} />", Tag.data())
                         : std::format("<{} {} />", Tag.data(), attrs);
  }

public:
  explicit element_builder(const attribute_list& list = {})
      : element(open(list))
  {
  }
};

template<based::string_literal Tag>
using element_atomic = element_builder<Tag, element::Type::Atomic>;

}  // namespace hemplate
