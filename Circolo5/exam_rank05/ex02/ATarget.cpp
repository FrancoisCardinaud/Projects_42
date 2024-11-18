#include "ATarget.hpp"

ATarget::~ATarget() {}

ATarget::ATarget(const std::string& type) : type(type)
{
}

const std::string& ATarget::getType() const
{
    return type;
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}