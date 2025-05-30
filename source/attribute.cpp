#include "hemplate/attribute.hpp"

namespace hemplate
{

attribute& attribute::append(std::string_view delim, const std::string& val)
{
  if (!val.empty()) {
    if (!empty()) {
      m_value += std::string(delim);
    }
    m_value += val;
  }
  return *this;
}

attribute_list::attribute_list(std::initializer_list<attribute> list)
{
  for (const auto& attr : list) {
    set(attr);
  }
}

attribute_list::attribute_list(attribute attr)
{
  set(std::move(attr));
}

attribute_list::attribute_list(
    attribute_list attrs, std::initializer_list<attribute> list
)
    : attribute_list(std::move(attrs))
{
  for (const auto& attr : list) {
    set(attr);
  }
}

void attribute_list::set(const attribute_list& list)
{
  for (const auto& attr : list.m_attributes) {
    set(attr);
  }

  set(list.m_class);
  set(list.m_style);
}

void attribute_list::set(attribute attr)
{
  if (attr.name() == "class") {
    m_class.append(" ", attr.value());
    return;
  }

  if (attr.name() == "style") {
    m_style.append("; ", attr.value());
    return;
  }

  m_attributes.emplace_back(std::move(attr));
}

}  // namespace hemplate
