#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "SimpleShapeFabric.h"
#include "CTriangle.h"
#include "BorderDecorator.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "Constants.h"
#include "CPoint.cpp"
#include <SFML/Graphics.hpp>
#include <memory>


std::vector<std::shared_ptr<CShape>> ImportShapes()
{
    std::ifstream in(INPUT_FILE);
    std::string line;
    std::vector<std::shared_ptr<CShape>> shapes;

    while (getline(in, line))
    {
        std::istringstream iss(line);
        std::string type;
        std::getline(iss, type, ':');
        std::string params = line.substr(type.length() + 1);

        auto shape = SimpleShapeFabric::createShape(type.substr(0, type.find(':')), params);
        if (shape)
        {
            shapes.push_back(shape);
        }
    }
    return shapes;
}

void OutputShapes(const std::vector<std::shared_ptr<CShape>>& shapes)
{
    std::ofstream out(OUTPUT_FILE);
    for (const auto& shape : shapes)
    {
        out << shape->ToString();
    }
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    auto shapes = ImportShapes();
    
    shapes[0] = std::make_shared<BorderDecorator>(shapes[0], 2, sf::Color::Red);
    shapes[1] = std::make_shared<BorderDecorator>(shapes[1], 2, sf::Color::Red);
    shapes[2] = std::make_shared<BorderDecorator>(shapes[2], 2, sf::Color::Red);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto& shape : shapes)
        {
            shape->draw(window);
        }

        window.display();
    }

    OutputShapes(shapes);
}
