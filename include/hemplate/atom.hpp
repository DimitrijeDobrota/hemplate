#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::atom
{

std::string format_time(std::int64_t sec);
std::string format_time_now();

class HEMPLATE_EXPORT feed
    : public element_builder<"feed", element::Type::Boolean>
{
  static auto attributes(std::string_view xmlns)
  {
    return attribute_list {
        {"xmlns", xmlns},
    };
  }

public:
  static constexpr const auto default_xmlns = "http://www.w3.org/2005/Atom";

  explicit feed(std::string_view xmlns, const is_element auto&... children)
      : element_builder(attributes(xmlns), children...)
  {
  }

  explicit feed(std::string_view xmlns, std::span<const element> children)
      : element_builder(attributes(xmlns), children)
  {
  }

  explicit feed(const is_element auto&... children)
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
using author        = element_builder<"author", element::Type::Boolean>;
using category      = element_builder<"category", element::Type::Boolean>;
using content       = element_builder<"content", element::Type::Boolean>;
using contributor   = element_builder<"contributor", element::Type::Boolean>;
using div           = element_builder<"div", element::Type::Boolean>;
using email         = element_builder<"email", element::Type::Boolean>;
using entry         = element_builder<"entry", element::Type::Boolean>;
using generator     = element_builder<"generator", element::Type::Boolean>;
using icon          = element_builder<"icon", element::Type::Boolean>;
using id            = element_builder<"id", element::Type::Boolean>;
using intervalBlock = element_builder<"intervalBlock", element::Type::Boolean>;
using link          = element_builder<"link", element::Type::Boolean>;
using logo          = element_builder<"logo", element::Type::Boolean>;
using meterReading  = element_builder<"meterReading", element::Type::Boolean>;
using name          = element_builder<"name", element::Type::Boolean>;
using published     = element_builder<"published", element::Type::Boolean>;
using readingType   = element_builder<"readingType", element::Type::Boolean>;
using rights        = element_builder<"rights", element::Type::Boolean>;
using source        = element_builder<"source", element::Type::Boolean>;
using subtitle      = element_builder<"subtitle", element::Type::Boolean>;
using summary       = element_builder<"summary", element::Type::Boolean>;
using text          = element_builder<"", element::Type::Boolean>;
using title         = element_builder<"title", element::Type::Boolean>;
using updated       = element_builder<"updated", element::Type::Boolean>;
using uri           = element_builder<"uri", element::Type::Boolean>;
using usagePoint    = element_builder<"usagePoint", element::Type::Boolean>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::atom
