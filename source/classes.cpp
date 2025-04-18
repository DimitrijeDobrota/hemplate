#include <chrono>
#include <ctime>
#include <format>
#include <string>

#include "hemplate/classes.hpp"

namespace {

auto sec_since_epoch(int64_t sec)
{
  return std::chrono::time_point_cast<std::chrono::seconds>(
      std::chrono::system_clock::from_time_t(time_t {0})
      + std::chrono::seconds(sec));
}

auto get_time_now()
{
  return std::chrono::current_zone()
             ->to_local(std::chrono::system_clock::now())
             .time_since_epoch()
      / std::chrono::seconds(1);
}

}  // namespace

namespace hemplate::atom {

std::string format_time(int64_t sec)
{
  static constexpr const char* rfc3339_f = "{:%FT%H:%M:%SZ}";
  return std::format(rfc3339_f, sec_since_epoch(sec));
}

std::string format_time_now()
{
  return format_time(get_time_now());
}

}  // namespace hemplate::atom

namespace hemplate::rss {

std::string format_time(int64_t sec)
{
  static constexpr const char* rfc882_f = "{:%a, %d %b %Y %H:%M:%S %z}";
  return std::format(rfc882_f, sec_since_epoch(sec));
}

std::string format_time_now()
{
  return format_time(get_time_now());
}

}  // namespace hemplate::rss
