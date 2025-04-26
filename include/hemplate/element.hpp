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

template<std::size_t N>
using string_literal = based::string_literal<N>;

class HEMPLATE_EXPORT element_base
{
  friend class element;

  template<string_literal Tag>
    requires(Tag.size() > 0)
  friend class element_boolean;

  template<string_literal Tag>
    requires(Tag.size() > 0)
  friend class element_atomic;

  std::string m_otag;
  std::string m_ctag;

  using child_t = std::variant<element_base, std::string>;
  std::vector<child_t> m_cdn;

  template<typename... Args>
  explicit element_base(
      std::string_view open_tag, std::string_view close_tag, Args&&... args
  )
      : m_otag(open_tag)
      , m_ctag(close_tag)
  {
    const auto add = based::overload {
        [this](const std::ranges::forward_range auto& range)
          requires(!std::constructible_from<std::string_view, decltype(range)>)
        {
          m_cdn.reserve(std::size(m_cdn) + std::size(range));
          m_cdn.insert(std::end(m_cdn), std::begin(range), std::end(range));
        },
        [this](const std::string_view data)
        {
          m_cdn.emplace_back(std::string(data));
        },
        [this](const element_base& elem)
        {
          m_cdn.emplace_back(elem);
        },
    };

    m_cdn.reserve(sizeof...(args));
    (add(std::forward<Args>(args)), ...);
  }

  void render_children(std::ostream& out, std::size_t indent_value) const
  {
    const std::string indent(indent_value, ' ');

    const auto render = based::overload {
        [&](const element_base& elem)
        {
          elem.render(out, indent_value);
        },
        [&](const std::string& data)
        {
          out << indent << data << '\n';
        },
    };

    for (const auto& child : m_cdn) {
      std::visit(render, child);
    }
  }

  void render(std::ostream& out, std::size_t indent_value) const
  {
    const std::string indent(indent_value, ' ');

    if (m_otag.empty()) {
      render_children(out, indent_value);
      return;
    }

    out << indent << m_otag << '\n';
    render_children(out, indent_value + 2);
    out << indent << m_ctag << '\n';
  }

public:
  explicit operator std::string() const
  {
    std::stringstream ss;
    ss << *this;
    return ss.str();
  }

  friend std::ostream& operator<<(std::ostream& out, const element_base& element)
  {
    element.render(out, 0);
    return out;
  }
};

class HEMPLATE_EXPORT element : public element_base
{
public:
  template<typename... Args>
    requires(!std::same_as<attribute_list, std::remove_cvref_t<Args>> && ...)
  element(Args&&... args)  // NOLINT *-explicit
      : element_base("", "", std::forward<Args>(args)...)
  {
  }
};

template<string_literal Tag>
  requires(Tag.size() > 0)
class HEMPLATE_EXPORT element_boolean : public element_base
{
  static auto close() { return std::format("</{}>", Tag.data()); }
  static auto open(const attribute_list& attrs = {})
  {
    return attrs.empty() ? std::format("<{}>", Tag.data())
                         : std::format("<{} {}>", Tag.data(), attrs);
  }

public:
  template<typename... Args>
  explicit element_boolean(const attribute_list& attrs, Args&&... args)
      : element_base(open(attrs), close(), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
    requires(!std::same_as<attribute_list, std::remove_cvref_t<Args>> && ...)
  explicit element_boolean(Args&&... args)
      : element_base(open(), close(), std::forward<Args>(args)...)
  {
  }
};

template<string_literal Tag>
  requires(Tag.size() > 0)
class HEMPLATE_EXPORT element_atomic : public element_base
{
  static auto open(const attribute_list& attrs = {})
  {
    return attrs.empty() ? std::format("<{} />", Tag.data())
                         : std::format("<{} {} />", Tag.data(), attrs);
  }

public:
  explicit element_atomic(const attribute_list& list = {})
      : element_base("", "", open(list))
  {
  }
};

}  // namespace hemplate
