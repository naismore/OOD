#pragma once
#include "IVisitor.h"
#include "fstream"

class ShapeVisitor : public IVisitor
{
public:
	ShapeVisitor(std::string filename);
	void visit(CCircle* circle) override;
	void visit(CRectangle* rectangle) override;
	void visit(CTriangle* triangle) override;
private:
	std::ofstream outFile;
};

