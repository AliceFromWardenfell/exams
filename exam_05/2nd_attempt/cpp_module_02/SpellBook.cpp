#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it = book.begin();
	std::map<std::string, ASpell*>::iterator it_end = book.end();

	while (it != it_end)
	{
		delete it->second;
		it++;
	}
	book.clear();
	std::cout << "SpellBook disappeared..." << std::endl;
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell && !book[spell->getName()])
	{
		book[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(const std::string& spell_name)
{
	std::map<std::string, ASpell*>::iterator it;
	it = book.find(spell_name);
	if (it != book.end())
	{
		delete it->second;
		book.erase(it);
	}
}

ASpell* SpellBook::createSpell(const std::string& spell_name)
{
	ASpell* spell = book[spell_name];
	if (spell)
		return spell;
	return NULL;
}
