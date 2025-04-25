#include <ostream>
#include <string>

#include "hemplate/element.hpp"

namespace hemplate
{

void element::render_children(std::ostream& out, std::size_t indent_value) const
{
  for (const auto& child : m_children) {
    child.render(out, indent_value);
  }
}

void element::render(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');

  if (m_otag.empty()) {
    if (!m_data.empty()) {
      out << indent << m_data << '\n';
    } else {
      render_children(out, indent_value);
    }
    return;
  }

  if (!m_children.empty()) {
    out << indent << m_otag << '\n';
    render_children(out, indent_value + 2);
    out << indent << m_ctag << '\n';
    return;
  }

  out << indent << m_otag << m_ctag << '\n';
}

}  // namespace hemplate
