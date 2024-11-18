#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public :
		BrickWall();
		BrickWall* clone() const;
};