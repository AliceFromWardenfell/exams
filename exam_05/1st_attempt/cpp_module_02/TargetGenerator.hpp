#pragma once

#include "ATarget.hpp"
#include <iostream>
#include <map>

class TargetGenerator
{
	public:

		TargetGenerator();
		~TargetGenerator();

	private:

		TargetGenerator(TargetGenerator const & instance);
		TargetGenerator& operator=(TargetGenerator const & instance);

	private:

		std::map< std::string, ATarget* > generator;

	public:

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(std::string const & target_type);
		ATarget*	createTarget(std::string const & target_type);

};