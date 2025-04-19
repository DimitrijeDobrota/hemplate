#include <format>
#include <ostream>
#include <string>

#include "hemplate/element.hpp"

namespace hemplate {

element& element::add(const element& elem)
{
  m_children.emplace_back(elem);
  return *this;
}

element& element::set(const std::string& name)
{
  m_attributes.set(name);
  return *this;
}

element& element::set(const std::string& name, const std::string& value)
{
  m_attributes.set(name, value);
  return *this;
}

void element::render(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');

  if (m_name.empty())
  {
    out << indent << m_data << '\n';
    return;
  }

  if (m_type == Type::Atomic)
  {
    out << indent << std::format("<{} {}/>\n", m_name, m_attributes);
    return;
  }

  if (!m_data.empty())
  {
    out << indent << std::format("<{} {}>\n", m_name, m_attributes);

    if (!m_children.empty())
    {
      for (const auto& child : m_children)
      {
        child.render(out, indent_value + 2);
      }
    }
    else
    {
      out << indent << "  " << m_data << '\n';
    }

    out << indent << std::format("</{}>\n", m_name);
    return;
  }

  if (m_children.empty())
  {
    /*
        tgl_state();
        get_state() ? open_tag(false) : close_tag();
    */
  }
  else
  {
    out << indent << std::format("<{} {}>\n", m_name, m_attributes);
    for (const auto& child : m_children)
    {
      child.render(out, indent_value + 2);
    }
    out << indent << std::format("</{}>\n", m_name);
  }
}

}  // namespace hemplate
