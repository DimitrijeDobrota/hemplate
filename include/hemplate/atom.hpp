#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::atom {

std::string format_time(std::int64_t sec);
std::string format_time_now();

class feed : public elementBuilder<tag<"feed">, element::Type::Boolean>
{
public:
  static constexpr const auto default_xmlns = "http://www.w3.org/2005/Atom";

  explicit feed(std::string xmlns,
                const std::derived_from<element> auto&... children)
      : elementBuilder({{"xmlns", std::move(xmlns)}}, children...)
  {
  }

  explicit feed(std::string xmlns, std::span<const element> children)
      : elementBuilder({{"xmlns", std::move(xmlns)}}, children)
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
using author        = elementBuilder<tag<"author">, element::Type::Boolean>;
using category      = elementBuilder<tag<"category">, element::Type::Boolean>;
using content       = elementBuilder<tag<"content">, element::Type::Boolean>;
using contributor   = elementBuilder<tag<"contributor">, element::Type::Boolean>;
using div           = elementBuilder<tag<"div">, element::Type::Boolean>;
using email         = elementBuilder<tag<"email">, element::Type::Boolean>;
using entry         = elementBuilder<tag<"entry">, element::Type::Boolean>;
using generator     = elementBuilder<tag<"generator">, element::Type::Boolean>;
using icon          = elementBuilder<tag<"icon">, element::Type::Boolean>;
using id            = elementBuilder<tag<"id">, element::Type::Boolean>;
using intervalBlock = elementBuilder<tag<"intervalBlock">, element::Type::Boolean>;
using link          = elementBuilder<tag<"link">, element::Type::Boolean>;
using logo          = elementBuilder<tag<"logo">, element::Type::Boolean>;
using meterReading  = elementBuilder<tag<"meterReading">, element::Type::Boolean>;
using name          = elementBuilder<tag<"name">, element::Type::Boolean>;
using published     = elementBuilder<tag<"published">, element::Type::Boolean>;
using readingType   = elementBuilder<tag<"readingType">, element::Type::Boolean>;
using rights        = elementBuilder<tag<"rights">, element::Type::Boolean>;
using source        = elementBuilder<tag<"source">, element::Type::Boolean>;
using subtitle      = elementBuilder<tag<"subtitle">, element::Type::Boolean>;
using summary       = elementBuilder<tag<"summary">, element::Type::Boolean>;
using text          = elementBuilder<tag<"">, element::Type::Boolean>;
using title         = elementBuilder<tag<"title">, element::Type::Boolean>;
using updated       = elementBuilder<tag<"updated">, element::Type::Boolean>;
using uri           = elementBuilder<tag<"uri">, element::Type::Boolean>;
using usagePoint    = elementBuilder<tag<"usagePoint">, element::Type::Boolean>;
// clang-format on

}  // namespace hemplate::atom
