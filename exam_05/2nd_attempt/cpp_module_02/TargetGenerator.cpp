#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it = generator.begin();
	std::map<std::string, ATarget*>::iterator it_end = generator.end();

	while (it != it_end)
	{
		delete it->second;
		it++;
	}
	generator.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
	{
		generator[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string& target_type)
{
	std::map<std::string, ATarget*>::iterator it;
	it = generator.find(target_type);
	if (it != generator.end())
	{
		delete it->second;
		generator.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(const std::string& target_type)
{
	ATarget* target = generator[target_type];
	if (target)
		return target->clone();
	return NULL;
}
