#include "SpellBook.hpp"

SpellBook::SpellBook() { }

SpellBook::SpellBook(SpellBook const & instance)
	:	spellbook(instance.spellbook) { }

SpellBook::~SpellBook() { }

SpellBook&	SpellBook::operator=(SpellBook const & instance)
{
	if (this != &instance)
		this->spellbook = instance.spellbook;
	return *this;
}

void	SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
		spellbook[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(std::string const & spell_name)
{
	std::map< std::string, ASpell* >::iterator it;
	it = spellbook.find(spell_name);
	if (it != spellbook.end())
		delete it->second;
	spellbook.erase(spell_name);
}

ASpell*	SpellBook::createSpell(std::string const & spell_name)
{
	std::map< std::string, ASpell* >::iterator it;
	it = spellbook.find(spell_name);
	if (it == spellbook.end())
		throw std::exception();
	return it->second;
}
