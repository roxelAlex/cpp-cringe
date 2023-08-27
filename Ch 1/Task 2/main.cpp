/*
Измените программу из задания №1 так, чтобы функции readNumber() и writeAnswer() 
находились в отдельном файле io.cpp. 
Используйте предварительные объявления для доступа к этим функциям с функции main().
*/

int main()
{
    int x = readNumber();
    int y = readNumber();
    writeAnswer(x, y);
    return 0;
}