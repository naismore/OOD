#include "CShape.h"
#include <sstream>

CShape::CShape(std::string type) : m_type(type) {}

std::string CShape::ToString() const
{
    std::ostringstream strm;
    strm << m_type << ": "
         << "P=" << GetPerimeter() << "; "
         << "S=" << GetArea() << std::endl;
    return strm.str();
}

std::string CShape::GetType() const
{
    return m_type;
}