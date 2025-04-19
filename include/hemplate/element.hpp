#pragma once

#include <memory>
#include <span>
#include <string>
#include <vector>

#include "hemplate/attribute.hpp"
#include "hemplate/hemplate_export.hpp"

namespace hemplate {

class HEMPLATE_EXPORT element
{
  enum class Type : uint8_t
  {
    Atomic,
    Boolean,
    Comment,
  };

  Type m_type;

  std::string m_name;
  std::string m_data;

  std::vector<element> m_children;
  attributeList m_attributes;

  explicit element(Type type,
                   std::string_view name,
                   const std::derived_from<element> auto&... children)
      : m_type(type)
      , m_name(name)
      , m_children(std::initializer_list<element> {children...})
  {
  }

  explicit element(Type type, std::string_view name, std::string_view data)
      : m_type(type)
      , m_name(name)
      , m_data(data)
  {
  }

  explicit element(Type type,
                   std::string_view name,
                   std::span<const element> children)
      : m_type(type)
      , m_name(name)
      , m_children(children.begin(), children.end())
  {
  }

  template<typename T>
  friend class elementAtomic;

  template<typename T>
  friend class elementBoolean;

  void render(std::ostream& out, std::size_t indent_value) const;

public:
  friend std::ostream& operator<<(std::ostream& out, const element& element)
  {
    element.render(out, 0);
    return out;
  }

  element& add(const element& elem);
  element& add(std::unique_ptr<element> elem);

  element& set(const std::string& name);
  element& set(const std::string& name, const std::string& value);
};

template<typename Tag>
class HEMPLATE_EXPORT elementAtomic : public element
{
public:
  explicit elementAtomic(std::string_view data)
      : element(element::Type::Atomic, Tag::get_name(), data)
  {
  }

  explicit elementAtomic(const std::derived_from<element> auto&... children)
      : element(element::Type::Atomic, Tag::get_name(), children...)
  {
  }

  explicit elementAtomic(std::span<const element> children)
      : element(element::Type::Atomic, Tag::get_name(), children)
  {
  }
};

template<typename Tag>
class HEMPLATE_EXPORT elementBoolean : public element
{
  static bool m_state;  // NOLINT

public:
  explicit elementBoolean(std::string_view data)
      : element(element::Type::Boolean, Tag::get_name(), data)
  {
  }

  explicit elementBoolean(const std::derived_from<element> auto&... children)
      : element(element::Type::Boolean, Tag::get_name(), children...)
  {
  }

  explicit elementBoolean(std::span<const element> children)
      : element(element::Type::Boolean, Tag::get_name(), children)
  {
  }

  bool get_state() const { return m_state; }
  void tgl_state() const { m_state = !m_state; }
};

template<typename Tag>
bool elementBoolean<Tag>::m_state = false;  // NOLINT

}  // namespace hemplate
