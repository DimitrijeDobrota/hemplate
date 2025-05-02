#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::sitemap
{

class HEMPLATE_EXPORT urlset : public element_boolean<"urlset">
{
  static auto attributes(std::string_view xmlns)
  {
    return attribute_list {
        {"xmlns", xmlns},
    };
  }

public:
  static constexpr const auto def_xmlns =
      "http://www.sitemaps.org/schemas/sitemap/0.9";

  template<typename... Args>
  explicit urlset(std::string_view xmlns, Args&&... args)
      : element_boolean(attributes(xmlns), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
  explicit urlset(Args&&... args)
      : element_boolean(attributes(def_xmlns), std::forward<Args>(args)...)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN(*naming*)
using changefreq = element_boolean<"changefreq">;
using lastmod    = element_boolean<"lastmod">;
using loc        = element_boolean<"loc">;
using url        = element_boolean<"url">;
using priority   = element_boolean<"priority">;
// NOLINTEND(*naming*)
// clang-format on

}  // namespace hemplate::sitemap
