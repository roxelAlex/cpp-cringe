/*
Используя следующий прототип функции:
int editData();
Преобразуйте тип возвращаемого значения int в status_t,
используя ключевое слово typedef.
В ответе к этому заданию укажите стейтмент typedef и обновленный
прототип функции.
*/

typedef int status_t;
status_t editData();

/*
Используя прототип функции из задания №1, преобразуйте тип
возвращаемого значения int в status_t, используя ключевое слово using (C++11).
В ответе к этому заданию укажите стейтмент создания псевдонима типа и
обновленный прототип функции.
*/

using status_t = int;
status_t editData();