#pragma once

#include <array>

#include <based/concepts/procedure/procedure.hpp>

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT comment : public element
{
public:
  explicit comment(std::string_view data)
      : element(std::format("<-- {} -->", data))
  {
  }
};

class HEMPLATE_EXPORT xml : public element
{
  static auto attrs(std::string_view version, std::string_view encoding)
  {
    return attribute_list {
        {"version", version},
        {"encoding", encoding},
    };
  }

public:
  static constexpr const auto def_version = "1.0";
  static constexpr const auto def_encoding = "UTF-8";

  explicit xml(
      std::string_view version = def_version,
      std::string_view encoding = def_encoding
  )
      : element(std::format("<? xml {}?>", attrs(version, encoding)))
  {
  }
};

template<std::ranges::forward_range R>
element transform(
    const R& range,
    based::Procedure<element, std::ranges::range_value_t<R>> auto proc
)
{
  std::vector<element> res;

  res.reserve(std::size(range));
  for (const auto& elem : range) {
    res.emplace_back(proc(elem));
  }

  return element {res};
}

}  // namespace hemplate
