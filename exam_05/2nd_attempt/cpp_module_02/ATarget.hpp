#pragma once

#include <iostream>

class ASpell;

class ATarget
{
	public:

		ATarget();
		ATarget(std::string new_type);
		virtual ~ATarget();
		ATarget(const ATarget& instance);
		ATarget& operator=(const ATarget& instance);

	public:

		const std::string& getType() const;

		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& spell) const;

	protected:

		std::string	type;

};