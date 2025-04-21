#pragma once

#include <array>
#include <cstdint>

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate {

template<std::size_t N>
struct string_literal
{
  // NOLINTNEXTLINE
  constexpr string_literal(const char (&str)[N])
      : m_value(std::to_array(str))
  {
  }

  constexpr std::size_t size() const { return N; }
  constexpr const char* data() const { return m_value.data(); }

  std::array<char, N> m_value;
};

template<string_literal Name>
struct tag
{
  static char const* get_name() { return Name.data(); }
};

using comment = elementBuilder<tag<"comment">, element::Type::Comment>;

class xml : public elementBuilder<tag<"xml">, element::Type::Xml>
{
public:
  static constexpr const auto default_version  = "1.0";
  static constexpr const auto default_encoding = "UTF-8";

  explicit xml(std::string version  = default_version,
               std::string encoding = default_encoding)
      : elementBuilder({{"version", std::move(version)},
                        {"encoding", std::move(encoding)}})
  {
  }
};

using transparent =
    elementBuilder<tag<"transparent">, element::Type::Transparent>;

template<typename P, typename T>
concept procedure = requires { requires(std::invocable<P, const T&>); };

template<std::ranges::forward_range R>
transparent transform(const R& range,
                      procedure<std::ranges::range_value_t<R>> auto proc)
{
  std::vector<element> res;

  res.reserve(std::size(range));
  for (const auto& elem : range)
  {
    res.emplace_back(proc(elem));
  }

  return transparent {res};
}

namespace html {

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::transparent;
using hemplate::xml;

// clang-format off
using abbr       = elementBuilder<tag<"abbr">, element::Type::Boolean>;
using address    = elementBuilder<tag<"address">, element::Type::Boolean>;
using a          = elementBuilder<tag<"a">, element::Type::Boolean>;
using area       = elementBuilder<tag<"area">, element::Type::Atomic>;
using article    = elementBuilder<tag<"article">, element::Type::Boolean>;
using aside      = elementBuilder<tag<"aside">, element::Type::Boolean>;
using audio      = elementBuilder<tag<"audio">, element::Type::Boolean>;
using base       = elementBuilder<tag<"base">, element::Type::Atomic>;
using bdi        = elementBuilder<tag<"bdi">, element::Type::Boolean>;
using bdo        = elementBuilder<tag<"bdo">, element::Type::Boolean>;
using b          = elementBuilder<tag<"b">, element::Type::Boolean>;
using blockquote = elementBuilder<tag<"blockquote">, element::Type::Boolean>;
using body       = elementBuilder<tag<"body">, element::Type::Boolean>;
using br         = elementBuilder<tag<"br">, element::Type::Atomic>;
using button     = elementBuilder<tag<"button">, element::Type::Boolean>;
using canvas     = elementBuilder<tag<"canvas">, element::Type::Boolean>;
using caption    = elementBuilder<tag<"caption">, element::Type::Boolean>;
using cite       = elementBuilder<tag<"cite">, element::Type::Boolean>;
using code       = elementBuilder<tag<"code">, element::Type::Boolean>;
using col        = elementBuilder<tag<"col">, element::Type::Atomic>;
using colgroup   = elementBuilder<tag<"colgroup">, element::Type::Boolean>;
using data       = elementBuilder<tag<"data">, element::Type::Boolean>;
using datalist   = elementBuilder<tag<"datalist">, element::Type::Boolean>;
using dd         = elementBuilder<tag<"dd">, element::Type::Boolean>;
using del        = elementBuilder<tag<"del">, element::Type::Boolean>;
using details    = elementBuilder<tag<"details">, element::Type::Boolean>;
using dfn        = elementBuilder<tag<"dfn">, element::Type::Boolean>;
using dialog     = elementBuilder<tag<"dialog">, element::Type::Boolean>;
using div        = elementBuilder<tag<"div">, element::Type::Boolean>;
using dl         = elementBuilder<tag<"dl">, element::Type::Boolean>;
using doctype    = elementBuilder<tag<"!DOCTYPE html">, element::Type::Atomic>;
using dt         = elementBuilder<tag<"dt">, element::Type::Boolean>;
using embed      = elementBuilder<tag<"embed">, element::Type::Atomic>;
using em         = elementBuilder<tag<"em">, element::Type::Boolean>;
using fieldset   = elementBuilder<tag<"fieldset">, element::Type::Boolean>;
using figcaption = elementBuilder<tag<"figcaption">, element::Type::Boolean>;
using figure     = elementBuilder<tag<"figure">, element::Type::Boolean>;
using footer     = elementBuilder<tag<"footer">, element::Type::Boolean>;
using form       = elementBuilder<tag<"form">, element::Type::Boolean>;
using h1         = elementBuilder<tag<"h1">, element::Type::Boolean>;
using h2         = elementBuilder<tag<"h2">, element::Type::Boolean>;
using h3         = elementBuilder<tag<"h3">, element::Type::Boolean>;
using h4         = elementBuilder<tag<"h4">, element::Type::Boolean>;
using h5         = elementBuilder<tag<"h5">, element::Type::Boolean>;
using h6         = elementBuilder<tag<"h6">, element::Type::Boolean>;
using head       = elementBuilder<tag<"head">, element::Type::Boolean>;
using header     = elementBuilder<tag<"header">, element::Type::Boolean>;
using hgroup     = elementBuilder<tag<"hgroup">, element::Type::Boolean>;
using hr         = elementBuilder<tag<"hr">, element::Type::Atomic>;
using html       = elementBuilder<tag<"html">, element::Type::Boolean>;
using i          = elementBuilder<tag<"i">, element::Type::Boolean>;
using iframe     = elementBuilder<tag<"iframe">, element::Type::Boolean>;
using img        = elementBuilder<tag<"img">, element::Type::Atomic>;
using input      = elementBuilder<tag<"input">, element::Type::Atomic>;
using ins        = elementBuilder<tag<"ins">, element::Type::Boolean>;
using kbd        = elementBuilder<tag<"kbd">, element::Type::Boolean>;
using label      = elementBuilder<tag<"label">, element::Type::Boolean>;
using legend     = elementBuilder<tag<"legend">, element::Type::Boolean>;
using li         = elementBuilder<tag<"li">, element::Type::Boolean>;
using link       = elementBuilder<tag<"link">, element::Type::Atomic>;
using main       = elementBuilder<tag<"main">, element::Type::Boolean>;
using map        = elementBuilder<tag<"map">, element::Type::Boolean>;
using mark       = elementBuilder<tag<"mark">, element::Type::Boolean>;
using menu       = elementBuilder<tag<"menu">, element::Type::Boolean>;
using meta       = elementBuilder<tag<"meta">, element::Type::Atomic>;
using meter      = elementBuilder<tag<"meter">, element::Type::Boolean>;
using nav        = elementBuilder<tag<"nav">, element::Type::Boolean>;
using noscript   = elementBuilder<tag<"noscript">, element::Type::Boolean>;
using object     = elementBuilder<tag<"object">, element::Type::Boolean>;
using ol         = elementBuilder<tag<"ol">, element::Type::Boolean>;
using optgroup   = elementBuilder<tag<"optgroup">, element::Type::Boolean>;
using option     = elementBuilder<tag<"option">, element::Type::Boolean>;
using output     = elementBuilder<tag<"output">, element::Type::Boolean>;
using p          = elementBuilder<tag<"p">, element::Type::Boolean>;
using param      = elementBuilder<tag<"param">, element::Type::Atomic>;
using picture    = elementBuilder<tag<"picture">, element::Type::Boolean>;
using pre        = elementBuilder<tag<"pre">, element::Type::Boolean>;
using progress   = elementBuilder<tag<"progress">, element::Type::Boolean>;
using q          = elementBuilder<tag<"q">, element::Type::Boolean>;
using rp         = elementBuilder<tag<"rp">, element::Type::Boolean>;
using rt         = elementBuilder<tag<"rt">, element::Type::Boolean>;
using ruby       = elementBuilder<tag<"ruby">, element::Type::Boolean>;
using s          = elementBuilder<tag<"s">, element::Type::Boolean>;
using samp       = elementBuilder<tag<"samp">, element::Type::Boolean>;
using script     = elementBuilder<tag<"script">, element::Type::Boolean>;
using search     = elementBuilder<tag<"search">, element::Type::Boolean>;
using section    = elementBuilder<tag<"section">, element::Type::Boolean>;
using select     = elementBuilder<tag<"select">, element::Type::Boolean>;
using small      = elementBuilder<tag<"small">, element::Type::Boolean>;
using source     = elementBuilder<tag<"source">, element::Type::Atomic>;
using span       = elementBuilder<tag<"span">, element::Type::Boolean>;
using strong     = elementBuilder<tag<"strong">, element::Type::Boolean>;
using style      = elementBuilder<tag<"style">, element::Type::Boolean>;
using sub        = elementBuilder<tag<"sub">, element::Type::Boolean>;
using summary    = elementBuilder<tag<"summary">, element::Type::Boolean>;
using sup        = elementBuilder<tag<"sup">, element::Type::Boolean>;
using svg        = elementBuilder<tag<"svg">, element::Type::Boolean>;
using table      = elementBuilder<tag<"table">, element::Type::Boolean>;
using tbody      = elementBuilder<tag<"tbody">, element::Type::Boolean>;
using td         = elementBuilder<tag<"td">, element::Type::Boolean>;
using textarea   = elementBuilder<tag<"textarea">, element::Type::Boolean>;
using text       = elementBuilder<tag<"">, element::Type::Boolean>;
using tfoot      = elementBuilder<tag<"tfoot">, element::Type::Boolean>;
using th         = elementBuilder<tag<"th">, element::Type::Boolean>;
using thead      = elementBuilder<tag<"thead">, element::Type::Boolean>;
using time       = elementBuilder<tag<"time">, element::Type::Boolean>;
using title      = elementBuilder<tag<"title">, element::Type::Boolean>;
using tr         = elementBuilder<tag<"tr">, element::Type::Boolean>;
using track      = elementBuilder<tag<"track">, element::Type::Atomic>;
using u          = elementBuilder<tag<"u">, element::Type::Boolean>;
using ul         = elementBuilder<tag<"ul">, element::Type::Boolean>;
using var        = elementBuilder<tag<"var">, element::Type::Boolean>;
using video      = elementBuilder<tag<"video">, element::Type::Boolean>;
using wbr        = elementBuilder<tag<"wbr">, element::Type::Atomic>;
// clang-format on

}  // namespace html

namespace rss {

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

}  // namespace rss

namespace atom {

std::string format_time(std::int64_t sec);
std::string format_time_now();

class feed : public elementBuilder<tag<"feed">, element::Type::Boolean>
{
public:
  static constexpr const auto default_xmlns = "http://www.w3.org/2005/Atom";

  explicit feed(std::string xmlns,
                const std::derived_from<element> auto&... children)
      : elementBuilder({{"xmlns", std::move(xmlns)}}, children...)
  {
  }

  explicit feed(std::string xmlns, std::span<const element> children)
      : elementBuilder({{"xmlns", std::move(xmlns)}}, children)
  {
  }

  explicit feed(const std::derived_from<element> auto&... children)
      : feed(default_xmlns, children...)
  {
  }

  explicit feed(std::span<const element> children)
      : feed(default_xmlns, children)
  {
  }
};

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::transparent;
using hemplate::xml;

// clang-format off
using author        = elementBuilder<tag<"author">, element::Type::Boolean>;
using category      = elementBuilder<tag<"category">, element::Type::Boolean>;
using content       = elementBuilder<tag<"content">, element::Type::Boolean>;
using contributor   = elementBuilder<tag<"contributor">, element::Type::Boolean>;
using div           = elementBuilder<tag<"div">, element::Type::Boolean>;
using email         = elementBuilder<tag<"email">, element::Type::Boolean>;
using entry         = elementBuilder<tag<"entry">, element::Type::Boolean>;
using generator     = elementBuilder<tag<"generator">, element::Type::Boolean>;
using icon          = elementBuilder<tag<"icon">, element::Type::Boolean>;
using id            = elementBuilder<tag<"id">, element::Type::Boolean>;
using intervalBlock = elementBuilder<tag<"intervalBlock">, element::Type::Boolean>;
using link          = elementBuilder<tag<"link">, element::Type::Boolean>;
using logo          = elementBuilder<tag<"logo">, element::Type::Boolean>;
using meterReading  = elementBuilder<tag<"meterReading">, element::Type::Boolean>;
using name          = elementBuilder<tag<"name">, element::Type::Boolean>;
using published     = elementBuilder<tag<"published">, element::Type::Boolean>;
using readingType   = elementBuilder<tag<"readingType">, element::Type::Boolean>;
using rights        = elementBuilder<tag<"rights">, element::Type::Boolean>;
using source        = elementBuilder<tag<"source">, element::Type::Boolean>;
using subtitle      = elementBuilder<tag<"subtitle">, element::Type::Boolean>;
using summary       = elementBuilder<tag<"summary">, element::Type::Boolean>;
using text          = elementBuilder<tag<"">, element::Type::Boolean>;
using title         = elementBuilder<tag<"title">, element::Type::Boolean>;
using updated       = elementBuilder<tag<"updated">, element::Type::Boolean>;
using uri           = elementBuilder<tag<"uri">, element::Type::Boolean>;
using usagePoint    = elementBuilder<tag<"usagePoint">, element::Type::Boolean>;
// clang-format on

}  // namespace atom

namespace sitemap {

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

}  // namespace sitemap

}  // namespace hemplate
