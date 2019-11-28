#include <iostream>
#include "cl_application.h"
int main()
{
	cl_application ob_application;
	
	ob_application.bild_tree_objects(); // Построение дерева
	
	ob_application.exec_app(); // Запуск программы (системы)
	
	return 0;
}
