#pragma once

#include <ostream>

#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT streamable
{
public:
  streamable()                                 = default;
  streamable(const streamable&)                = default;
  streamable(streamable&&) noexcept            = default;
  streamable& operator=(const streamable&)     = default;
  streamable& operator=(streamable&&) noexcept = default;
  virtual ~streamable()                        = default;

  virtual void render(std::ostream& out) const = 0;

  friend std::ostream& operator<<(std::ostream& out, const streamable& obj)
  {
    obj.render(out);
    return out;
  }
};

}  // namespace hemplate
