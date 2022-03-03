#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() { }

ATarget::ATarget(std::string const & type)
	:	type(type) { }

ATarget::ATarget(ATarget const & instance)
	:	type(instance.type) { }

ATarget::~ATarget() { }

ATarget&	ATarget::operator=(ATarget const & instance)
{
	if (this != &instance)
		this->type = instance.type;
	return *this;
}

std::string const &	ATarget::getType() const { return type; }

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}
