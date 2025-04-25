#pragma once

#include "hemplate/classes.hpp"

namespace hemplate::html
{

using hemplate::comment;
using hemplate::element;
using hemplate::transform;
using hemplate::xml;

class doctype : public element
{
public:
  explicit doctype()
      : element("<!DOCTYPE html>")
  {
  }
};

// clang-format off
// NOLINTBEGIN *-identifier-naming
using abbr       = element_boolean<"abbr">;
using address    = element_boolean<"address">;
using a          = element_boolean<"a">;
using article    = element_boolean<"article">;
using aside      = element_boolean<"aside">;
using audio      = element_boolean<"audio">;
using bdi        = element_boolean<"bdi">;
using bdo        = element_boolean<"bdo">;
using b          = element_boolean<"b">;
using blockquote = element_boolean<"blockquote">;
using body       = element_boolean<"body">;
using button     = element_boolean<"button">;
using canvas     = element_boolean<"canvas">;
using caption    = element_boolean<"caption">;
using cite       = element_boolean<"cite">;
using code       = element_boolean<"code">;
using colgroup   = element_boolean<"colgroup">;
using data       = element_boolean<"data">;
using datalist   = element_boolean<"datalist">;
using dd         = element_boolean<"dd">;
using del        = element_boolean<"del">;
using details    = element_boolean<"details">;
using dfn        = element_boolean<"dfn">;
using dialog     = element_boolean<"dialog">;
using div        = element_boolean<"div">;
using dl         = element_boolean<"dl">;
using dt         = element_boolean<"dt">;
using em         = element_boolean<"em">;
using fieldset   = element_boolean<"fieldset">;
using figcaption = element_boolean<"figcaption">;
using figure     = element_boolean<"figure">;
using footer     = element_boolean<"footer">;
using form       = element_boolean<"form">;
using h1         = element_boolean<"h1">;
using h2         = element_boolean<"h2">;
using h3         = element_boolean<"h3">;
using h4         = element_boolean<"h4">;
using h5         = element_boolean<"h5">;
using h6         = element_boolean<"h6">;
using head       = element_boolean<"head">;
using header     = element_boolean<"header">;
using hgroup     = element_boolean<"hgroup">;
using html       = element_boolean<"html">;
using i          = element_boolean<"i">;
using iframe     = element_boolean<"iframe">;
using ins        = element_boolean<"ins">;
using kbd        = element_boolean<"kbd">;
using label      = element_boolean<"label">;
using legend     = element_boolean<"legend">;
using li         = element_boolean<"li">;
using main       = element_boolean<"main">;
using map        = element_boolean<"map">;
using mark       = element_boolean<"mark">;
using menu       = element_boolean<"menu">;
using meter      = element_boolean<"meter">;
using nav        = element_boolean<"nav">;
using noscript   = element_boolean<"noscript">;
using object     = element_boolean<"object">;
using ol         = element_boolean<"ol">;
using optgroup   = element_boolean<"optgroup">;
using option     = element_boolean<"option">;
using output     = element_boolean<"output">;
using p          = element_boolean<"p">;
using picture    = element_boolean<"picture">;
using pre        = element_boolean<"pre">;
using progress   = element_boolean<"progress">;
using q          = element_boolean<"q">;
using rp         = element_boolean<"rp">;
using rt         = element_boolean<"rt">;
using ruby       = element_boolean<"ruby">;
using s          = element_boolean<"s">;
using samp       = element_boolean<"samp">;
using script     = element_boolean<"script">;
using search     = element_boolean<"search">;
using section    = element_boolean<"section">;
using select     = element_boolean<"select">;
using small      = element_boolean<"small">;
using span       = element_boolean<"span">;
using strong     = element_boolean<"strong">;
using style      = element_boolean<"style">;
using sub        = element_boolean<"sub">;
using summary    = element_boolean<"summary">;
using sup        = element_boolean<"sup">;
using svg        = element_boolean<"svg">;
using table      = element_boolean<"table">;
using tbody      = element_boolean<"tbody">;
using td         = element_boolean<"td">;
using textarea   = element_boolean<"textarea">;
using tfoot      = element_boolean<"tfoot">;
using th         = element_boolean<"th">;
using thead      = element_boolean<"thead">;
using time       = element_boolean<"time">;
using title      = element_boolean<"title">;
using tr         = element_boolean<"tr">;
using u          = element_boolean<"u">;
using ul         = element_boolean<"ul">;
using var        = element_boolean<"var">;
using video      = element_boolean<"video">;

using area       = element_atomic<"area">;
using base       = element_atomic<"base">;
using br         = element_atomic<"br">;
using col        = element_atomic<"col">;
using embed      = element_atomic<"embed">;
using hr         = element_atomic<"hr">;
using img        = element_atomic<"img">;
using input      = element_atomic<"input">;
using link       = element_atomic<"link">;
using meta       = element_atomic<"meta">;
using param      = element_atomic<"param">;
using source     = element_atomic<"source">;
using track      = element_atomic<"track">;
using wbr        = element_atomic<"wbr">;
// NOLINTEND *-identifier-naming
// clang-format on

}  // namespace hemplate::html
