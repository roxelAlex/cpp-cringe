/*
Создайте структуру, содержащую имя и оценку учащегося (по шкале от 0 до 100).
Спросите у пользователя, сколько учеников он хочет ввести.
Динамически выделите массив для хранения всех студентов.
Затем попросите пользователя ввести для каждого студента его имя и оценку.
Как только пользователь ввел все имена и оценки, отсортируйте список оценок
студентов по убыванию (сначала самый высокий бал).
Затем выведите все имена и оценки в отсортированном виде.
*/

#include <iostream>
#include <algorithm>

struct Student
{
    std::string name;
    int score;
};

void sortByScore(Student *array, int length)
{
    for (int startIndex = 0; startIndex < length; startIndex++)
    {
        int maxIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
        {
            if(array[currentIndex].score > array[maxIndex].score)
                maxIndex = currentIndex;
        }
        std::swap(array[startIndex], array[maxIndex]);
    }
}

int main()
{
    int numberOfStudents = 0;
    do
    {
        std::cout << "Enter the number of students: ";
        std::cin >> numberOfStudents;
    } while (numberOfStudents <= 1);
    
    Student* students = new Student[numberOfStudents];

    for (int index = 0; index < numberOfStudents; index++)
    {
        std::cout << "Student #" << index + 1 << " : ";
        std::cin >> students[index].name;
        std::cout << "Score of student #" << index + 1 << " : ";
        std::cin >> students[index].score;
    }

    sortByScore(students, numberOfStudents);

    for (int index = 0; index < numberOfStudents; index++)
    {
        std::cout << students[index].name << " got a grade of " << students[index].score << std::endl;
    }

    delete[] students;

    return 0;
}