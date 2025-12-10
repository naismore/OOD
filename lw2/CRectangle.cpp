#include "CRectangle.h"
#include "IVisitor.h"

int CRectangle::GetHeight() const
{
    return m_point2.y - m_point1.y;
}

sf::RectangleShape CRectangle::GetRectangle() const
{
    return m_rectangle;
}

int CRectangle::GetWidth() const
{
    return m_point2.x - m_point1.x;
}

CRectangle::CRectangle(const CPoint &point1, const CPoint &point2)
    : CShape("RECTANGLE"), m_point1(point1), m_point2(point2)
{
    m_rectangle.setSize(sf::Vector2f(GetWidth(), GetHeight()));
    m_rectangle.setFillColor(sf::Color::Blue);
}

double CRectangle::GetArea() const
{
    return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
    return (GetWidth() + GetHeight()) * 2;
}

CPoint CRectangle::GetPoint1() const
{
    return m_point1;
}

CPoint CRectangle::GetPoint2() const
{
    return m_point2;
}

void CRectangle::draw(sf::RenderWindow& window)
{
    m_rectangle.setPosition(sf::Vector2f(m_point1.x, m_point1.y));
    window.draw(m_rectangle);
}

void CRectangle::accept(IVisitor* visitor)
{
    visitor->visit(this);
}