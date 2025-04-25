#pragma once

#include <span>
#include <sstream>
#include <string>
#include <vector>

#include <based/string.hpp>
#include <based/template.hpp>

#include "hemplate/attribute.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class element_base;

template<typename T>
concept is_element = std::derived_from<T, element_base>;

class HEMPLATE_EXPORT element_base
{
public:
  enum class Type : uint8_t
  {
    Blank,
    Atomic,
    Boolean,
  };

  template<based::string_literal Tag, Type MyType>
  friend class element_builder;

private:
  std::string m_otag;
  std::string m_ctag;

  using child_t = std::variant<element_base, std::string>;
  std::vector<child_t> m_cdn;

  void render_children(std::ostream& out, std::size_t indent_value) const;
  void render(std::ostream& out, std::size_t indent_value) const;

  template<typename... Args>
  explicit element_base(
      std::string_view open_tag, std::string_view close_tag, Args&&... args
  )
      : m_otag(open_tag)
      , m_ctag(close_tag)
  {
    m_cdn.reserve(sizeof...(args));
    const auto add = based::overload {
        [&](const element_base& elem) { m_cdn.emplace_back(elem); },
        [&](const std::ranges::forward_range auto& range)
          requires(!std::constructible_from<std::string_view, decltype(range)>)
        {
          m_cdn.reserve(std::size(m_cdn) + std::size(range));
          m_cdn.insert(std::end(m_cdn), std::begin(range), std::end(range));
        },
        [&](const std::string_view data)
        { m_cdn.emplace_back(std::string(data)); },
        };
    (add(std::forward<Args>(args)), ...);
  }

public:
  explicit operator std::string() const
  {
    std::stringstream ss;
    ss << *this;
    return ss.str();
  }

  friend std::ostream& operator<<(
      std::ostream& out, const element_base& element
  )
  {
    element.render(out, 0);
    return out;
  }
};

template<based::string_literal Tag, element_base::Type MyType>
class element_builder;

template<>
class HEMPLATE_EXPORT element_builder<"", element_base::Type::Blank>
    : public element_base
{
public:
  template<typename... Args>
    requires(!std::same_as<attribute_list, std::remove_cvref_t<Args>> && ...)
  explicit element_builder(Args&&... args)
      : element_base("", "", std::forward<Args>(args)...)
  {
  }
};

using element = element_builder<"", element_base::Type::Blank>;

template<based::string_literal Tag>
class HEMPLATE_EXPORT element_builder<Tag, element_base::Type::Boolean>
    : public element_base
{
  static auto close() { return std::format("</{}>", Tag.data()); }
  static auto open(const attribute_list& attrs = {})
  {
    return attrs.empty() ? std::format("<{}>", Tag.data())
                         : std::format("<{} {}>", Tag.data(), attrs);
  }

public:
  template<typename... Args>
  explicit element_builder(const attribute_list& attrs, Args&&... args)
      : element_base(open(attrs), close(), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
    requires(!std::same_as<attribute_list, std::remove_cvref_t<Args>> && ...)
  explicit element_builder(Args&&... args)
      : element_base(open(), close(), std::forward<Args>(args)...)
  {
  }
};

template<based::string_literal Tag>
using element_boolean = element_builder<Tag, element_base::Type::Boolean>;

template<based::string_literal Tag>
class HEMPLATE_EXPORT element_builder<Tag, element_base::Type::Atomic>
    : public element_base
{
  static auto open(const attribute_list& attrs = {})
  {
    return attrs.empty() ? std::format("<{} />", Tag.data())
                         : std::format("<{} {} />", Tag.data(), attrs);
  }

public:
  explicit element_builder(const attribute_list& list = {})
      : element_base("", "", open(list))
  {
  }
};

template<based::string_literal Tag>
using element_atomic = element_builder<Tag, element_base::Type::Atomic>;

}  // namespace hemplate
