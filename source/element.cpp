#include "hemplate/element.hpp"

namespace hemplate {

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

void element::render(std::ostream& out) const
{
  const auto open_tag = [this, &out](bool atomic)
  {
    out << '<' << get_name();
    if (!m_attributes.empty()) out << ' ', m_attributes.render(out);
    out << (atomic ? " />" : ">");
  };

  const auto close_tag = [this, &out]() { out << "</" << get_name() << '>'; };

  if (m_type == Type::Atomic)
  {
    open_tag(true);
    return;
  }

  if (!m_data.empty())
  {
    open_tag(false);
    if (!m_embeded.empty()) m_embeded.render(out);
    else out << m_data;
    close_tag();
    return;
  }

  if (m_embeded.empty())
  {
    tgl_state();
    get_state() ? open_tag(false) : close_tag();
  }
  else
  {
    open_tag(false);
    m_embeded.render(out);
    close_tag();
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
  for (const auto& elem : rhs.m_elems) add(*elem);

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
  for (const auto& elem : m_elems) elem->render(out);
}

}  // namespace hemplate
