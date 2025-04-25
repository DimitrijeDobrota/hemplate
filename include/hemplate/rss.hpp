#pragma once

#include "hemplate/classes.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate::rss
{

std::string format_time(std::int64_t sec);
std::string format_time_now();

class HEMPLATE_EXPORT rss : public element_boolean<"rss">
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

  explicit rss(
      std::string_view version,
      std::string_view xmlns,
      const is_element auto&... children
  )
      : element_builder(attributes(version, xmlns), children...)
  {
  }

  explicit rss(const is_element auto&... children)
      : rss(default_version, default_xmlns, children...)
  {
  }
};

class HEMPLATE_EXPORT atomLink  // NOLINT *-identifier-naming
    : public element_boolean<"atom:link">
{
  static auto attributes(
      attribute_list& list, std::string_view rel, std::string_view type
  )
  {
    list.set({
        {"rel", rel},
        {"type", type},
    });
    return list;
  }

public:
  static constexpr const auto default_rel = "self";
  static constexpr const auto default_type = "application/rss+xml";

  explicit atomLink(
      std::string_view rel,
      std::string_view type,
      attribute_list attrs,
      const is_element auto&... children
  )
      : element_builder(attributes(attrs, rel, type), children...)
  {
  }

  explicit atomLink(
      std::string_view rel,
      std::string_view type,
      const is_element auto&... children
  )
      : atomLink(rel, type, {}, children...)
  {
  }

  explicit atomLink(attribute_list attrs, const is_element auto&... children)
      : atomLink(default_rel, default_type, std::move(attrs), children...)
  {
  }

  explicit atomLink(const is_element auto&... children)
      : atomLink({}, children...)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN *-identifier-naming
using author         = element_boolean<"author">;
using category       = element_boolean<"category">;
using channel        = element_boolean<"channel">;
using comments       = element_boolean<"comments">;
using copyright      = element_boolean<"copyright">;
using description    = element_boolean<"description">;
using docs           = element_boolean<"docs">;
using generator      = element_boolean<"generator">;
using guid           = element_boolean<"guid">;
using height         = element_boolean<"height">;
using image          = element_boolean<"image">;
using item           = element_boolean<"item">;
using language       = element_boolean<"language">;
using lastBuildDate  = element_boolean<"lastBuildDate">;
using link           = element_boolean<"link">;
using managingEditor = element_boolean<"managingEditor">;
using name           = element_boolean<"name">;
using pubDate        = element_boolean<"pubDate">;
using rating         = element_boolean<"rating">;
using skipDays       = element_boolean<"skipDays">;
using skipHours      = element_boolean<"skipHours">;
using source         = element_boolean<"source">;
using textinput      = element_boolean<"textinput">;
using title          = element_boolean<"title">;
using ttl            = element_boolean<"ttl">;
using url            = element_boolean<"url">;
using webMaster      = element_boolean<"webMaster">;
using width          = element_boolean<"width">;

using cloud          = element_atomic<"cloud">;
using enclosure      = element_atomic<"enclosure">;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::rss
