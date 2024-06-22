#include "hemplate/attribute.hpp"

namespace hemplate
{

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
  m_attributes.emplace_back(name);
  return *this;
}

attributeList& attributeList::set(const std::string& name,
                                  const std::string& value)
{
  m_attributes.emplace_back(name, value);
  return *this;
}

void attributeList::render(std::ostream& out) const
{
  for (const auto& attr : m_attributes) {
    out << attr << ' ';
  }
}

}  // namespace hemplate
