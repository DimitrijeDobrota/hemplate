#pragma once

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

template<typename Tag>
class HEMPLATE_EXPORT elementBoolean : public element
{
public:
  elementBoolean()
      : element("", Type::Boolean)
  {
  }

  elementBoolean(const std::string& text)  // NOLINT
      : element(text, Type::Boolean)
  {
  }

  elementBoolean(const elementBoolean&)                = default;
  elementBoolean(elementBoolean&&) noexcept            = default;
  elementBoolean& operator=(const elementBoolean&)     = default;
  elementBoolean& operator=(elementBoolean&&) noexcept = default;
  ~elementBoolean() override                           = default;

  const char* get_name() const override { return Tag::get_name(); }

  std::unique_ptr<element> clone() const override
  {
    return std::make_unique<elementBoolean<Tag>>(*this);
  }

private:
};

}  // namespace hemplate
