#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::sitemap
{

class HEMPLATE_EXPORT urlset
    : public element_builder<"urlset", element::Type::Boolean>
{
  static auto attributes(std::string_view xmlns)
  {
    return attribute_list {
        {"xmlns", xmlns},
    };
  }

public:
  static constexpr const auto default_xmlns =
      "http://www.sitemaps.org/schemas/sitemap/0.9";

  explicit urlset(std::string_view xmlns, const is_element auto&... children)
      : element_builder(attributes(xmlns), children...)
  {
  }

  explicit urlset(const is_element auto&... children)
      : urlset(default_xmlns, children...)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN *-identifier-naming
using changefreq = element_builder<"changefreq", element::Type::Boolean>;
using lastmod    = element_builder<"lastmod", element::Type::Boolean>;
using loc        = element_builder<"loc", element::Type::Boolean>;
using url        = element_builder<"url", element::Type::Boolean>;
using priority   = element_builder<"priority", element::Type::Boolean>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::sitemap
