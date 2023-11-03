/*
c) Переделайте свой ответ из задания b, используя 5 отдельных файлов:
Point3D.h, Point3D.cpp, Vector3D.h, Vector3D.cpp и main.cpp.
*/

#include "Point3D.h"
#include "Vector3D.h"
 
int main()
{
	Point3D p(3.0, 4.0, 5.0);
	Vector3D v(3.0, 3.0, -2.0);
 
	p.print();
	p.moveByVector(v);
	p.print();
 
	return 0;
}