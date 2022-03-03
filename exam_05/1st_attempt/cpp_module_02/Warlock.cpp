#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
	:	name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
	spellbook = new SpellBook();
}

Warlock::~Warlock()
{
	delete spellbook;
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName() const
{
	return name;
}

const std::string&	Warlock::getTitle() const
{
	return title;
}

void				Warlock::setTitle(std::string const & new_title)
{
	title = new_title;
}

void				Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	spellbook->learnSpell(spell);
}

void	Warlock::forgetSpell(std::string const & spell_name)
{
	spellbook->forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string const & spell_name, ATarget const & target)
{
	ASpell* spell = spellbook->createSpell(spell_name);
	spell->launch(target);
}
