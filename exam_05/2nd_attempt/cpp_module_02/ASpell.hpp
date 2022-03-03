#pragma once

#include <iostream>

class ATarget;

class ASpell
{
	public:

		ASpell();
		ASpell(std::string new_name, std::string new_effects);
		virtual ~ASpell();
		ASpell(const ASpell& instance);
		ASpell& operator=(const ASpell& instance);

	public:

		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell* clone() const = 0;
		void launch(const ATarget& target) const;

	protected:

		std::string	name;
		std::string	effects;

};