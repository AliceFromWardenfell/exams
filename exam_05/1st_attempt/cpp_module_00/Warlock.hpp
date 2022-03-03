#pragma once

#include <iostream>

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

	public:

		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(std::string const & new_title);

		void introduce() const;

};
