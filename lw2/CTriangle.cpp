#include "CTriangle.h"
#include <cmath>
#include <iostream>
#include "IVisitor.h"

CTriangle::CTriangle(const CPoint &point1, const CPoint &point2, const CPoint &point3)
    : CShape("TRIANGLE"), m_point1(point1), m_point2(point2), m_point3(point3) {
    m_triangle.setPointCount(3);
    m_triangle.setPoint(0, sf::Vector2f(m_point1.x, m_point1.y));
    m_triangle.setPoint(1, sf::Vector2f(m_point2.x, m_point2.y));
    m_triangle.setPoint(2, sf::Vector2f(m_point3.x, m_point3.y));
    m_triangle.setFillColor(sf::Color::White);
    m_triangle.setOutlineColor(sf::Color::White);

    std::cout << "Triangle points set to: "

        << m_point1.x << "," << m_point1.y << " "

        << m_point2.x << "," << m_point2.y << " "

        << m_point3.x << "," << m_point3.y << std::endl;
}

double CTriangle::GetPerimeter() const
{
    double a = std::sqrt(std::pow(m_point2.x - m_point1.x, 2) + std::pow(m_point2.y - m_point1.y, 2));
    double b = std::sqrt(std::pow(m_point3.x - m_point2.x, 2) + std::pow(m_point3.y - m_point2.y, 2));
    double c = std::sqrt(std::pow(m_point1.x - m_point3.x, 2) + std::pow(m_point1.y - m_point3.y, 2));
    return a + b + c;
}

double CTriangle::GetArea() const
{
    double a = std::sqrt(std::pow(m_point2.x - m_point1.x, 2) + std::pow(m_point2.y - m_point1.y, 2));
    double b = std::sqrt(std::pow(m_point3.x - m_point2.x, 2) + std::pow(m_point3.y - m_point2.y, 2));
    double c = std::sqrt(std::pow(m_point1.x - m_point3.x, 2) + std::pow(m_point1.y - m_point3.y, 2));

    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c)); // Площадь по формуле Герона
};

CPoint CTriangle::GetPoint1() const
{
    return m_point1;
}

CPoint CTriangle::GetPoint2() const
{
    return m_point2;
}

CPoint CTriangle::GetPoint3() const
{
    return m_point3;
}

void CTriangle::draw(sf::RenderWindow& window)
{
    window.draw(m_triangle);
}

void CTriangle::accept(IVisitor* visitor)
{
    visitor->visit(this);
}