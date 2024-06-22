#pragma once

#include "hemplate/element.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate
{

template<typename Tag>
class HEMPLATE_EXPORT elementBoolean : public element
{
public:
  elementBoolean(const elementBoolean&)                = default;
  elementBoolean(elementBoolean&&) noexcept            = default;
  elementBoolean& operator=(const elementBoolean&)     = default;
  elementBoolean& operator=(elementBoolean&&) noexcept = default;
  ~elementBoolean() override                           = default;

  elementBoolean()
      : element({}, {}, "", Type::Boolean)
  {
  }

  elementBoolean(std::string text)  // NOLINT
      : element({}, {}, std::move(text), Type::Boolean)
  {
  }

  elementBoolean(attributeList attributes)  // NOLINT
      : element(std::move(attributes), {}, "", Type::Boolean)
  {
  }

  elementBoolean(elementList embedded)  // NOLINT
      : element({}, std::move(embedded), "", Type::Boolean)
  {
  }

  elementBoolean(std::string text, attributeList attributes)
      : element(std::move(attributes), {}, std::move(text), Type::Boolean)
  {
  }

  elementBoolean(attributeList attributes, elementList embedded)
      : element(std::move(attributes), std::move(embedded), "", Type::Boolean)
  {
  }

  const char* get_name() const override { return Tag::get_name(); }
  bool get_state() const override { return m_state; }

  void tgl_state() const override { m_state = !m_state; }

  std::unique_ptr<element> clone() const override
  {
    return std::make_unique<elementBoolean<Tag>>(*this);
  }

private:
  static bool m_state;  // NOLINT
};

template<typename Tag>
bool elementBoolean<Tag>::m_state = false;  // NOLINT

}  // namespace hemplate
