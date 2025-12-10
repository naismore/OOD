#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class IVisitor;
class CShape
{
public:
	CShape(std::string type);
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	std::string ToString() const;
	virtual ~CShape() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void accept(IVisitor* visitor) = 0;
	std::string GetType() const;
	void Select();

private:
	bool m_selected = false;
	std::string m_type;
};
