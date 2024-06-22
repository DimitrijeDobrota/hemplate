#pragma once

#include <string>

#include "hemplate/hemplate_export.hpp"

class HEMPLATE_EXPORT exported_class
{
public:
  exported_class();

  char const* name() const;

private:
  HEMPLATE_SUPPRESS_C4251
  std::string m_name;
};
