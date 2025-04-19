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

/*
class comment : public elementBoolean<tag<"">>
{
public:
  comment() = default;
  explicit comment(std::string text)
      : elementBoolean(std::move(text))
  {
  }

  void render(std::ostream& out) const override
  {
    if (get_data().empty())
    {
      tgl_state();
      out << (get_state() ? "<!-- " : " -->");
    }
    else out << "<!-- " << get_data() << " -->";
  }
};

class xml : public elementAtomic<tag<"xml">>
{
public:
  explicit xml(std::string version = "1.0", std::string encoding = "UTF-8")
      : m_version(std::move(version))
      , m_encoding(std::move(encoding))
  {
  }

  void render(std::ostream& out) const override
  {
    out << R"(<?xml version=")" << m_version << '"';
    out << R"( encoding=")" << m_encoding << "\"?>";
  }

private:
  std::string m_version;
  std::string m_encoding;
};
*/

namespace html {

/*
class doctype : public elementAtomic<tag<"doctype">>
{
public:
  explicit doctype() = default;

  void render(std::ostream& out) const override { out << "<!DOCTYPE html>"; }
};
*/

using a          = elementBoolean<tag<"a">>;
using abbr       = elementBoolean<tag<"abbr">>;
using address    = elementBoolean<tag<"address">>;
using area       = elementAtomic<tag<"area">>;
using article    = elementBoolean<tag<"article">>;
using aside      = elementBoolean<tag<"aside">>;
using audio      = elementBoolean<tag<"audio">>;
using b          = elementBoolean<tag<"b">>;
using base       = elementAtomic<tag<"base">>;
using bdi        = elementBoolean<tag<"bdi">>;
using bdo        = elementBoolean<tag<"bdo">>;
using blockquote = elementBoolean<tag<"blockquote">>;
using body       = elementBoolean<tag<"body">>;
using br         = elementAtomic<tag<"br">>;
using button     = elementBoolean<tag<"button">>;
using canvas     = elementBoolean<tag<"canvas">>;
using caption    = elementBoolean<tag<"caption">>;
using cite       = elementBoolean<tag<"cite">>;
using code       = elementBoolean<tag<"code">>;
using col        = elementAtomic<tag<"col">>;
using colgroup   = elementBoolean<tag<"colgroup">>;
using data       = elementBoolean<tag<"data">>;
using datalist   = elementBoolean<tag<"datalist">>;
using dd         = elementBoolean<tag<"dd">>;
using del        = elementBoolean<tag<"del">>;
using details    = elementBoolean<tag<"details">>;
using dfn        = elementBoolean<tag<"dfn">>;
using dialog     = elementBoolean<tag<"dialog">>;
using div        = elementBoolean<tag<"div">>;
using dl         = elementBoolean<tag<"dl">>;
using dt         = elementBoolean<tag<"dt">>;
using em         = elementBoolean<tag<"em">>;
using embed      = elementAtomic<tag<"embed">>;
using fieldset   = elementBoolean<tag<"fieldset">>;
using figcaption = elementBoolean<tag<"figcaption">>;
using figure     = elementBoolean<tag<"figure">>;
using footer     = elementBoolean<tag<"footer">>;
using form       = elementBoolean<tag<"form">>;
using h1         = elementBoolean<tag<"h1">>;
using h2         = elementBoolean<tag<"h2">>;
using h3         = elementBoolean<tag<"h3">>;
using h4         = elementBoolean<tag<"h4">>;
using h5         = elementBoolean<tag<"h5">>;
using h6         = elementBoolean<tag<"h6">>;
using head       = elementBoolean<tag<"head">>;
using header     = elementBoolean<tag<"header">>;
using hgroup     = elementBoolean<tag<"hgroup">>;
using hr         = elementAtomic<tag<"hr">>;
using html       = elementBoolean<tag<"html">>;
using i          = elementBoolean<tag<"i">>;
using iframe     = elementBoolean<tag<"iframe">>;
using img        = elementAtomic<tag<"img">>;
using input      = elementAtomic<tag<"input">>;
using ins        = elementBoolean<tag<"ins">>;
using kbd        = elementBoolean<tag<"kbd">>;
using label      = elementBoolean<tag<"label">>;
using legend     = elementBoolean<tag<"legend">>;
using li         = elementBoolean<tag<"li">>;
using link       = elementAtomic<tag<"link">>;
using main       = elementBoolean<tag<"main">>;
using map        = elementBoolean<tag<"map">>;
using mark       = elementBoolean<tag<"mark">>;
using menu       = elementBoolean<tag<"menu">>;
using meta       = elementAtomic<tag<"meta">>;
using meter      = elementBoolean<tag<"meter">>;
using nav        = elementBoolean<tag<"nav">>;
using noscript   = elementBoolean<tag<"noscript">>;
using object     = elementBoolean<tag<"object">>;
using ol         = elementBoolean<tag<"ol">>;
using optgroup   = elementBoolean<tag<"optgroup">>;
using option     = elementBoolean<tag<"option">>;
using output     = elementBoolean<tag<"output">>;
using p          = elementBoolean<tag<"p">>;
using param      = elementAtomic<tag<"param">>;
using picture    = elementBoolean<tag<"picture">>;
using pre        = elementBoolean<tag<"pre">>;
using progress   = elementBoolean<tag<"progress">>;
using q          = elementBoolean<tag<"q">>;
using rp         = elementBoolean<tag<"rp">>;
using rt         = elementBoolean<tag<"rt">>;
using ruby       = elementBoolean<tag<"ruby">>;
using s          = elementBoolean<tag<"s">>;
using samp       = elementBoolean<tag<"samp">>;
using script     = elementBoolean<tag<"script">>;
using search     = elementBoolean<tag<"search">>;
using section    = elementBoolean<tag<"section">>;
using select     = elementBoolean<tag<"select">>;
using small      = elementBoolean<tag<"small">>;
using source     = elementAtomic<tag<"source">>;
using span       = elementBoolean<tag<"span">>;
using strong     = elementBoolean<tag<"strong">>;
using style      = elementBoolean<tag<"style">>;
using sub        = elementBoolean<tag<"sub">>;
using summary    = elementBoolean<tag<"summary">>;
using sup        = elementBoolean<tag<"sup">>;
using svg        = elementBoolean<tag<"svg">>;
using table      = elementBoolean<tag<"table">>;
using tbody      = elementBoolean<tag<"tbody">>;
using td         = elementBoolean<tag<"td">>;
using textarea   = elementBoolean<tag<"textarea">>;
using text       = elementBoolean<tag<"">>;
using tfoot      = elementBoolean<tag<"tfoot">>;
using th         = elementBoolean<tag<"th">>;
using thead      = elementBoolean<tag<"thead">>;
using time       = elementBoolean<tag<"time">>;
using title      = elementBoolean<tag<"title">>;
using tr         = elementBoolean<tag<"tr">>;
using track      = elementAtomic<tag<"track">>;
using u          = elementBoolean<tag<"u">>;
using ul         = elementBoolean<tag<"ul">>;
using var        = elementBoolean<tag<"var">>;
using video      = elementBoolean<tag<"video">>;
using wbr        = elementAtomic<tag<"wbr">>;

}  // namespace html

