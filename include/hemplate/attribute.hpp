#pragma once

#include <string>
#include <utility>
#include <vector>

#include "hemplate/hemplate_export.hpp"
#include "hemplate/streamable.hpp"

namespace hemplate {

class HEMPLATE_EXPORT attribute : public streamable<attribute>
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

class HEMPLATE_EXPORT attributeList : public streamable<attributeList>
{
public:
  attributeList() = default;

  attributeList(std::initializer_list<attribute> list);
  attributeList(attribute attr);  // NOLINT

  attributeList& set(const attributeList& list);
  attributeList& set(const std::string& name);
  attributeList& set(const std::string& name, const std::string& value);

  attributeList add(const attributeList& list) const;
  attributeList add(const std::string& name) const;
  attributeList add(const std::string& name, const std::string& value) const;

  bool empty() const;

  explicit operator std::string() const
  {
    std::string res;

    if (!m_class.empty())
    {
      res += m_class;
      res += ' ';
    }

    if (!m_style.empty())
    {
      res += m_style;
      res += ' ';
    }

    for (const auto& attr : m_attributes)
    {
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

CUSTOM_FORMAT(hemplate::attribute)
CUSTOM_FORMAT(hemplate::attributeList)
