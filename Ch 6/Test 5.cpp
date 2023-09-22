/*
Измените следующую программу так, чтобы вместо maxScore с наибольшим
значением, переменная maxIndex содержала индекс элемента с наибольшим
значением:

#include <iostream>
 
int main()
{
    int scores[] = { 73, 85, 84, 44, 78 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);
 
    int maxScore = 0; // отслеживаем самую высокую оценку
    for (int student = 0; student < numStudents; ++student)
        if (scores[student] > maxScore)
            maxScore = scores[student];
 
    std::cout << "The best score was " << maxScore << '\n';
 
    return 0;
}
*/

#include <iostream>

int main()
{
    int scores[] = { 73, 85, 84, 44, 78 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);

    int maxIndex = 0;

    for (int student = 0; student < numStudents; student++)
        if (scores[student] > scores[maxIndex])
        {
            maxIndex = student;
        }
    std::cout << "The best score belong to index: " << maxIndex << " and have " << scores[maxIndex] << std::endl;
    return 0;
}