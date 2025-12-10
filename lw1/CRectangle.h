#pragma once
#include "CShape.h"
#include "CPoint.cpp"

class CRectangle : public CShape
{
public:
	CRectangle(CPoint &point1, CPoint &point2);
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetPoint1() const;
	CPoint GetPoint2() const;
	int GetWidth() const;
	int GetHeight() const;
	sf::RectangleShape GetRectangle() const;

	void draw(sf::RenderWindow& window) override;

private:
	sf::RectangleShape m_rectangle;
	CPoint m_point1;
	CPoint m_point2;
};
