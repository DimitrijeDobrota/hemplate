#pragma once

#include <string>
#include <vector>

#include "hemplate/hemplate_export.hpp"
#include "hemplate/streamable.hpp"

namespace hemplate
{

class HEMPLATE_EXPORT attribute : public streamable
{
public:
  attribute()                            = default;
  attribute(const attribute&)            = default;
  attribute(attribute&&)                 = default;
  attribute& operator=(const attribute&) = default;
  attribute& operator=(attribute&&)      = default;
  ~attribute() override                  = default;

  attribute(std::string name)  // NOLINT
      : m_name(std::move(name))
  {
  }

  attribute(std::string name, std::string value)  // NOLINT
      : m_name(std::move(name))
      , m_value(std::move(value))
  {
  }

  bool operator!=(const attribute& rhs) const;
  bool operator==(const attribute& rhs) const;

  const std::string& get_name() const { return m_name; }
  const std::string& get_value() const { return m_value; }

  void set_name(const std::string& name) { m_name = name; }
  void set_value(const std::string& value) { m_value = value; }

  void render(std::ostream& out) const override;

private:
  std::string m_name;
  std::string m_value;
};

class HEMPLATE_EXPORT attributeList : public streamable
{
public:
  attributeList()                                = default;
  attributeList(const attributeList&)            = default;
  attributeList(attributeList&&)                 = default;
  attributeList& operator=(const attributeList&) = default;
  attributeList& operator=(attributeList&&)      = default;
  ~attributeList() override                      = default;

  attributeList& set(const std::string& name);
  attributeList& set(const std::string& name, const std::string& value);

  bool empty() const { return m_attributes.empty(); }

  void render(std::ostream& out) const override;

private:
  std::vector<attribute> m_attributes;
};

}  // namespace hemplate
