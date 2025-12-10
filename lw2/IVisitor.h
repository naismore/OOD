#pragma once

class CRectangle;
class CTriangle;
class CCircle;
class IVisitor
{
public:
	virtual void visit(CCircle* circle) = 0;
	virtual void visit(CRectangle* rectangle) = 0;
	virtual void visit(CTriangle* triangle) = 0;
};

