#include "SimpleShapeFabric.h"
#include "Constants.h"
#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "TriangleCreator.h"

std::shared_ptr<CShape> SimpleShapeFabric::createShape(const std::string& type, const std::string& params)
{
    if (type == CIRCLE_TYPE)
    {
        CPoint central;
        double radius = 0;
        sscanf_s(params.c_str(), CIRCLE_STRING_TYPE.c_str(), &central.x, &central.y, &radius);
        CircleCreator& circleCreator = CircleCreator::getInstance();
        return circleCreator.createCircle(central, radius);
    }
    else if (type == TRIANGLE_TYPE)
    {
        CPoint p1, p2, p3;
        sscanf_s(params.c_str(), TRIANGLE_STRING_TYPE.c_str(), &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
        TriangleCreator& triangleCreator = TriangleCreator::getInstance();
        return triangleCreator.createTriangle(p1, p2, p3);
    }
    else if (type == RECTANGLE_TYPE)
    {
        CPoint p1, p2;
        sscanf_s(params.c_str(), RECTANGLE_STRING_TYPE.c_str(), &p1.x, &p1.y, &p2.x, &p2.y);
        RectangleCreator& rectangleCreator = RectangleCreator::getInstance();
        return rectangleCreator.createRectangle(p1, p2);
    }
    return nullptr;
}

std::shared_ptr<sf::Shape> SimpleShapeFabric::createShapeBorder(const std::shared_ptr<CShape>& shape, double thickness, sf::Color color)
{
    if (auto rectangle = dynamic_cast<CRectangle*>(shape.get())) {
        auto border = std::make_shared<sf::RectangleShape>(sf::Vector2f(rectangle->GetHeight(), rectangle->GetWidth()));
        border->setOutlineThickness(thickness);
        border->setOutlineColor(color);
        border->setFillColor(sf::Color::Transparent);
        border->setPosition(sf::Vector2f(rectangle->GetPoint1().x, rectangle->GetPoint1().y)); // Устанавливаем позицию рамки
        return border;

    }
    else if (auto circle = dynamic_cast<CCircle*>(shape.get())) {
        auto border = std::make_shared<sf::CircleShape>(circle->GetRadius());
        border->setOutlineThickness(thickness);
        border->setOutlineColor(color);
        border->setFillColor(sf::Color::Transparent);
        border->setPosition(sf::Vector2f(circle->GetCenterPoint().x, circle->GetCenterPoint().y)); // Устанавливаем позицию рамки
        return border;
    }
    else if (auto triangle = dynamic_cast<CTriangle*>(shape.get()))
    {

        auto border = std::make_shared<sf::ConvexShape>();
        border->setPointCount(3);
        border->setPoint(0, sf::Vector2f(triangle->GetPoint1().x, triangle->GetPoint1().y));
        border->setPoint(1, sf::Vector2f(triangle->GetPoint2().x, triangle->GetPoint2().y));
        border->setPoint(2, sf::Vector2f(triangle->GetPoint3().x, triangle->GetPoint3().y));
        border->setOutlineThickness(thickness);
        border->setOutlineColor(color);
        border->setFillColor(sf::Color::Transparent);
        return border;
    }
    return nullptr;
}


