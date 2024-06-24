#pragma once

#include <array>

#include "hemplate/elementAtomic.hpp"
#include "hemplate/elementBoolean.hpp"
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

namespace html {

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

using author         = elementBoolean<tag<"author">>;
using category       = elementBoolean<tag<"category">>;
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
using textinput      = elementBoolean<tag<"textinput">>;
using title          = elementBoolean<tag<"title">>;
using ttl            = elementBoolean<tag<"ttl">>;
using url            = elementBoolean<tag<"url">>;
using webMaster      = elementBoolean<tag<"webMaster">>;
using width          = elementBoolean<tag<"width">>;
using atomLink       = elementAtomic<tag<"atom:link">>;

}  // namespace rss

namespace atom {

using author        = elementBoolean<tag<"author">>;
using category      = elementBoolean<tag<"category">>;
using content       = elementBoolean<tag<"content">>;
using contributor   = elementBoolean<tag<"contributor">>;
using div           = elementBoolean<tag<"div">>;
using entry         = elementBoolean<tag<"entry">>;
using feed          = elementBoolean<tag<"feed">>;
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
using title         = elementBoolean<tag<"title">>;
using update        = elementBoolean<tag<"update">>;
using updated       = elementBoolean<tag<"updated">>;
using usagePoint    = elementBoolean<tag<"usagePoint">>;

}  // namespace atom

}  // namespace hemplate
