#pragma once

#include <array>

#include <based/string.hpp>
#include <based/type_traits.hpp>

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

template<based::string_literal Name>
struct tag
{
  static auto get_name() { return Name.data(); }
  static auto get_size() { return Name.size(); }
};

using comment = element_builder<tag<"comment">, element::Type::Comment>;

class HEMPLATE_EXPORT xml
    : public element_builder<tag<"xml">, element::Type::Xml>
{
public:
  static constexpr const auto default_version = "1.0";
  static constexpr const auto default_encoding = "UTF-8";

  explicit xml(std::string version = default_version,
               std::string encoding = default_encoding)
      : element_builder({{"version", std::move(version)},
                         {"encoding", std::move(encoding)}})
  {
  }
};

using transparent =
    element_builder<tag<"transparent">, element::Type::Transparent>;

template<std::ranges::forward_range R>
transparent transform(const R& range,
                      based::Procedure<std::ranges::range_value_t<R>> auto proc)
{
  std::vector<element> res;

  res.reserve(std::size(range));
  for (const auto& elem : range) {
    res.emplace_back(proc(elem));
  }

  return transparent {res};
}
}  // namespace hemplate
