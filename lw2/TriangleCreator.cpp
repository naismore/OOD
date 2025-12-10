#include "TriangleCreator.h"

TriangleCreator::TriangleCreator() {
    // Здесь можно добавить инициализацию, если это необходимо
}

TriangleCreator& TriangleCreator::getInstance() {
    static TriangleCreator instance; // Создание единственного экземпляра
    return instance;
}

std::shared_ptr<CTriangle> TriangleCreator::createTriangle(const CPoint& point1, const CPoint& point2, const CPoint& point3) {
    return std::make_shared<CTriangle>(point1, point2, point3); // Создание и возврат объекта CTriangle
}
