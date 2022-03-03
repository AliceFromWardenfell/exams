#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string new_name, std::string new_effects) :
	name(new_name),
	effects(new_effects)
{
	return;
}

ASpell::ASpell(const ASpell& instance) :
	name(instance.getName()),
	effects(instance.getEffects())
{
	return;
}

ASpell& ASpell::operator=(const ASpell& instance)
{
	if (this != &instance)
	{
		this->name = instance.getName();
		this->effects = instance.getEffects();
	}
	return *this;
}

ASpell::~ASpell() {}

std::string ASpell::getName() const { return name; }
std::string ASpell::getEffects() const { return effects; }

void ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
