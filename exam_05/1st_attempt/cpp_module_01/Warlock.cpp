#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
	:	name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
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
	if (spell)
		spellbook[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(std::string const & spell_name)
{
	std::map< std::string, ASpell* >::iterator it;
	it = spellbook.find(spell_name);
	if (it != spellbook.end())
		delete it->second;
	spellbook.erase(spell_name);
}

void	Warlock::launchSpell(std::string const & spell_name, ATarget const & target)
{
	ASpell* spell = spellbook[spell_name];
	if (spell)
		spell->launch(target);
}
