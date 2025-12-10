#pragma once
#include "CShape.h"
#include "CPoint.cpp"

class IVisitor;
class CTriangle : public CShape
{
public:
	CTriangle(const CPoint &point1, const CPoint &point2, const CPoint &point3);
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetPoint1() const;
	CPoint GetPoint2() const;
	CPoint GetPoint3() const;

	void accept(IVisitor* visitor) override;

	void draw(sf::RenderWindow& window) override;

private:
	sf::ConvexShape m_triangle;
	CPoint m_point1;
	CPoint m_point2;
	CPoint m_point3;
};
