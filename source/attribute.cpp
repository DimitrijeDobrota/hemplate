#include "hemplate/attribute.hpp"

namespace hemplate
{

attribute_list::attribute_list(std::initializer_list<attribute> list)
{
  for (const auto& attr : list) {
    set(attr.get_name(), attr.get_value());
  }
}

attribute_list::attribute_list(attribute attr)  // NOLINT
{
  set(attr.get_name(), attr.get_value());
}

bool attribute_list::empty() const
{
  return m_attributes.empty() && m_class.get_value().empty()
      && m_style.get_value().empty();
}

attribute_list& attribute_list::set(const attribute_list& list)
{
  for (const auto& attr : list.m_attributes) {
    set(attr.get_name(), attr.get_value());
  }
  set("class", list.m_class);
  set("style", list.m_style);

  return (*this);
}

attribute_list& attribute_list::set(const std::string& name)
{
  if (name != "class" && name != "style") {
    m_attributes.emplace_back(name);
  }
  return *this;
}

attribute_list& attribute_list::set(const std::string& name,
                                    const std::string& value)
{
  if (name == "class") {
    if (m_class.get_value().empty()) {
      m_class.set_value(value);
    } else {
      m_class.set_value(m_class.get_value() + " " + value);
    }
  } else if (name == "style") {
    if (m_style.get_value().empty()) {
      m_style.set_value(value);
    } else {
      m_style.set_value(m_style.get_value() + "; " + value);
    }
  } else {
    m_attributes.emplace_back(name, value);
  }

  return *this;
}

attribute_list attribute_list::add(const attribute_list& list) const
{
  attribute_list res = *this;
  res.set(list);
  return res;
}

attribute_list attribute_list::add(const std::string& name) const
{
  attribute_list res = *this;
  res.set(name);
  return res;
}

attribute_list attribute_list::add(const std::string& name,
                                   const std::string& value) const
{
  attribute_list res = *this;
  res.set(name, value);
  return res;
}

}  // namespace hemplate
