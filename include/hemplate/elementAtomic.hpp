#pragma once

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate {

template<typename Tag>
class HEMPLATE_EXPORT elementAtomic : public element
{
public:
  elementAtomic(const elementAtomic&)                = default;
  elementAtomic(elementAtomic&&) noexcept            = default;
  elementAtomic& operator=(const elementAtomic&)     = default;
  elementAtomic& operator=(elementAtomic&&) noexcept = default;
  ~elementAtomic() override                          = default;

  elementAtomic()
      : element({}, {}, "", Type::Atomic)
  {
  }

  elementAtomic(attributeList attributes)  // NOLINT
      : element(std::move(attributes), {}, "", Type::Atomic)
  {
  }

  const char* get_name() const override { return Tag::get_name(); }

  std::unique_ptr<element> clone() const override
  {
    return std::make_unique<elementAtomic<Tag>>(*this);
  }

private:
};

}  // namespace hemplate
