#include "CShapeGroup.h"

CShapeGroup::CShapeGroup() : CShape("ShapeGroup") {}

void CShapeGroup::Add(std::shared_ptr<CShape> shape)
{
	m_shapes.push_back(shape);
}

void CShapeGroup::Remove(std::shared_ptr<CShape> shape)
{
	m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
}

double CShapeGroup::GetArea() const
{
	double totalArea = 0;
	for (const auto& shape : m_shapes)
	{
		totalArea += shape->GetArea();
	}
	return totalArea;
}

double CShapeGroup::GetPerimeter() const
{
	double totalPerimeter = 0;
	for (const auto& shape : m_shapes)
	{
		totalPerimeter += shape->GetPerimeter();
	}
	return totalPerimeter;
}

void CShapeGroup::draw(sf::RenderWindow& window)
{
	for (const auto& shape : m_shapes)
	{
		shape->draw(window);
	}
}
