#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
	public:

		Warlock(std::string const & name, std::string const & title);
		~Warlock();

	private:

		Warlock();
		Warlock(Warlock const & instance);
		Warlock& operator=(Warlock const & instance);

	private:

		std::string	name;
		std::string	title;
		std::map< std::string, ASpell* > spellbook;

	public:

		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(std::string const & new_title);

		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const & spell_name);
		void	launchSpell(std::string const & spell_name, ATarget const & target);

};
