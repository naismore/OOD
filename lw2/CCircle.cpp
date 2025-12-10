#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "IVisitor.h"

CCircle::CCircle(const CPoint &center, double &radius)
	: CShape("CIRCLE"), m_center(center), m_radius(radius), m_circle(radius) {
	m_circle.setFillColor(sf::Color::Green);
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::draw(sf::RenderWindow& window)
{
	m_circle.setPosition(m_center.x, m_center.y);
	window.draw(m_circle);
}

CPoint CCircle::GetCenterPoint() const
{
	return m_center;
}


void CCircle::accept(IVisitor* visitor)
{
	visitor->visit(this);
}