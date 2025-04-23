#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::rss
{

std::string format_time(std::int64_t sec);
std::string format_time_now();

class HEMPLATE_EXPORT rss
    : public element_builder<"rss", element::Type::Boolean>
{
  static auto attributes(std::string_view version, std::string_view xmlns)
  {
    return attribute_list {
        {"version", version},
        {"xmlns", xmlns},
    };
  }

public:
  static constexpr const auto default_version = "2.0";
  static constexpr const auto default_xmlns = "http://www.w3.org/2005/Atom";

  explicit rss(std::string_view version,
               std::string_view xmlns,
               const is_element auto&... children)
      : element_builder(attributes(version, xmlns), children...)
  {
  }

  explicit rss(std::string_view version,
               std::string_view xmlns,
               std::span<const element> children)
      : element_builder(attributes(version, xmlns), children)
  {
  }

  explicit rss(const is_element auto&... children)
      : rss(default_version, default_xmlns, children...)
  {
  }

  explicit rss(std::span<const element> children)
      : rss(default_version, default_xmlns, children)
  {
  }
};

class HEMPLATE_EXPORT atomLink  // NOLINT *-identifier-naming
    : public element_builder<"atom:link", element::Type::Boolean>
{
  static auto attributes(attribute_list& list,
                         std::string_view rel,
                         std::string_view type)
  {
    return list.set({
        {"rel", rel},
        {"type", type},
    });
  }

public:
  static constexpr const auto default_rel = "self";
  static constexpr const auto default_type = "application/rss+xml";

  explicit atomLink(std::string_view rel,
                    std::string_view type,
                    attribute_list attrs,
                    const is_element auto&... children)
      : element_builder(attributes(attrs, rel, type), children...)
  {
  }

  explicit atomLink(std::string_view rel,
                    std::string_view type,
                    attribute_list attrs,
                    std::span<const element> children)
      : element_builder(attributes(attrs, rel, type), children)
  {
  }

  explicit atomLink(attribute_list attrs, const is_element auto&... children)
      : atomLink(default_rel, default_type, std::move(attrs), children...)
  {
  }

  explicit atomLink(attribute_list attrs, std::span<const element> children)
      : atomLink(default_rel, default_type, std::move(attrs), children)
  {
  }

  explicit atomLink(const is_element auto&... children)
      : atomLink({}, children...)
  {
  }

  explicit atomLink(std::span<const element> children)
      : atomLink({}, children)
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
using author         = element_builder<"author", element::Type::Boolean>;
using category       = element_builder<"category", element::Type::Boolean>;
using channel        = element_builder<"channel", element::Type::Boolean>;
using cloud          = element_builder<"cloud", element::Type::Atomic>;
using comments       = element_builder<"comments", element::Type::Boolean>;
using copyright      = element_builder<"copyright", element::Type::Boolean>;
using description    = element_builder<"description", element::Type::Boolean>;
using docs           = element_builder<"docs", element::Type::Boolean>;
using enclosure      = element_builder<"enclosure", element::Type::Atomic>;
using generator      = element_builder<"generator", element::Type::Boolean>;
using guid           = element_builder<"guid", element::Type::Boolean>;
using height         = element_builder<"height", element::Type::Boolean>;
using image          = element_builder<"image", element::Type::Boolean>;
using item           = element_builder<"item", element::Type::Boolean>;
using language       = element_builder<"language", element::Type::Boolean>;
using lastBuildDate  = element_builder<"lastBuildDate", element::Type::Boolean>;
using link           = element_builder<"link", element::Type::Boolean>;
using managingEditor = element_builder<"managingEditor", element::Type::Boolean>;
using name           = element_builder<"name", element::Type::Boolean>;
using pubDate        = element_builder<"pubDate", element::Type::Boolean>;
using rating         = element_builder<"rating", element::Type::Boolean>;
using skipDays       = element_builder<"skipDays", element::Type::Boolean>;
using skipHours      = element_builder<"skipHours", element::Type::Boolean>;
using source         = element_builder<"source", element::Type::Boolean>;
using text           = element_builder<"", element::Type::Boolean>;
using textinput      = element_builder<"textinput", element::Type::Boolean>;
using title          = element_builder<"title", element::Type::Boolean>;
using ttl            = element_builder<"ttl", element::Type::Boolean>;
using url            = element_builder<"url", element::Type::Boolean>;
using webMaster      = element_builder<"webMaster", element::Type::Boolean>;
using width          = element_builder<"width", element::Type::Boolean>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::rss
