#include <string>

#include "hemplate/hemplate.hpp"

exported_class::exported_class()
    : m_name {"hemplate"}
{
}

char const* exported_class::name() const
{
  return m_name.c_str();
}
