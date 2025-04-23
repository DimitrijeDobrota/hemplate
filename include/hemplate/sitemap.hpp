#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::sitemap
{

class urlset : public element_builder<tag<"urlset">, element::Type::Boolean>
{
public:
  static constexpr const auto default_xmlns =
      "http://www.sitemaps.org/schemas/sitemap/0.9";

  explicit urlset(std::string xmlns,
                  const std::derived_from<element> auto&... children)
      : element_builder({{"xmlns", std::move(xmlns)}}, children...)
  {
  }

  explicit urlset(std::string xmlns, std::span<const element> children)
      : element_builder({{"xmlns", std::move(xmlns)}}, children)
  {
  }

  explicit urlset(const std::derived_from<element> auto&... children)
      : urlset(default_xmlns, children...)
  {
  }

  explicit urlset(std::span<const element> children)
      : urlset(default_xmlns, children)
  {
  }
};

// clang-format off
// NOLINTBEGIN *-identifier-naming
using changefreq = element_builder<tag<"changefreq">, element::Type::Boolean>;
using lastmod    = element_builder<tag<"lastmod">, element::Type::Boolean>;
using loc        = element_builder<tag<"loc">, element::Type::Boolean>;
using url        = element_builder<tag<"url">, element::Type::Boolean>;
using priority   = element_builder<tag<"priority">, element::Type::Boolean>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::sitemap
