#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() { }

TargetGenerator::TargetGenerator(TargetGenerator const & instance)
	:	generator(instance.generator) { }

TargetGenerator::~TargetGenerator() { }

TargetGenerator&	TargetGenerator::operator=(TargetGenerator const & instance)
{
	if (this != &instance)
		this->generator = instance.generator;
	return *this;
}

void		TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		generator[target->getType()] = target->clone();
}

void		TargetGenerator::forgetTargetType(std::string const & target_type)
{
	std::map< std::string, ATarget* >::iterator it;
	it = generator.find(target_type);
	if (it != generator.end())
		delete it->second;
	generator.erase(target_type);
}

ATarget*	TargetGenerator::createTarget(std::string const & target_type)
{
	std::map< std::string, ATarget* >::iterator it;
	it = generator.find(target_type);
	if (it == generator.end())
		throw std::exception();
	return it->second;
}
