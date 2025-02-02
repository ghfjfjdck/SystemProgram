// Prakt6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    else if (n < 0) {
        return 1.0 / power(x, abs(n));
    }
    else {
        return x * power(x, n - 1);
    }
}

int main()
{
    double x1 = 2.0;
    int n1 = 3;
    std::cout << x1 << "^" << n1 << " = " << power(x1, n1) << std::endl;   // Вывод: 8

    double x2 = 2.0;
    int n2 = -2;
    std::cout << x2 << "^" << n2 << " = " << power(x2, n2) << std::endl;   // Вывод: 0.25

    double x3 = 5.0;
    int n3 = 0;
    std::cout << x3 << "^" << n3 << " = " << power(x3, n3) << std::endl;   // Вывод: 1

    return 0;
}


