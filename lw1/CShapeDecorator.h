#include "CShape.h"
#include <memory>

class CShapeDecorator : public CShape
{
public:
    CShapeDecorator(std::shared_ptr<CShape> shape);

    virtual void draw(sf::RenderWindow& window);

    virtual double GetArea() const override;
    virtual double GetPerimeter() const override;
    virtual std::string ToString() const;


protected:
    std::shared_ptr<CShape> m_shape;
};