#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::atom
{

std::string format_time(std::int64_t sec);
std::string format_time_now();

class HEMPLATE_EXPORT feed
    : public element_builder<tag<"feed">, element::Type::Boolean>
{
public:
  static constexpr const auto default_xmlns = "http://www.w3.org/2005/Atom";

  explicit feed(std::string xmlns,
                const std::derived_from<element> auto&... children)
      : element_builder({{"xmlns", std::move(xmlns)}}, children...)
  {
  }

  explicit feed(std::string xmlns, std::span<const element> children)
      : element_builder({{"xmlns", std::move(xmlns)}}, children)
  {
  }

  explicit feed(const std::derived_from<element> auto&... children)
      : feed(default_xmlns, children...)
  {
  }

  explicit feed(std::span<const element> children)
      : feed(default_xmlns, children)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::transparent;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN *-identifier-naming
using author        = element_builder<tag<"author">, element::Type::Boolean>;
using category      = element_builder<tag<"category">, element::Type::Boolean>;
using content       = element_builder<tag<"content">, element::Type::Boolean>;
using contributor   = element_builder<tag<"contributor">, element::Type::Boolean>;
using div           = element_builder<tag<"div">, element::Type::Boolean>;
using email         = element_builder<tag<"email">, element::Type::Boolean>;
using entry         = element_builder<tag<"entry">, element::Type::Boolean>;
using generator     = element_builder<tag<"generator">, element::Type::Boolean>;
using icon          = element_builder<tag<"icon">, element::Type::Boolean>;
using id            = element_builder<tag<"id">, element::Type::Boolean>;
using intervalBlock = element_builder<tag<"intervalBlock">, element::Type::Boolean>;
using link          = element_builder<tag<"link">, element::Type::Boolean>;
using logo          = element_builder<tag<"logo">, element::Type::Boolean>;
using meterReading  = element_builder<tag<"meterReading">, element::Type::Boolean>;
using name          = element_builder<tag<"name">, element::Type::Boolean>;
using published     = element_builder<tag<"published">, element::Type::Boolean>;
using readingType   = element_builder<tag<"readingType">, element::Type::Boolean>;
using rights        = element_builder<tag<"rights">, element::Type::Boolean>;
using source        = element_builder<tag<"source">, element::Type::Boolean>;
using subtitle      = element_builder<tag<"subtitle">, element::Type::Boolean>;
using summary       = element_builder<tag<"summary">, element::Type::Boolean>;
using text          = element_builder<tag<"">, element::Type::Boolean>;
using title         = element_builder<tag<"title">, element::Type::Boolean>;
using updated       = element_builder<tag<"updated">, element::Type::Boolean>;
using uri           = element_builder<tag<"uri">, element::Type::Boolean>;
using usagePoint    = element_builder<tag<"usagePoint">, element::Type::Boolean>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::atom
