#include "ShapeObserver.h"

ShapeObserver::ShapeObserver(const std::string& filename) : outFile(filename) {};
void ShapeObserver::update(const std::string& message)
{
	if (outFile.is_open()) {
		outFile << message << std::endl;
	}// Записываем сообщение в файл
}
