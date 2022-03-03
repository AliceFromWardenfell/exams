#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string new_name, std::string new_effects) :
	name(new_name),
	effects(new_effects)
{
	return;
}

ASpell::~ASpell() {}

std::string ASpell::getName() const { return name; }
std::string ASpell::getEffects() const { return effects; }

void ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
