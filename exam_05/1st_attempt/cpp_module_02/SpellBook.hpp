#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class SpellBook
{
	public:

		SpellBook();
		~SpellBook();

	private:

		SpellBook(SpellBook const & instance);
		SpellBook& operator=(SpellBook const & instance);

	private:

		std::map< std::string, ASpell* > spellbook;

	public:

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const & spell_name);
		ASpell*	createSpell(std::string const & spell_name);

};