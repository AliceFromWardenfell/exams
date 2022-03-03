#include "Fwoosh.hpp"

Fwoosh::Fwoosh() :
	ASpell("Fwoosh", "fwooshed")
{
	return;
}

ASpell* Fwoosh::clone() const
{
	return new Fwoosh();
}
