#pragma once
#include <memory>
#include "CRectangle.h"
#include "CPoint.cpp" // Убедитесь, что вы включаете только заголовочный файл

class RectangleCreator {
public:
    static RectangleCreator& getInstance(); // Метод для получения экземпляра синглтона
    std::shared_ptr<CRectangle> createRectangle(const CPoint& point1, const CPoint& point2); // Метод для создания прямоугольника

private:
    RectangleCreator(); // Приватный конструктор
    RectangleCreator(const RectangleCreator&) = delete; // Запрет копирования
    RectangleCreator& operator=(const RectangleCreator&) = delete; // Запрет присваивания
};
