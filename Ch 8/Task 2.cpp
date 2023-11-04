/*Напишите деструктор для следующего класса:*/

#include <iostream>
 
class Welcome
{
private:
	char *m_data;
 
public:
	Welcome()
	{
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}
    // Деструктор
	~Welcome()
	{
        // Мда, проще задания не придумаешь. Просто освобождаем динамически
        // выделенную память для массива.
        delete[] m_data;
	}
 
	void print() const
	{
		std::cout << m_data;
	}
 
};
 
int main()
{
	Welcome hello;
	hello.print();
 
    return 0;
}