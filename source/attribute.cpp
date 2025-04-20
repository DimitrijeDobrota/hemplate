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

bool attributeList::empty() const
{
  return m_attributes.empty() && m_class.get_value().empty()
      && m_style.get_value().empty();
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

attributeList attributeList::add(const std::string& name) const
{
  attributeList res = *this;
  res.set(name);
  return res;
}

attributeList attributeList::add(const std::string& name,
                                 const std::string& value) const
{
  attributeList res = *this;
  res.set(name, value);
  return res;
}

}  // namespace hemplate
