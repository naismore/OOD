#pragma once
#include <memory>
#include "CShape.h"

class SimpleShapeFabric
{
public:
	static std::shared_ptr<CShape> createShape(const std::string& type, const std::string& params);
	static std::shared_ptr<sf::Shape> createShapeBorder(const std::shared_ptr<CShape>& shape, double thickness, sf::Color color);
};