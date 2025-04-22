#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::sitemap {

class urlset : public elementBuilder<tag<"urlset">, element::Type::Boolean>
{
public:
  static constexpr const auto default_xmlns =
      "http://www.sitemaps.org/schemas/sitemap/0.9";

  explicit urlset(std::string xmlns,
                  const std::derived_from<element> auto&... children)
      : elementBuilder({{"xmlns", std::move(xmlns)}}, children...)
  {
  }

  explicit urlset(std::string xmlns, std::span<const element> children)
      : elementBuilder({{"xmlns", std::move(xmlns)}}, children)
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
using changefreq = elementBuilder<tag<"changefreq">, element::Type::Boolean>;
using lastmod    = elementBuilder<tag<"lastmod">, element::Type::Boolean>;
using loc        = elementBuilder<tag<"loc">, element::Type::Boolean>;
using url        = elementBuilder<tag<"url">, element::Type::Boolean>;
using priority   = elementBuilder<tag<"priority">, element::Type::Boolean>;
// clang-format on

}  // namespace hemplate::sitemap
