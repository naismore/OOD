#pragma once
#include <memory>
#include "CTriangle.h"
#include "CPoint.cpp" // Убедитесь, что вы включаете только заголовочный файл

class TriangleCreator {
public:
    static TriangleCreator& getInstance(); // Метод для получения экземпляра синглтона
    std::shared_ptr<CTriangle> createTriangle(const CPoint& point1, const CPoint& point2, const CPoint& point3); // Метод для создания треугольника

private:
    TriangleCreator(); // Приватный конструктор
    TriangleCreator(const TriangleCreator&) = delete; // Запрет копирования
    TriangleCreator& operator=(const TriangleCreator&) = delete; // Запрет присваивания
};
