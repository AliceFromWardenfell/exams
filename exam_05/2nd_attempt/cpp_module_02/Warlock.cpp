#include "Warlock.hpp"

Warlock::Warlock(std::string new_name, std::string new_title)	:
	name(new_name),
	title(new_title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const { return name; }
const std::string& Warlock::getTitle() const { return title; }
void Warlock::setTitle(const std::string& new_title) { title = new_title; }

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	spellbook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell_name)
{
	spellbook.forgetSpell(spell_name);
}

void Warlock::launchSpell(std::string spell_name, ATarget& target)
{
	ASpell* spell = spellbook.createSpell(spell_name);
	if (spell)
	{
		spell->launch(target);
	}
}
