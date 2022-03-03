#include "BrickWall.hpp"

BrickWall::BrickWall() :
	ATarget("Inconspicuous Red-brick Wall")
{
	return;
}

ATarget* BrickWall::clone() const
{
	return new BrickWall();
}
