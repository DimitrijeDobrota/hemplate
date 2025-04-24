#pragma once

#include <format>
#include <string>
#include <vector>

#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT attribute
{
  std::string m_name;
  std::string m_value;

public:
  attribute(std::string_view name)  // NOLINT *-explicit-constructor
      : m_name(name)
  {
  }

  attribute(std::string_view name, std::string_view val)
      : m_name(name)
      , m_value(val)
  {
  }

  explicit operator std::string() const
  {
    if (empty()) {
      return name();
    }
    return name() + "=\"" + value() + "\"";
  }

  const std::string& name() const { return m_name; }
  const std::string& value() const { return m_value; }

  bool operator==(const attribute& rhs) const = default;

  bool empty() const { return value().empty(); }

  attribute& append(std::string_view delim, const std::string& val);
};

class HEMPLATE_EXPORT attribute_list
{
public:
  attribute_list() = default;

  attribute_list(std::initializer_list<attribute> list);
  attribute_list(attribute attr);  // NOLINT *-explicit-constructor
  attribute_list(attribute_list attrs, std::initializer_list<attribute> list);

  void set(const attribute_list& list);
  void set(attribute attr);

  bool empty() const
  {
    return m_attributes.empty() && m_class.empty() && m_style.empty();
  }

  explicit operator std::string() const
  {
    std::string res;

    if (!m_class.empty()) {
      res += std::string(m_class);
      res += ' ';
    }

    if (!m_style.empty()) {
      res += std::string(m_style);
      res += ' ';
    }

    for (const auto& attr : m_attributes) {
      res += std::string(attr);
      res += ' ';
    }

    if (!res.empty()) {
      res.pop_back();
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
struct std::formatter<hemplate::attribute_list>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(
      const hemplate::attribute_list& type, std::format_context& ctx
  )
  {
    return std::format_to(ctx.out(), "{}", static_cast<std::string>(type));
  }
};
