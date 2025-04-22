#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::rss {

std::string format_time(std::int64_t sec);
std::string format_time_now();

class rss : public elementBuilder<tag<"rss">, element::Type::Boolean>
{
public:
  static constexpr const auto default_version = "2.0";
  static constexpr const auto default_xmlns   = "http://www.w3.org/2005/Atom";

  explicit rss(std::string version,
               std::string xmlns,
               const std::derived_from<element> auto&... children)
      : elementBuilder({{"version", std::move(version)},
                        {"xmlns:atom", std::move(xmlns)}},
                       children...)
  {
  }

  explicit rss(std::string version,
               std::string xmlns,
               std::span<const element> children)
      : elementBuilder({{"version", std::move(version)},
                        {"xmlns:atom", std::move(xmlns)}},
                       children)
  {
  }

  explicit rss(const std::derived_from<element> auto&... children)
      : rss(default_version, default_xmlns, children...)
  {
  }

  explicit rss(std::span<const element> children)
      : rss(default_version, default_xmlns, children)
  {
  }
};

class atomLink
    : public elementBuilder<tag<"atom:link">, element::Type::Boolean>
{
public:
  static constexpr const auto default_rel  = "self";
  static constexpr const auto default_type = "application/rss+xml";

  explicit atomLink(std::string rel,
                    std::string type,
                    const attributeList& attributes,
                    const std::derived_from<element> auto&... children)
      : elementBuilder(attributes.add({{"rel", std::move(rel)},
                                       {"type", std::move(type)}}),
                       children...)
  {
  }

  explicit atomLink(std::string rel,
                    std::string type,
                    const attributeList& attributes,
                    std::span<const element> children)
      : elementBuilder(attributes.add({{"rel", std::move(rel)},
                                       {"type", std::move(type)}}),
                       children)
  {
  }

  explicit atomLink(const std::derived_from<element> auto&... children)
      : atomLink(default_rel, default_type, {}, children...)
  {
  }

  explicit atomLink(std::span<const element> children)
      : atomLink(default_rel, default_type, {}, children)
  {
  }

  explicit atomLink(const attributeList& attributes,
                    const std::derived_from<element> auto&... children)
      : atomLink(default_rel, default_type, attributes, children...)
  {
  }

  explicit atomLink(const attributeList& attributes,
                    std::span<const element> children)
      : atomLink(default_rel, default_type, attributes, children)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::transparent;
using hemplate::xml;

// clang-format off
using author         = elementBuilder<tag<"author">, element::Type::Boolean>;
using category       = elementBuilder<tag<"category">, element::Type::Boolean>;
using channel        = elementBuilder<tag<"channel">, element::Type::Boolean>;
using cloud          = elementBuilder<tag<"cloud">, element::Type::Atomic>;
using comments       = elementBuilder<tag<"comments">, element::Type::Boolean>;
using copyright      = elementBuilder<tag<"copyright">, element::Type::Boolean>;
using description    = elementBuilder<tag<"description">, element::Type::Boolean>;
using docs           = elementBuilder<tag<"docs">, element::Type::Boolean>;
using enclosure      = elementBuilder<tag<"enclosure">, element::Type::Atomic>;
using generator      = elementBuilder<tag<"generator">, element::Type::Boolean>;
using guid           = elementBuilder<tag<"guid">, element::Type::Boolean>;
using height         = elementBuilder<tag<"height">, element::Type::Boolean>;
using image          = elementBuilder<tag<"image">, element::Type::Boolean>;
using item           = elementBuilder<tag<"item">, element::Type::Boolean>;
using language       = elementBuilder<tag<"language">, element::Type::Boolean>;
using lastBuildDate  = elementBuilder<tag<"lastBuildDate">, element::Type::Boolean>;
using link           = elementBuilder<tag<"link">, element::Type::Boolean>;
using managingEditor = elementBuilder<tag<"managingEditor">, element::Type::Boolean>;
using name           = elementBuilder<tag<"name">, element::Type::Boolean>;
using pubDate        = elementBuilder<tag<"pubDate">, element::Type::Boolean>;
using rating         = elementBuilder<tag<"rating">, element::Type::Boolean>;
using skipDays       = elementBuilder<tag<"skipDays">, element::Type::Boolean>;
using skipHours      = elementBuilder<tag<"skipHours">, element::Type::Boolean>;
using source         = elementBuilder<tag<"source">, element::Type::Boolean>;
using text           = elementBuilder<tag<"">, element::Type::Boolean>;
using textinput      = elementBuilder<tag<"textinput">, element::Type::Boolean>;
using title          = elementBuilder<tag<"title">, element::Type::Boolean>;
using ttl            = elementBuilder<tag<"ttl">, element::Type::Boolean>;
using url            = elementBuilder<tag<"url">, element::Type::Boolean>;
using webMaster      = elementBuilder<tag<"webMaster">, element::Type::Boolean>;
using width          = elementBuilder<tag<"width">, element::Type::Boolean>;
// clang-format on

}  // namespace hemplate::rss
