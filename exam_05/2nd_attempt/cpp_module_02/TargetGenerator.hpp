#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	public:

		TargetGenerator();
		~TargetGenerator();
		
	public:

		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string& target_type);
		ATarget* createTarget(const std::string& target_type);

	private:

		std::map<std::string, ATarget*> generator;
	
	private:

		TargetGenerator(const TargetGenerator& instance);
		TargetGenerator& operator=(const TargetGenerator& instance);

};