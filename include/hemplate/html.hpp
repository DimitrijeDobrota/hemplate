#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::html
{

using hemplate::blank;
using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

class doctype : public element
{
public:
  explicit doctype()
      : element("<!DOCTYPE html>", "", "")
  {
  }
};

// clang-format off
// NOLINTBEGIN *-identifier-naming
using abbr       = element_builder<"abbr", element::Type::Boolean>;
using address    = element_builder<"address", element::Type::Boolean>;
using a          = element_builder<"a", element::Type::Boolean>;
using area       = element_builder<"area", element::Type::Atomic>;
using article    = element_builder<"article", element::Type::Boolean>;
using aside      = element_builder<"aside", element::Type::Boolean>;
using audio      = element_builder<"audio", element::Type::Boolean>;
using base       = element_builder<"base", element::Type::Atomic>;
using bdi        = element_builder<"bdi", element::Type::Boolean>;
using bdo        = element_builder<"bdo", element::Type::Boolean>;
using b          = element_builder<"b", element::Type::Boolean>;
using blockquote = element_builder<"blockquote", element::Type::Boolean>;
using body       = element_builder<"body", element::Type::Boolean>;
using br         = element_builder<"br", element::Type::Atomic>;
using button     = element_builder<"button", element::Type::Boolean>;
using canvas     = element_builder<"canvas", element::Type::Boolean>;
using caption    = element_builder<"caption", element::Type::Boolean>;
using cite       = element_builder<"cite", element::Type::Boolean>;
using code       = element_builder<"code", element::Type::Boolean>;
using col        = element_builder<"col", element::Type::Atomic>;
using colgroup   = element_builder<"colgroup", element::Type::Boolean>;
using data       = element_builder<"data", element::Type::Boolean>;
using datalist   = element_builder<"datalist", element::Type::Boolean>;
using dd         = element_builder<"dd", element::Type::Boolean>;
using del        = element_builder<"del", element::Type::Boolean>;
using details    = element_builder<"details", element::Type::Boolean>;
using dfn        = element_builder<"dfn", element::Type::Boolean>;
using dialog     = element_builder<"dialog", element::Type::Boolean>;
using div        = element_builder<"div", element::Type::Boolean>;
using dl         = element_builder<"dl", element::Type::Boolean>;
using dt         = element_builder<"dt", element::Type::Boolean>;
using embed      = element_builder<"embed", element::Type::Atomic>;
using em         = element_builder<"em", element::Type::Boolean>;
using fieldset   = element_builder<"fieldset", element::Type::Boolean>;
using figcaption = element_builder<"figcaption", element::Type::Boolean>;
using figure     = element_builder<"figure", element::Type::Boolean>;
using footer     = element_builder<"footer", element::Type::Boolean>;
using form       = element_builder<"form", element::Type::Boolean>;
using h1         = element_builder<"h1", element::Type::Boolean>;
using h2         = element_builder<"h2", element::Type::Boolean>;
using h3         = element_builder<"h3", element::Type::Boolean>;
using h4         = element_builder<"h4", element::Type::Boolean>;
using h5         = element_builder<"h5", element::Type::Boolean>;
using h6         = element_builder<"h6", element::Type::Boolean>;
using head       = element_builder<"head", element::Type::Boolean>;
using header     = element_builder<"header", element::Type::Boolean>;
using hgroup     = element_builder<"hgroup", element::Type::Boolean>;
using hr         = element_builder<"hr", element::Type::Atomic>;
using html       = element_builder<"html", element::Type::Boolean>;
using i          = element_builder<"i", element::Type::Boolean>;
using iframe     = element_builder<"iframe", element::Type::Boolean>;
using img        = element_builder<"img", element::Type::Atomic>;
using input      = element_builder<"input", element::Type::Atomic>;
using ins        = element_builder<"ins", element::Type::Boolean>;
using kbd        = element_builder<"kbd", element::Type::Boolean>;
using label      = element_builder<"label", element::Type::Boolean>;
using legend     = element_builder<"legend", element::Type::Boolean>;
using li         = element_builder<"li", element::Type::Boolean>;
using link       = element_builder<"link", element::Type::Atomic>;
using main       = element_builder<"main", element::Type::Boolean>;
using map        = element_builder<"map", element::Type::Boolean>;
using mark       = element_builder<"mark", element::Type::Boolean>;
using menu       = element_builder<"menu", element::Type::Boolean>;
using meta       = element_builder<"meta", element::Type::Atomic>;
using meter      = element_builder<"meter", element::Type::Boolean>;
using nav        = element_builder<"nav", element::Type::Boolean>;
using noscript   = element_builder<"noscript", element::Type::Boolean>;
using object     = element_builder<"object", element::Type::Boolean>;
using ol         = element_builder<"ol", element::Type::Boolean>;
using optgroup   = element_builder<"optgroup", element::Type::Boolean>;
using option     = element_builder<"option", element::Type::Boolean>;
using output     = element_builder<"output", element::Type::Boolean>;
using p          = element_builder<"p", element::Type::Boolean>;
using param      = element_builder<"param", element::Type::Atomic>;
using picture    = element_builder<"picture", element::Type::Boolean>;
using pre        = element_builder<"pre", element::Type::Boolean>;
using progress   = element_builder<"progress", element::Type::Boolean>;
using q          = element_builder<"q", element::Type::Boolean>;
using rp         = element_builder<"rp", element::Type::Boolean>;
using rt         = element_builder<"rt", element::Type::Boolean>;
using ruby       = element_builder<"ruby", element::Type::Boolean>;
using s          = element_builder<"s", element::Type::Boolean>;
using samp       = element_builder<"samp", element::Type::Boolean>;
using script     = element_builder<"script", element::Type::Boolean>;
using search     = element_builder<"search", element::Type::Boolean>;
using section    = element_builder<"section", element::Type::Boolean>;
using select     = element_builder<"select", element::Type::Boolean>;
using small      = element_builder<"small", element::Type::Boolean>;
using source     = element_builder<"source", element::Type::Atomic>;
using span       = element_builder<"span", element::Type::Boolean>;
using strong     = element_builder<"strong", element::Type::Boolean>;
using style      = element_builder<"style", element::Type::Boolean>;
using sub        = element_builder<"sub", element::Type::Boolean>;
using summary    = element_builder<"summary", element::Type::Boolean>;
using sup        = element_builder<"sup", element::Type::Boolean>;
using svg        = element_builder<"svg", element::Type::Boolean>;
using table      = element_builder<"table", element::Type::Boolean>;
using tbody      = element_builder<"tbody", element::Type::Boolean>;
using td         = element_builder<"td", element::Type::Boolean>;
using textarea   = element_builder<"textarea", element::Type::Boolean>;
using text       = element_builder<"", element::Type::Boolean>;
using tfoot      = element_builder<"tfoot", element::Type::Boolean>;
using th         = element_builder<"th", element::Type::Boolean>;
using thead      = element_builder<"thead", element::Type::Boolean>;
using time       = element_builder<"time", element::Type::Boolean>;
using title      = element_builder<"title", element::Type::Boolean>;
using tr         = element_builder<"tr", element::Type::Boolean>;
using track      = element_builder<"track", element::Type::Atomic>;
using u          = element_builder<"u", element::Type::Boolean>;
using ul         = element_builder<"ul", element::Type::Boolean>;
using var        = element_builder<"var", element::Type::Boolean>;
using video      = element_builder<"video", element::Type::Boolean>;
using wbr        = element_builder<"wbr", element::Type::Atomic>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::html
