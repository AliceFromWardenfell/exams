#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string new_type) :
	type(new_type)
{
	return;
}

ATarget::ATarget(const ATarget& instance) :
	type(instance.getType())
{
	return;
}

ATarget& ATarget::operator=(const ATarget& instance)
{
	if (this != &instance)
	{
		this->type = instance.getType();
	}
	return *this;
}

ATarget::~ATarget() {}

const std::string& ATarget::getType() const { return type; }

void ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
