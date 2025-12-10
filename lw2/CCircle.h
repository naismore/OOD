#pragma once
#include "CShape.h"
#include "CPoint.cpp"

class IVisitor;
class CCircle : public CShape
{
public:
	CCircle(const CPoint &center, double &radius);
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetCenterPoint() const;
	double GetRadius() const;
	void accept(IVisitor* visitor) override;
	void draw(sf::RenderWindow& window) override;

private:
	sf::CircleShape m_circle;
	CPoint m_center;
	double m_radius;
};
