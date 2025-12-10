#include "CShape.h"
#include <memory>

class IVisitor;
class CShapeDecorator : public CShape
{
public:
    CShapeDecorator(std::shared_ptr<CShape> shape);

    virtual void draw(sf::RenderWindow& window);
    virtual void accept(IVisitor* visitor);
    virtual double GetArea() const override;
    virtual double GetPerimeter() const override;
    virtual std::string ToString() const;


protected:
    std::shared_ptr<CShape> m_shape;
};