#pragma once

#include <memory>
#include <string>
#include <vector>

#include "hemplate/hemplate_export.hpp"
#include "hemplate/streamable.hpp"

namespace hemplate
{

class element;

class HEMPLATE_EXPORT elementList : public streamable
{
public:
  elementList()                         = default;
  ~elementList() override               = default;
  elementList(elementList&&)            = default;
  elementList& operator=(elementList&&) = default;

  // explicitly clone all the elements
  elementList(const elementList& rhs);
  elementList& operator=(const elementList& rhs);

  elementList& add(const element& elem);
  elementList& add(std::unique_ptr<element> elem);

  bool empty() const { return m_elems.empty(); }

  void render(std::ostream& out) const override;

private:
  std::vector<std::unique_ptr<element>> m_elems;
};

class HEMPLATE_EXPORT element : public streamable
{
public:
  enum class Type
  {
    Atomic,
    Boolean,
  };

  explicit element(std::string data, Type type)
      : m_data(std::move(data))
      , m_type(type)
  {
  }

  element(const element&)                = default;
  element(element&&) noexcept            = default;
  element& operator=(const element&)     = default;
  element& operator=(element&&) noexcept = default;
  ~element() override                    = default;

  Type get_type() const { return m_type; }
  std::string get_data() const { return m_data; }
  const elementList& get_embeded() const { return m_embeded; }

  void set_data(const std::string& data) { m_data = data; }
  void set_embedded(const elementList& embed) { m_embeded = embed; }

  element& add(const element& elem);
  element& add(std::unique_ptr<element> elem);

  virtual const char* get_name() const           = 0;
  virtual std::unique_ptr<element> clone() const = 0;

  void render(std::ostream& out) const override;

private:
  std::string m_data;
  Type m_type;

  elementList m_embeded;
};

}  // namespace hemplate
