#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		
		BrickWall();

	public:

		ATarget*	clone();
};