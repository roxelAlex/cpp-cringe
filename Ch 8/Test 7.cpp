/*
Добавьте в следующую программу инициализацию нестатических членов и
список инициализации членов:
*/

#include <string>
#include <iostream>
 
class Thing
{
private:
    // Инициализация нестатических членов
	std::string m_color = "blue";
	double m_radius = 20.0;
 
public:
    // Конструктор по умолчанию без параметров
    // Тело конструктора оставляем пустым, потому что члены уже инициализированы
	Thing()
	{
	}
 
    // Конструктор с параметром color (для radius предоставлено значение по умолчанию)
	// Удаляем тело конструктора, добавляем список инициализации в следующих
    // трёх конструкторах.
    Thing(const std::string &color) : m_color(color)
	{
	}
 
    // Конструктор с параметром radius (для color предоставлено значение по умолчанию)
	Thing(double radius) : m_radius(radius)
	{		
	}
 
    // Конструктор с параметрами color и radius
	Thing(const std::string &color, double radius) :
        m_color(color),
        m_radius(radius)
	{
	}
 
	void print()
	{
		std::cout << "color: " << m_color << " and radius: " << m_radius << '\n';
	}
};
 
int main()
{
	Thing defl;
	defl.print();
 
	Thing red("red");
	red.print();
	
	Thing thirty(30.0);
	thirty.print();
	
	Thing redThirty("red", 30.0);
	redThirty.print();
 
	return 0;
}