#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "BaseObject.h"

class Obstacle : public BaseObject {

public:
	void update();

	bool b_canKill = false;
	bool quackcollide = false;
};

#endif