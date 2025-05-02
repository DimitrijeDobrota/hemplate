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
  static constexpr const auto def_version = "2.0";
  static constexpr const auto def_xmlns = "http://www.w3.org/2005/Atom";

  template<typename... Args>
  explicit rss(std::string_view version, std::string_view xmlns, Args&&... args)
      : element_boolean(attributes(version, xmlns), std::forward<Args>(args)...)
  {
  }

  template<typename... Args>
  explicit rss(Args&&... args)
      : element_boolean(
            attributes(def_version, def_xmlns), std::forward<Args>(args)...
        )
  {
  }
};

class HEMPLATE_EXPORT atomLink  // NOLINT(*naming*)
    : public element_boolean<"atom:link">
{
  static auto attributes(
      const attribute_list& list, std::string_view rel, std::string_view type
  )
  {
    return attribute_list {list, {{"rel", rel}, {"type", type}}};
  }

public:
  static constexpr const auto def_rel = "self";
  static constexpr const auto def_type = "application/rss+xml";

  template<typename... Args>
  explicit atomLink(
      std::string_view rel,
      std::string_view type,
      const attribute_list& attrs,
      Args&&... args
  )
      : element_boolean(
            attributes(attrs, rel, type), std::forward<Args>(args)...
        )
  {
  }

  template<typename... Args>
  explicit atomLink(std::string_view rel, std::string_view type, Args&&... args)
      : element_boolean(
            attributes({}, rel, type), {}, std::forward<Args>(args)...
        )
  {
  }

  template<typename... Args>
  explicit atomLink(const attribute_list& attrs, Args&&... args)
      : element_boolean(
            attributes(attrs, def_rel, def_type), std::forward<Args>(args)...
        )
  {
  }

  template<typename... Args>
  explicit atomLink(Args&&... args)
      : element_boolean(std::forward<Args>(args)...)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN(*naming*)
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
// NOLINTEND(*naming*)
// clang-format on

}  // namespace hemplate::rss
