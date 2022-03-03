#pragma once

#include <iostream>
#include "ASpell.hpp"

class ATarget
{
	public:

		ATarget();
		ATarget(std::string const & type);
		ATarget(ATarget const & instance);
		virtual ~ATarget();
		ATarget&	operator=(ATarget const & instance);

	protected:

		std::string	type;

	public:

		std::string const &	getType() const;
		
		virtual ATarget*	clone() = 0;
		void				getHitBySpell(ASpell const & spell) const;
};
