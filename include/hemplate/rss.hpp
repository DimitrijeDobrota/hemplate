#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::rss
{

std::string format_time(std::int64_t sec);
std::string format_time_now();

class rss : public element_builder<tag<"rss">, element::Type::Boolean>
{
public:
  static constexpr const auto default_version = "2.0";
  static constexpr const auto default_xmlns = "http://www.w3.org/2005/Atom";

  explicit rss(std::string version,
               std::string xmlns,
               const std::derived_from<element> auto&... children)
      : element_builder(
            {{"version", std::move(version)}, {"xmlns:atom", std::move(xmlns)}},
            children...)
  {
  }

  explicit rss(std::string version,
               std::string xmlns,
               std::span<const element> children)
      : element_builder(
            {{"version", std::move(version)}, {"xmlns:atom", std::move(xmlns)}},
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

class atomLink  // NOLINT *-identifier-naming
    : public element_builder<tag<"atom:link">, element::Type::Boolean>
{
public:
  static constexpr const auto default_rel = "self";
  static constexpr const auto default_type = "application/rss+xml";

  explicit atomLink(std::string rel,
                    std::string type,
                    const attribute_list& attributes,
                    const std::derived_from<element> auto&... children)
      : element_builder(attributes.add({{"rel", std::move(rel)},
                                        {"type", std::move(type)}}),
                        children...)
  {
  }

  explicit atomLink(std::string rel,
                    std::string type,
                    const attribute_list& attributes,
                    std::span<const element> children)
      : element_builder(attributes.add({{"rel", std::move(rel)},
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

  explicit atomLink(const attribute_list& attributes,
                    const std::derived_from<element> auto&... children)
      : atomLink(default_rel, default_type, attributes, children...)
  {
  }

  explicit atomLink(const attribute_list& attributes,
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
// NOLINTBEGIN *-identifier-naming
using author         = element_builder<tag<"author">, element::Type::Boolean>;
using category       = element_builder<tag<"category">, element::Type::Boolean>;
using channel        = element_builder<tag<"channel">, element::Type::Boolean>;
using cloud          = element_builder<tag<"cloud">, element::Type::Atomic>;
using comments       = element_builder<tag<"comments">, element::Type::Boolean>;
using copyright      = element_builder<tag<"copyright">, element::Type::Boolean>;
using description    = element_builder<tag<"description">, element::Type::Boolean>;
using docs           = element_builder<tag<"docs">, element::Type::Boolean>;
using enclosure      = element_builder<tag<"enclosure">, element::Type::Atomic>;
using generator      = element_builder<tag<"generator">, element::Type::Boolean>;
using guid           = element_builder<tag<"guid">, element::Type::Boolean>;
using height         = element_builder<tag<"height">, element::Type::Boolean>;
using image          = element_builder<tag<"image">, element::Type::Boolean>;
using item           = element_builder<tag<"item">, element::Type::Boolean>;
using language       = element_builder<tag<"language">, element::Type::Boolean>;
using lastBuildDate  = element_builder<tag<"lastBuildDate">, element::Type::Boolean>;
using link           = element_builder<tag<"link">, element::Type::Boolean>;
using managingEditor = element_builder<tag<"managingEditor">, element::Type::Boolean>;
using name           = element_builder<tag<"name">, element::Type::Boolean>;
using pubDate        = element_builder<tag<"pubDate">, element::Type::Boolean>;
using rating         = element_builder<tag<"rating">, element::Type::Boolean>;
using skipDays       = element_builder<tag<"skipDays">, element::Type::Boolean>;
using skipHours      = element_builder<tag<"skipHours">, element::Type::Boolean>;
using source         = element_builder<tag<"source">, element::Type::Boolean>;
using text           = element_builder<tag<"">, element::Type::Boolean>;
using textinput      = element_builder<tag<"textinput">, element::Type::Boolean>;
using title          = element_builder<tag<"title">, element::Type::Boolean>;
using ttl            = element_builder<tag<"ttl">, element::Type::Boolean>;
using url            = element_builder<tag<"url">, element::Type::Boolean>;
using webMaster      = element_builder<tag<"webMaster">, element::Type::Boolean>;
using width          = element_builder<tag<"width">, element::Type::Boolean>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::rss
