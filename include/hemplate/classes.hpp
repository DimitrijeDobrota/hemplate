#pragma once

#include <array>

#include <based/string.hpp>
#include <based/type_traits.hpp>

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT comment : public element
{
public:
  explicit comment(std::string_view data)
      : element(std::format("<-- {} -->", data), "", "")
  {
  }
};

class HEMPLATE_EXPORT xml : public element
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
      : element(
            std::format("<? {}?>", attribute_list {version, encoding}), "", ""
        )
  {
  }
};

template<std::ranges::forward_range R>
blank transform(
    const R& range, based::Procedure<std::ranges::range_value_t<R>> auto proc
)
{
  std::vector<element> res;

  res.reserve(std::size(range));
  for (const auto& elem : range) {
    res.emplace_back(proc(elem));
  }

  return blank {res};
}

}  // namespace hemplate
