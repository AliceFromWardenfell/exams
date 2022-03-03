#pragma once

#include <iostream>

class ATarget;

class ASpell
{
	public:

		ASpell();
		ASpell(std::string const & name, std::string const & effects);
		ASpell(ASpell const & instance);
		virtual ~ASpell();
		ASpell&	operator=(ASpell const & instance);

	protected:

		std::string	name;
		std::string	effects;

	public:

		std::string	getName() const;
		std::string	getEffects() const;

		virtual ASpell*	clone() = 0;
		void			launch(ATarget const & target) const;
};
