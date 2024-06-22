#pragma once

#include <memory>
#include <string>
#include <vector>

#include "hemplate/attribute.hpp"
#include "hemplate/hemplate_export.hpp"
#include "hemplate/streamable.hpp"

namespace hemplate {

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

  explicit element(attributeList attributes,
                   elementList embedded,
                   std::string data,
                   Type type)
      : m_attributes(std::move(attributes))
      , m_embeded(std::move(embedded))
      , m_data(std::move(data))
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
  const attributeList& get_attributes() const { return m_attributes; }

  virtual bool get_state() const { return false; }
  virtual const char* get_name() const = 0;

  void set_data(const std::string& data) { m_data = data; }
  void set_embedded(const elementList& embed) { m_embeded = embed; }
  void set_attributes(const attributeList& attrs) { m_attributes = attrs; }

  virtual void tgl_state() const {}

  element& add(const element& elem);
  element& add(std::unique_ptr<element> elem);

  element& set(const std::string& name);
  element& set(const std::string& name, const std::string& value);

  virtual std::unique_ptr<element> clone() const = 0;

  void render(std::ostream& out) const override;

private:
  attributeList m_attributes;
  elementList m_embeded;
  std::string m_data;
  Type m_type;
};

}  // namespace hemplate
