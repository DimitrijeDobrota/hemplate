#pragma once

#include <format>
#include <ostream>

#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

template<typename D>
class HEMPLATE_EXPORT streamable
{
  friend D;

  streamable() = default;

public:
  bool operator==(const streamable& rhs) const = default;

  friend std::ostream& operator<<(std::ostream& out, const streamable& obj)
  {
    return out << static_cast<std::string>(static_cast<D&>(obj));
  }
};

// NOLINTNEXTLINE cppcoreguidelines-macro-usage
#define CUSTOM_FORMAT(Type) \
  template<> \
  struct std::formatter<Type> \
  { \
    constexpr auto parse(std::format_parse_context& ctx) \
    { \
      return ctx.begin(); \
    } \
\
    auto format(const Type& type, std::format_context& ctx) const \
    { \
      return std::format_to(ctx.out(), "{}", static_cast<std::string>(type)); \
    } \
  };

}  // namespace hemplate
