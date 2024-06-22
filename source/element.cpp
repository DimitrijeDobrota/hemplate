#include "hemplate/element.hpp"

namespace hemplate
{

void element::render(std::ostream& out) const
{
  if (get_type() == Type::Boolean) {
    out << "<" << get_name() << ">";
    out << get_data();
    out << "</" << get_name() << ">";
  } else {
    out << "<" << get_name() << " />";
  }
}

}  // namespace hemplate
