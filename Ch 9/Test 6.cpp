#include <iostream>
#include <vector>
#include <string>

struct StudentGrade
{
    std::string studentName; // Имя стундента
    char studentGrade; // Оценка студента
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map; // Контейнер map, для хранения оценок учеников

public:
    // Конструктор по умолчанию
    GradeMap()
    {

    }

    // Перегужаем оператор индекса для поиска и вывода оценки студента
    // или для добавления нового в контейнер
    char& operator[] (const std::string& name)
    {
        for (auto& ref : m_map) // Проходимся по всему вектору
        {
            if (ref.studentName == name) // Если нашли совпадение
                return ref.studentGrade; // возвращаем оценку
        }

        StudentGrade temp{ name, ' ' }; 

        m_map.push_back(temp); // Если не нашли, то добавляем новый элемент

        return m_map.back().studentGrade; // И присваиваем оценку
    }
};

int main()
{
    GradeMap grades;
    grades["John"] = 'A';
    grades["Martin"] = 'B';
    std::cout << "John has a grade of " << grades["John"] << std::endl;
    std::cout << "Martin has a grade of " << grades["Martin"] << std::endl;

    return 0;
}