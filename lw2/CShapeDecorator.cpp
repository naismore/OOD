#include "CShapeDecorator.h"

CShapeDecorator::CShapeDecorator(std::shared_ptr<CShape> shape) : m_shape(shape), CShape(shape->GetType()) { }

void CShapeDecorator::draw(sf::RenderWindow& window)
{
	m_shape->draw(window);
}

double CShapeDecorator::GetArea() const
{
	return m_shape->GetArea();
}

double CShapeDecorator::GetPerimeter() const
{
	return m_shape->GetPerimeter();
}

std::string CShapeDecorator::ToString() const
{
	return m_shape->ToString();
}

void CShapeDecorator::accept(IVisitor* visitor)
{
	return m_shape->accept(visitor);
}