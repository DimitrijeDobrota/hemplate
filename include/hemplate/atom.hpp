#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::atom
{

std::string format_time(std::int64_t sec);
std::string format_time_now();

class HEMPLATE_EXPORT feed : public element_boolean<"feed">
{
  static auto def_attrs()
  {
    return attribute_list {
        {"xmlns", "http://www.w3.org/2005/Atom"},
    };
  }

public:
  template<typename... Args>
    requires(!std::same_as<attribute_list, std::remove_cvref_t<Args>> && ...)
  explicit feed(Args&&... args)
      : element_boolean(def_attrs(), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
  explicit feed(const attribute_list& attrs, Args&&... args)
      : element_boolean(attrs, std::forward<Args>(args)...)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN(*naming*)
using author        = element_boolean<"author">;
using category      = element_boolean<"category">;
using content       = element_boolean<"content">;
using contributor   = element_boolean<"contributor">;
using div           = element_boolean<"div">;
using email         = element_boolean<"email">;
using entry         = element_boolean<"entry">;
using generator     = element_boolean<"generator">;
using icon          = element_boolean<"icon">;
using id            = element_boolean<"id">;
using intervalBlock = element_boolean<"intervalBlock">;
using link          = element_boolean<"link">;
using logo          = element_boolean<"logo">;
using meterReading  = element_boolean<"meterReading">;
using name          = element_boolean<"name">;
using published     = element_boolean<"published">;
using readingType   = element_boolean<"readingType">;
using rights        = element_boolean<"rights">;
using source        = element_boolean<"source">;
using subtitle      = element_boolean<"subtitle">;
using summary       = element_boolean<"summary">;
using title         = element_boolean<"title">;
using updated       = element_boolean<"updated">;
using uri           = element_boolean<"uri">;
using usagePoint    = element_boolean<"usagePoint">;
// NOLINTEND(*naming*)
// clang-format on

}  // namespace hemplate::atom