namespace rss {

std::string format_time(std::int64_t sec);
std::string format_time_now();

/*
class rss : public elementBoolean<tag<"rss">>
{
public:
  explicit rss(std::string version = "2.0",
               std::string xmlns   = "http://www.w3.org/2005/Atom")
      : elementBoolean(attributeList({{"version", std::move(version)},
                                      {"xmlns:atom", std::move(xmlns)}}))
  {
  }
};

class atomLink : public elementAtomic<tag<"atom:link">>
{
public:
  explicit atomLink(std::string rel  = "self",
                    std::string type = "application/rss+xml")
      : elementAtomic(attributeList(
            {{"rel", std::move(rel)}, {"type", std::move(type)}}))
  {
  }
};
*/

using author         = elementBoolean<tag<"author">>;
using category       = elementBoolean<tag<"category">>;
using channel        = elementBoolean<tag<"channel">>;
using cloud          = elementAtomic<tag<"cloud">>;
using comments       = elementBoolean<tag<"comments">>;
using copyright      = elementBoolean<tag<"copyright">>;
using description    = elementBoolean<tag<"description">>;
using docs           = elementBoolean<tag<"docs">>;
using enclosure      = elementAtomic<tag<"enclosure">>;
using generator      = elementBoolean<tag<"generator">>;
using guid           = elementBoolean<tag<"guid">>;
using height         = elementBoolean<tag<"height">>;
using image          = elementBoolean<tag<"image">>;
using item           = elementBoolean<tag<"item">>;
using language       = elementBoolean<tag<"language">>;
using lastBuildDate  = elementBoolean<tag<"lastBuildDate">>;
using link           = elementBoolean<tag<"link">>;
using managingEditor = elementBoolean<tag<"managingEditor">>;
using name           = elementBoolean<tag<"name">>;
using pubDate        = elementBoolean<tag<"pubDate">>;
using rating         = elementBoolean<tag<"rating">>;
using skipDays       = elementBoolean<tag<"skipDays">>;
using skipHours      = elementBoolean<tag<"skipHours">>;
using source         = elementBoolean<tag<"source">>;
using text           = elementBoolean<tag<"">>;
using textinput      = elementBoolean<tag<"textinput">>;
using title          = elementBoolean<tag<"title">>;
using ttl            = elementBoolean<tag<"ttl">>;
using url            = elementBoolean<tag<"url">>;
using webMaster      = elementBoolean<tag<"webMaster">>;
using width          = elementBoolean<tag<"width">>;

}  // namespace rss

