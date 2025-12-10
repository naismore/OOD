#include "ShapeVisitor.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

ShapeVisitor::ShapeVisitor(std::string filename) : outFile(filename) {}

void ShapeVisitor::visit(CCircle* circle) {
    std::string circleToString = circle->ToString();
    outFile << circle->ToString() << "\n";
}

void ShapeVisitor::visit(CRectangle* rectangle) {
    std::string rectangleToString = rectangle->ToString();
    outFile << rectangleToString << "\n";
}

void ShapeVisitor::visit(CTriangle* triangle) {
    std::string triangleToString = triangle->ToString();
    outFile << triangleToString << "\n";
}