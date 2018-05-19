#include <stdexcept>

#include "entity.h"

CEntity::CEntity(std::string& name)
    : _name(std::move(name))
{
    validateEntity();
}

CEntity::CEntity(std::string&& name)
    : _name(std::move(name))
{
    validateEntity();
}

bool CEntity::operator==(const CEntity& rhs) const
{
    return this->getName() == rhs.getName();
}

std::string_view CEntity::getName() const
{
    return std::string_view(&_name[0], _name.size());
}

void CEntity::validateEntity()
{
    if (_name.empty())
    {
        throw std::logic_error("Name cannot be empty");
    }
}