namespace atom {

std::string format_time(std::int64_t sec);
std::string format_time_now();

/*
class feed : public elementBoolean<tag<"feed">>
{
public:
  explicit feed(std::string xmlns = "http://www.w3.org/2005/Atom")
      : elementBoolean(attributeList({{"xmlns", std::move(xmlns)}}))
  {
  }
};
*/

using author        = elementBoolean<tag<"author">>;
using category      = elementBoolean<tag<"category">>;
using content       = elementBoolean<tag<"content">>;
using contributor   = elementBoolean<tag<"contributor">>;
using div           = elementBoolean<tag<"div">>;
using email         = elementBoolean<tag<"email">>;
using entry         = elementBoolean<tag<"entry">>;
using generator     = elementBoolean<tag<"generator">>;
using icon          = elementBoolean<tag<"icon">>;
using id            = elementBoolean<tag<"id">>;
using intervalBlock = elementBoolean<tag<"intervalBlock">>;
using link          = elementBoolean<tag<"link">>;
using logo          = elementBoolean<tag<"logo">>;
using meterReading  = elementBoolean<tag<"meterReading">>;
using name          = elementBoolean<tag<"name">>;
using published     = elementBoolean<tag<"published">>;
using readingType   = elementBoolean<tag<"readingType">>;
using rights        = elementBoolean<tag<"rights">>;
using source        = elementBoolean<tag<"source">>;
using subtitle      = elementBoolean<tag<"subtitle">>;
using summary       = elementBoolean<tag<"summary">>;
using text          = elementBoolean<tag<"">>;
using title         = elementBoolean<tag<"title">>;
using updated       = elementBoolean<tag<"updated">>;
using uri           = elementBoolean<tag<"uri">>;
using usagePoint    = elementBoolean<tag<"usagePoint">>;

}  // namespace atom

namespace sitemap {

/*
class urlset : public elementBoolean<tag<"urlset">>
{
public:
  explicit urlset(
      std::string xmlns = "http://www.sitemaps.org/schemas/sitemap/0.9")
      : elementBoolean(attributeList({"xmlns", std::move(xmlns)}))
  {
  }
};
*/

using changefreq = elementBoolean<tag<"changefreq">>;
using lastmod    = elementBoolean<tag<"lastmod">>;
using loc        = elementBoolean<tag<"loc">>;
using url        = elementBoolean<tag<"url">>;
using priority   = elementBoolean<tag<"priority">>;

}  // namespace sitemap

}  // namespace hemplate
