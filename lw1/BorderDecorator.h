#include "CShapeDecorator.h"

class BorderDecorator : public CShapeDecorator
{

public:
    BorderDecorator(std::shared_ptr<CShape>& shape, double thickness, sf::Color color);
    void draw(sf::RenderWindow& window);

private:
    sf::Color m_color;
    double m_thickness;
};