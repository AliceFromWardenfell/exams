#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "BrickWall.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
#include "Warlock.hpp"

int main()
{
	ASpell* f1 = new Fireball();
	// Fireball f2 = *f1;
	// Fireball f3;
	// *f1 = f3;

	ASpell* p1 = new Polymorph();
	// Polymorph p2 = *p1;
	// Polymorph p3;
	// *p1 = p3;

	BrickWall* w1 = new BrickWall();
	// BrickWall w2 = w1;
	// BrickWall w3;
	// w1 = w3;

	Dummy* d1 = new Dummy();

	std::cout << f1->getName() << std::endl;
	std::cout << p1->getName() << std::endl;

	*f1 = *p1;

	std::cout << f1->getName() << std::endl;
	std::cout << p1->getName() << std::endl;

	TargetGenerator generator;

	generator.learnTargetType(w1);
	generator.learnTargetType(d1);
	
	ATarget* new_target1 = generator.createTarget("Inconspicuous Red-brick Wall");
	ATarget* new_target2 = generator.createTarget("Target Practice Dummy");
	if (new_target1)
		std::cout << new_target1->getType() << std::endl;
	else
		std::cout << "new_target1 = NULL" << std::endl;
	if (new_target2)
		std::cout << new_target2->getType() << std::endl;
	else
		std::cout << "new_target2 = NULL" << std::endl;

	generator.forgetTargetType("Inconspicuous Red-brick Wall");
	//generator.forgetTargetType("Target Practice Dummy");

	ATarget* new_target3 = generator.createTarget("Inconspicuous Red-brick Wall");
	ATarget* new_target4 = generator.createTarget("Target Practice Dummy");

	if (new_target3)
		std::cout << new_target3->getType() << std::endl;
	else
		std::cout << "new_target1 = NULL" << std::endl;
	if (new_target4)
		std::cout << new_target4->getType() << std::endl;
	else
		std::cout << "new_target2 = NULL" << std::endl;

	Warlock* streg = new Warlock("Neo", "The One");
	streg->introduce();
	streg->learnSpell(f1);
	streg->learnSpell(p1);
	streg->launchSpell("Fireball", *new_target1);
	streg->launchSpell("Polymorph", *new_target2);
	streg->forgetSpell("Fireball");
	streg->forgetSpell("Polymorph");
	streg->launchSpell("Fireball", *new_target1);
	streg->launchSpell("Polymorph", *new_target2);

	delete f1;
	delete p1;

	delete w1;
	delete d1;

	delete new_target1;
	delete new_target2;
	delete new_target3;
	delete new_target4;

	delete streg;
}