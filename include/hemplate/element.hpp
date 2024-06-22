#pragma once

#include <string>

#include "hemplate/hemplate_export.hpp"
#include "hemplate/streamable.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT element : public streamable
{
public:
  enum class Type
  {
    Atomic,
    Boolean,
  };

  explicit element(Type type)
      : m_type(type)
  {
  }

  element(const element&)                = default;
  element(element&&) noexcept            = default;
  element& operator=(const element&)     = default;
  element& operator=(element&&) noexcept = default;
  ~element() override                    = default;

  Type get_type() const { return m_type; }
  std::string get_data() const { return m_data; }

  void set_data(const std::string& data) { m_data = data; }

  virtual const char* get_name() const = 0;
  void render(std::ostream& out) const override;

private:
  Type m_type;

  std::string m_data;
};

}  // namespace hemplate
