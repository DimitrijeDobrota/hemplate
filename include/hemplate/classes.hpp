#pragma once

#include <array>
#include <cstdint>

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

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

using comment = element_builder<tag<"comment">, element::Type::Comment>;

class xml : public element_builder<tag<"xml">, element::Type::Xml>
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

template<typename P, typename T>
concept procedure = requires { requires(std::invocable<P, const T&>); };

template<std::ranges::forward_range R>
transparent transform(const R& range,
                      procedure<std::ranges::range_value_t<R>> auto proc)
{
  std::vector<element> res;

  res.reserve(std::size(range));
  for (const auto& elem : range) {
    res.emplace_back(proc(elem));
  }

  return transparent {res};
}
}  // namespace hemplate
