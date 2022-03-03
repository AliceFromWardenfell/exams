#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	public:

		SpellBook();
		~SpellBook();
		
	public:

		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string& spell_name);
		ASpell* createSpell(const std::string& spell_name);

	private:

		std::map<std::string, ASpell*> book;
	
	private:

		SpellBook(const SpellBook& instance);
		SpellBook& operator=(const SpellBook& instance);

};