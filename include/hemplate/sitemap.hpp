#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::sitemap
{

class HEMPLATE_EXPORT urlset : public element_boolean<"urlset">
{
  static auto def_attrs()
  {
    return attribute_list {
        {"xmlns", "http://www.sitemaps.org/schemas/sitemap/0.9"},
    };
  }

public:
  template<typename... Args>
  explicit urlset(Args&&... args)
    requires(!std::same_as<attribute_list, std::remove_cvref_t<Args>> && ...)
      : element_boolean(def_attrs(), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
  explicit urlset(const attribute_list& attrs, Args&&... args)
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
using changefreq = element_boolean<"changefreq">;
using lastmod    = element_boolean<"lastmod">;
using loc        = element_boolean<"loc">;
using url        = element_boolean<"url">;
using priority   = element_boolean<"priority">;
// NOLINTEND(*naming*)
// clang-format on

}  // namespace hemplate::sitemap
