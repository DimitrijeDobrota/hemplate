#pragma once

#include <array>

#include <based/string.hpp>
#include <based/type_traits.hpp>

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

using comment = element_builder<"comment", element::Type::Comment>;
using transparent = element_builder<"transparent", element::Type::Transparent>;

class HEMPLATE_EXPORT xml
    : public element_builder<"xml", element::Type::Special>
{
public:
  static constexpr const auto default_version = "1.0";
  static constexpr const auto default_encoding = "UTF-8";

  static auto data(std::string_view version, std::string_view encoding)
  {
    const attribute_list attrs {{"version", version}, {"encoding", encoding}};
    return "?xml " + std::string(attrs) + "?";
  }

  explicit xml(
      std::string_view version = default_version,
      std::string_view encoding = default_encoding
  )
      : element_builder(data(version, encoding))
  {
  }
};

template<std::ranges::forward_range R>
transparent transform(
    const R& range, based::Procedure<std::ranges::range_value_t<R>> auto proc
)
{
  std::vector<element> res;

  res.reserve(std::size(range));
  for (const auto& elem : range) {
    res.emplace_back(proc(elem));
  }

  return transparent {res};
}
}  // namespace hemplate
