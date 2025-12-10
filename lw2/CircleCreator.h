#pragma once
#include <iostream>
#include "CCircle.h"
#include <memory>

class CircleCreator
{
public:
	static CircleCreator& getInstance();
	std::shared_ptr<CCircle> createCircle(const CPoint& center, double radius);
private:
	CircleCreator();
	CircleCreator(const CircleCreator& obj) = delete;
	CircleCreator& operator=(const CircleCreator&) = delete;
};

