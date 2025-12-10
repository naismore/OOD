#include "CircleCreator.h"

CircleCreator& CircleCreator::getInstance()
{
	static CircleCreator instance;
	return instance;
}

std::shared_ptr<CCircle> CircleCreator::createCircle(const CPoint& center, double radius)
{
	return std::make_shared<CCircle>(center, radius);
}

CircleCreator::CircleCreator() {}