#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() { }

ASpell::ASpell(std::string const & name, std::string const & effects)
	:	name(name), effects(effects) { }

ASpell::ASpell(ASpell const & instance)
	:	name(instance.name), effects(instance.effects) { }

ASpell::~ASpell() { }

ASpell&	ASpell::operator=(ASpell const & instance)
{
	if (this != &instance)
	{
		this->name = instance.name;
		this->effects = instance.effects;
	}
	return *this;
}

std::string	ASpell::getName() const { return name; }
std::string	ASpell::getEffects() const { return effects; }

void	ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}
