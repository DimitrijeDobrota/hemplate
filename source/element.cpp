#include <ostream>
#include <string>

#include "hemplate/element.hpp"

namespace hemplate
{

void element_base::render_children(std::ostream& out, std::size_t indent_value)
    const
{
  const auto render = based::overload {
      [&](const element_base& elem) { elem.render(out, indent_value); },
      [&](const std::string& data)
      { out << std::string(indent_value, ' ') << data << '\n'; },
  };

  for (const auto& child : m_cdn) {
    std::visit(render, child);
  }
}

void element_base::render(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');

  if (m_otag.empty()) {
    render_children(out, indent_value);
    return;
  }

  if (!m_cdn.empty()) {
    out << indent << m_otag << '\n';
    render_children(out, indent_value + 2);
    out << indent << m_ctag << '\n';
    return;
  }

  out << indent << m_otag << m_ctag << '\n';
}

}  // namespace hemplate
