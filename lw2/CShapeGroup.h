#pragma once
#include "CShape.h"

class CShapeGroup : public CShape
{
public:
	CShapeGroup();
	void Add(std::shared_ptr<CShape> shape);
	void Remove(std::shared_ptr<CShape> shape);
	double GetArea() const override;
	double GetPerimeter() const override;
	void draw(sf::RenderWindow& window);
private:
	std::vector<std::shared_ptr<CShape>> m_shapes;
};