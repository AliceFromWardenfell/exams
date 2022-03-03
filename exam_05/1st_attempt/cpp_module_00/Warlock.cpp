#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
	:	name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName() const
{
	return name;
}

const std::string&	Warlock::getTitle() const
{
	return title;
}

void				Warlock::setTitle(std::string const & new_title)
{
	title = new_title;
}

void				Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}