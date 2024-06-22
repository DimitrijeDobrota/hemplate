#include <algorithm>

#include "hemplate/attribute.hpp"

namespace hemplate {

attributeList::attributeList(std::initializer_list<attribute> list)
{
  for (const auto& attr : list) set(attr.get_name(), attr.get_value());
}

attributeList::attributeList(attribute attr)  // NOLINT
{
  set(attr.get_name(), attr.get_value());
}

bool attribute::operator!=(const attribute& rhs) const
{
  return !(*this == rhs);
}

bool attribute::operator==(const attribute& rhs) const
{
  return m_name == rhs.m_name && m_value == rhs.m_value;
}

void attribute::render(std::ostream& out) const
{
  out << get_name() << "=\"" << get_value() << "\"";
}

attributeList& attributeList::set(const std::string& name)
{
  if (name != "class" && name != "style") m_attributes.emplace_back(name);
  return *this;
}

attributeList& attributeList::set(const std::string& name,
                                  const std::string& value)
{
  if (name == "class")
  {
    if (m_class.get_value().empty()) m_class.set_value(value);
    else m_class.set_value(m_class.get_value() + " " + value);
  }
  else if (name == "style")
  {
    if (m_style.get_value().empty()) m_style.set_value(value);
    else m_style.set_value(m_style.get_value() + "; " + value);
  }
  else m_attributes.emplace_back(name, value);

  return *this;
}

void attributeList::render(std::ostream& out) const
{
  if (!m_class.get_value().empty()) out << m_class << ' ';
  if (!m_style.get_value().empty()) out << m_style << ' ';

  for (const auto& attr : m_attributes) out << attr << ' ';
}

}  // namespace hemplate
