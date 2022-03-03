#pragma once

#include <iostream>
#include "ASpell.hpp"
#include <map>

class Warlock
{
	public:

		Warlock(std::string new_name, std::string new_title);
		~Warlock();

	public:

		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& new_title);

		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spell_name);
		void launchSpell(std::string spell_name, ATarget& target);

	private:

		std::string	name;
		std::string	title;
		std::map<std::string, ASpell*> spellbook;

	private:

		Warlock();
		Warlock(const Warlock& instance);
		Warlock& operator=(const Warlock& instance);

};