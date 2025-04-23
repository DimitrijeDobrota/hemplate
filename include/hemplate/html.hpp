#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::html
{

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::transparent;
using hemplate::xml;

// clang-format off
// NOLINTBEGIN *-identifier-naming
using abbr       = element_builder<tag<"abbr">, element::Type::Boolean>;
using address    = element_builder<tag<"address">, element::Type::Boolean>;
using a          = element_builder<tag<"a">, element::Type::Boolean>;
using area       = element_builder<tag<"area">, element::Type::Atomic>;
using article    = element_builder<tag<"article">, element::Type::Boolean>;
using aside      = element_builder<tag<"aside">, element::Type::Boolean>;
using audio      = element_builder<tag<"audio">, element::Type::Boolean>;
using base       = element_builder<tag<"base">, element::Type::Atomic>;
using bdi        = element_builder<tag<"bdi">, element::Type::Boolean>;
using bdo        = element_builder<tag<"bdo">, element::Type::Boolean>;
using b          = element_builder<tag<"b">, element::Type::Boolean>;
using blockquote = element_builder<tag<"blockquote">, element::Type::Boolean>;
using body       = element_builder<tag<"body">, element::Type::Boolean>;
using br         = element_builder<tag<"br">, element::Type::Atomic>;
using button     = element_builder<tag<"button">, element::Type::Boolean>;
using canvas     = element_builder<tag<"canvas">, element::Type::Boolean>;
using caption    = element_builder<tag<"caption">, element::Type::Boolean>;
using cite       = element_builder<tag<"cite">, element::Type::Boolean>;
using code       = element_builder<tag<"code">, element::Type::Boolean>;
using col        = element_builder<tag<"col">, element::Type::Atomic>;
using colgroup   = element_builder<tag<"colgroup">, element::Type::Boolean>;
using data       = element_builder<tag<"data">, element::Type::Boolean>;
using datalist   = element_builder<tag<"datalist">, element::Type::Boolean>;
using dd         = element_builder<tag<"dd">, element::Type::Boolean>;
using del        = element_builder<tag<"del">, element::Type::Boolean>;
using details    = element_builder<tag<"details">, element::Type::Boolean>;
using dfn        = element_builder<tag<"dfn">, element::Type::Boolean>;
using dialog     = element_builder<tag<"dialog">, element::Type::Boolean>;
using div        = element_builder<tag<"div">, element::Type::Boolean>;
using dl         = element_builder<tag<"dl">, element::Type::Boolean>;
using doctype    = element_builder<tag<"!DOCTYPE html">, element::Type::Atomic>;
using dt         = element_builder<tag<"dt">, element::Type::Boolean>;
using embed      = element_builder<tag<"embed">, element::Type::Atomic>;
using em         = element_builder<tag<"em">, element::Type::Boolean>;
using fieldset   = element_builder<tag<"fieldset">, element::Type::Boolean>;
using figcaption = element_builder<tag<"figcaption">, element::Type::Boolean>;
using figure     = element_builder<tag<"figure">, element::Type::Boolean>;
using footer     = element_builder<tag<"footer">, element::Type::Boolean>;
using form       = element_builder<tag<"form">, element::Type::Boolean>;
using h1         = element_builder<tag<"h1">, element::Type::Boolean>;
using h2         = element_builder<tag<"h2">, element::Type::Boolean>;
using h3         = element_builder<tag<"h3">, element::Type::Boolean>;
using h4         = element_builder<tag<"h4">, element::Type::Boolean>;
using h5         = element_builder<tag<"h5">, element::Type::Boolean>;
using h6         = element_builder<tag<"h6">, element::Type::Boolean>;
using head       = element_builder<tag<"head">, element::Type::Boolean>;
using header     = element_builder<tag<"header">, element::Type::Boolean>;
using hgroup     = element_builder<tag<"hgroup">, element::Type::Boolean>;
using hr         = element_builder<tag<"hr">, element::Type::Atomic>;
using html       = element_builder<tag<"html">, element::Type::Boolean>;
using i          = element_builder<tag<"i">, element::Type::Boolean>;
using iframe     = element_builder<tag<"iframe">, element::Type::Boolean>;
using img        = element_builder<tag<"img">, element::Type::Atomic>;
using input      = element_builder<tag<"input">, element::Type::Atomic>;
using ins        = element_builder<tag<"ins">, element::Type::Boolean>;
using kbd        = element_builder<tag<"kbd">, element::Type::Boolean>;
using label      = element_builder<tag<"label">, element::Type::Boolean>;
using legend     = element_builder<tag<"legend">, element::Type::Boolean>;
using li         = element_builder<tag<"li">, element::Type::Boolean>;
using link       = element_builder<tag<"link">, element::Type::Atomic>;
using main       = element_builder<tag<"main">, element::Type::Boolean>;
using map        = element_builder<tag<"map">, element::Type::Boolean>;
using mark       = element_builder<tag<"mark">, element::Type::Boolean>;
using menu       = element_builder<tag<"menu">, element::Type::Boolean>;
using meta       = element_builder<tag<"meta">, element::Type::Atomic>;
using meter      = element_builder<tag<"meter">, element::Type::Boolean>;
using nav        = element_builder<tag<"nav">, element::Type::Boolean>;
using noscript   = element_builder<tag<"noscript">, element::Type::Boolean>;
using object     = element_builder<tag<"object">, element::Type::Boolean>;
using ol         = element_builder<tag<"ol">, element::Type::Boolean>;
using optgroup   = element_builder<tag<"optgroup">, element::Type::Boolean>;
using option     = element_builder<tag<"option">, element::Type::Boolean>;
using output     = element_builder<tag<"output">, element::Type::Boolean>;
using p          = element_builder<tag<"p">, element::Type::Boolean>;
using param      = element_builder<tag<"param">, element::Type::Atomic>;
using picture    = element_builder<tag<"picture">, element::Type::Boolean>;
using pre        = element_builder<tag<"pre">, element::Type::Boolean>;
using progress   = element_builder<tag<"progress">, element::Type::Boolean>;
using q          = element_builder<tag<"q">, element::Type::Boolean>;
using rp         = element_builder<tag<"rp">, element::Type::Boolean>;
using rt         = element_builder<tag<"rt">, element::Type::Boolean>;
using ruby       = element_builder<tag<"ruby">, element::Type::Boolean>;
using s          = element_builder<tag<"s">, element::Type::Boolean>;
using samp       = element_builder<tag<"samp">, element::Type::Boolean>;
using script     = element_builder<tag<"script">, element::Type::Boolean>;
using search     = element_builder<tag<"search">, element::Type::Boolean>;
using section    = element_builder<tag<"section">, element::Type::Boolean>;
using select     = element_builder<tag<"select">, element::Type::Boolean>;
using small      = element_builder<tag<"small">, element::Type::Boolean>;
using source     = element_builder<tag<"source">, element::Type::Atomic>;
using span       = element_builder<tag<"span">, element::Type::Boolean>;
using strong     = element_builder<tag<"strong">, element::Type::Boolean>;
using style      = element_builder<tag<"style">, element::Type::Boolean>;
using sub        = element_builder<tag<"sub">, element::Type::Boolean>;
using summary    = element_builder<tag<"summary">, element::Type::Boolean>;
using sup        = element_builder<tag<"sup">, element::Type::Boolean>;
using svg        = element_builder<tag<"svg">, element::Type::Boolean>;
using table      = element_builder<tag<"table">, element::Type::Boolean>;
using tbody      = element_builder<tag<"tbody">, element::Type::Boolean>;
using td         = element_builder<tag<"td">, element::Type::Boolean>;
using textarea   = element_builder<tag<"textarea">, element::Type::Boolean>;
using text       = element_builder<tag<"">, element::Type::Boolean>;
using tfoot      = element_builder<tag<"tfoot">, element::Type::Boolean>;
using th         = element_builder<tag<"th">, element::Type::Boolean>;
using thead      = element_builder<tag<"thead">, element::Type::Boolean>;
using time       = element_builder<tag<"time">, element::Type::Boolean>;
using title      = element_builder<tag<"title">, element::Type::Boolean>;
using tr         = element_builder<tag<"tr">, element::Type::Boolean>;
using track      = element_builder<tag<"track">, element::Type::Atomic>;
using u          = element_builder<tag<"u">, element::Type::Boolean>;
using ul         = element_builder<tag<"ul">, element::Type::Boolean>;
using var        = element_builder<tag<"var">, element::Type::Boolean>;
using video      = element_builder<tag<"video">, element::Type::Boolean>;
using wbr        = element_builder<tag<"wbr">, element::Type::Atomic>;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::html
