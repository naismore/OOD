#include "BorderDecorator.h"
#include "SimpleShapeFabric.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
BorderDecorator::BorderDecorator(std::shared_ptr<CShape>& shape, double thickness, sf::Color color) : CShapeDecorator(shape), m_color(color), m_thickness(thickness) {}

void BorderDecorator::draw(sf::RenderWindow& window)
{
	m_shape->draw(window);
	auto border = SimpleShapeFabric::createShapeBorder(m_shape, m_thickness, m_color);
	window.draw(*border);
}
