#pragma once

#include <format>
#include <string>
#include <utility>
#include <vector>

#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT attribute
{
public:
  attribute(std::string name)  // NOLINT
      : m_name(std::move(name))
  {
  }

  attribute(std::string name, std::string value)  // NOLINT
      : m_name(std::move(name))
      , m_value(std::move(value))
  {
  }

  bool operator==(const attribute& rhs) const = default;

  const std::string& get_name() const { return m_name; }
  const std::string& get_value() const { return m_value; }

  void set_name(const std::string& name) { m_name = name; }
  void set_value(const std::string& value) { m_value = value; }

  bool empty() const { return get_value().empty(); }

  // NOLINTNEXTLINE *-explicit-constructor
  operator std::string() const
  {
    return get_name() + "=\"" + get_value() + "\"";
  }

private:
  std::string m_name;
  std::string m_value;
};

class HEMPLATE_EXPORT attribute_list
{
public:
  attribute_list() = default;

  attribute_list(std::initializer_list<attribute> list);
  attribute_list(attribute attr);  // NOLINT

  attribute_list& set(const attribute_list& list);
  attribute_list& set(const std::string& name);
  attribute_list& set(const std::string& name, const std::string& value);

  attribute_list add(const attribute_list& list) const;
  attribute_list add(const std::string& name) const;
  attribute_list add(const std::string& name, const std::string& value) const;

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
