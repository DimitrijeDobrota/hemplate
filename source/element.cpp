#include <format>
#include <ostream>
#include <string>

#include "hemplate/element.hpp"

namespace hemplate
{

void element::render_comment(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');

  out << indent << "<!-- " << m_data << " -->\n";
}

void element::render_atomic(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');

  out << indent << std::format("<{} {}/>\n", m_tag, attributes());
}

void element::render_xml(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');
  out << indent << std::format("<?xml {}?>\n", attributes());
}

void element::render_children(std::ostream& out, std::size_t indent_value) const
{
  for (const auto& child : m_children) {
    child.render(out, indent_value);
  }
}

void element::render(std::ostream& out, std::size_t indent_value) const
{
  const std::string indent(indent_value, ' ');

  switch (m_type) {
    case Type::Atomic:
      render_atomic(out, indent_value);
      return;
    case Type::Comment:
      render_comment(out, indent_value);
      return;
    case Type::Xml:
      render_xml(out, indent_value);
      return;
    case Type::Transparent:
      render_children(out, indent_value);
      return;
    default:
      break;
  }

  if (m_tag.empty()) {
    out << indent << m_data << '\n';
    return;
  }

  if (!m_data.empty()) {
    out << indent << std::format("<{} {}>\n", m_tag, attributes());

    if (!m_children.empty()) {
      render_children(out, indent_value + 2);
    } else {
      out << indent << "  " << m_data << '\n';
    }

    out << indent << std::format("</{}>\n", m_tag);
    return;
  }

  if (m_children.empty()) {
    if (tgl_state()) {
      out << indent << std::format("<{} {}>\n", m_tag, attributes());
    } else {
      out << indent << std::format("</{}>\n", m_tag);
    }
  } else {
    out << indent << std::format("<{} {}>\n", m_tag, attributes());
    render_children(out, indent_value + 2);
    out << indent << std::format("</{}>\n", m_tag);
  }
}

}  // namespace hemplate
