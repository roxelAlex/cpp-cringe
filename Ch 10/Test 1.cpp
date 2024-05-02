/*
Обновите вышеприведенный пример с Работником/Отделом так, чтобы Отдел мог
состоять из нескольких Работников.
*/

#include <iostream>
#include <vector>

// Класс Работник
class Worker
{
    private:
        std::string m_name; // Имя работника

    public:
        // Конструктор
        Worker(std::string name)
            : m_name(name)
            {

            }

        // Метод возврата имени работника
        std::string getName() const { return m_name; }
};
// Класс отдел
class Department
{
    private:
        std::vector<Worker*> m_worker;  // Вектор с работниками

    public:
        // Конструктор по умолчанию
        Department()
            {

            }

        // Метод, который вносит работников в вектор
        void add(Worker *w)
        {
            m_worker.push_back(w);
        }
        
        // Перегружаем оператор вывода
        friend std::ostream& operator<< (std::ostream &out, const Department &d)
        {
            out << "Department: ";

            for (auto ref : d.m_worker) // Проходимся циклом forech по вектору
            {
                out << ref->getName() << " ";   // Выводим каждое имя из вектора
            }

            out << "\n";
            
            return out;
        }
};

int main()
{
    // Создаем Работников вне области видимости класса Department
    Worker *w1 = new Worker("Anton");
    Worker *w2 = new Worker("Ivan");
    Worker *w3 = new Worker("Max");
 
    {
        // Создаем Отдел и передаем Работников в качестве параметров конструктора
        Department department; // содаем пустой Отдел
        department.add(w1);
        department.add(w2);
        department.add(w3);
 
        std::cout << department;
 
    } // department выходит из области видимости и уничтожается здесь
 
    std::cout << w1->getName() << " still exists!\n";
    std::cout << w2->getName() << " still exists!\n";
    std::cout << w3->getName() << " still exists!\n";
 
    delete w1;
    delete w2;
    delete w3;
 
    return 0;
}