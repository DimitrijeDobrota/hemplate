#include "hemplate/element.hpp"

namespace hemplate
{

element& element::add(const element& elem)
{
  m_embeded.add(elem);
  return *this;
}

element& element::add(std::unique_ptr<element> elem)
{
  m_embeded.add(std::move(elem));
  return *this;
}

void element::render(std::ostream& out) const
{
  if (get_type() == Type::Boolean && m_data.empty()) {
    out << '<' << get_name() << '>';

    m_embeded.render(out);

    out << "</" << get_name() << '>';
  } else {
    out << '<' << get_name() << '>';

    if (!m_embeded.empty()) {
      m_embeded.render(out);
    } else {
      out << m_data;
    }

    out << "</" << get_name() << '>';
  }
}

elementList::elementList(const elementList& rhs)
{
  this->operator=(rhs);
}

elementList& elementList::operator=(const elementList& rhs)
{
  if (this == &rhs) return *this;

  m_elems.clear();
  for (const auto& elem : rhs.m_elems) {
    add(*elem);
  }

  return *this;
}

elementList& elementList::add(const element& elem)
{
  m_elems.push_back(elem.clone());
  return *this;
}

elementList& elementList::add(std::unique_ptr<element> elem)
{
  m_elems.push_back(std::move(elem));
  return *this;
}

void elementList::render(std::ostream& out) const
{
  for (const auto& elem : m_elems) {
    elem->render(out);
  }
}

}  // namespace hemplate
