/*
Теперь обновите ваш код из предыдущего задания с использованием конструкторов
с параметрами по умолчанию. Постарайтесь использовать как можно меньше
конструкторов.
*/

#include <iostream>

class Ball
{
    private:
        std::string m_color;
        float m_radius;

    public:
        Ball(std::string color = "red", float radius = 20.0)
        {
            m_color = color;
            m_radius = radius;
        }
        Ball(float radius)
        {
            m_color = "red";
            m_radius = radius;
        }
        void print()
        {
            std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
        }
};

int main()
{
    Ball def;
    def.print();

    Ball black("black");
    black.print();

    Ball thirty(30.0);
    thirty.print();

    Ball blackThirty ("black", 30.0);
    blackThirty.print();

    return 0;
}