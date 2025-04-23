#pragma once

#include <format>
#include <string>
#include <vector>

#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

struct HEMPLATE_EXPORT attribute
{
  std::string name;
  std::string value;

  explicit attribute(std::string_view namee)
      : name(namee)
  {
  }

  attribute(std::string_view namee, std::string_view val)
      : name(namee)
      , value(val)
  {
  }

  operator std::string() const  // NOLINT *-explicit-constructor
  {
    return name + "=\"" + value + "\"";
  }

  bool operator==(const attribute& rhs) const = default;

  bool empty() const { return value.empty(); }

  attribute& append(std::string_view delim, const std::string& val);
};

class HEMPLATE_EXPORT attribute_list
{
public:
  attribute_list() = default;

  attribute_list(std::initializer_list<attribute> list);
  attribute_list(attribute attr);  // NOLINT *-explicit-constructor

  attribute_list& set(const attribute_list& list);
  attribute_list& set(attribute attr);

  attribute_list add(const attribute_list& list) const;
  attribute_list add(attribute attr) const;

  bool empty() const;

  explicit operator std::string() const
  {
    std::string res;

    if (!m_class.empty()) {
      res += m_class;
      res += ' ';
    }

    if (!m_style.empty()) {
      res += m_style;
      res += ' ';
    }

    for (const auto& attr : m_attributes) {
      res += attr;
      res += ' ';
    }

    return res;
  }

private:
  std::vector<attribute> m_attributes;
  attribute m_class = attribute("class");
  attribute m_style = attribute("style");
};

}  // namespace hemplate

template<>
struct std::formatter<hemplate::attribute>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(const hemplate::attribute& type, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", static_cast<std::string>(type));
  }
};

template<>
struct std::formatter<hemplate::attribute_list>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(const hemplate::attribute_list& type,
                     std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", static_cast<std::string>(type));
  }
};
