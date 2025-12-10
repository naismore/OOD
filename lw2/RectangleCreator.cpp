#include "RectangleCreator.h"

RectangleCreator& RectangleCreator::getInstance() {
    static RectangleCreator instance; // Создание единственного экземпляра
    return instance;
}

std::shared_ptr<CRectangle> RectangleCreator::createRectangle(const CPoint& point1, const CPoint& point2) {
    return std::make_shared<CRectangle>(point1, point2); // Создание и возврат объекта CRectangle
}

RectangleCreator::RectangleCreator()
{

}
