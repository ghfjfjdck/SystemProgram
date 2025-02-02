

#include <iostream>
#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
//Zadanie 1
#define t 2.0
#define z 3.0
#define y cos(t + z)
#define x (4 * pow(y, 3) - (z / t))
//Zadanie 2
#define X -4.52
#define Y 0.75
#define W (sqrt(pow(sin(abs(X)), 2) + Y))
#define Z W
#define F (exp(-2 * X) * (tan(Z) + 2 * Y))
#define b F

int main() {
    printf("Zadanie 1: %f\t\n", x);
    printf("Zadanie 2: %f\t\n",b);
   //Zadanie 3;
    double a = 2;
    double pi= 3.14159265358979323846;;
    double alpha = 0.5;
    double result = sin(pi / 2.0 + 3.0 * a) / 1.0 - sin(3.0 * alpha - pi);
    printf("Zadanie 3: %f\t\n",result);
    return 0;
}

