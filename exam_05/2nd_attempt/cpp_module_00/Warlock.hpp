#pragma once

#include <iostream>

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

	private:

		std::string	name;
		std::string	title;

	private:

		Warlock();
		Warlock(const Warlock& instance);
		Warlock& operator=(const Warlock& instance);

};