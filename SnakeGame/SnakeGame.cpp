#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <locale>


int speed = 150;
struct Snake {
    int x, y;        
    int cordEatX, cordEatY; // Координаты еды
    int Score = 0;   // Счет игры
    Snake* next;      // Указатель на следующий вагончик
    bool Eat = true; // Флаг "еда съедена"

    // Конструктор, для создания нового вагончика змейки
    Snake(int vx, int vy) : x(vx), y(vy), next(nullptr) {}

    // Метод для движения змейки
    void go(int goX, int goY) {
        int hX = x; 
        int hY = y;

        x += goX;  
        y += goY;

        Snake* cur = next; 
        while (cur != nullptr) {  
            int tempX = cur->x;   
            int tempY = cur->y;

            cur->x = hX;          
            cur->y = hY;

            hX = tempX;           
            hY = tempY;

            cur = cur->next;      
        }
    }

    // Метод для проверки, что змейка не врезалась
    bool CheckSnake(Snake* snake) {
        
        if (x < 0 || x >= 20 || y < 0 || y >= 20) {
            return true; 
        }

        Snake* cur = next; 
        while (cur != nullptr) { 
            if (cur->x == x && cur->y == y) {
                return true;    
            }
            cur = cur->next;
        }

        // Если змейка съела еду
        if (cordEatX == x && cordEatY == y) {
            cur = snake; 
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            
            cur->next = new Snake(cur->x, cur->y);
            Eat = true; 
            Score += 10; 
            if(speed>30)
            speed -= 10;
        }
        return false;
    }

    // Метод для рисования игрового поля
    void drawField() {
        char field[20][20] = {}; 

        
        if (Eat) {
            cordEatX = rand() % 19 + 1; 
            cordEatY = rand() % 19 + 1;
            Eat = false; 
        }

        // Заполняем игровое поле ( '.' - пустота)
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (j == cordEatX && i == cordEatY) {
                    field[i][j] = 'E';  
                }
                else {
                    field[i][j] = '_'; 
                }
            }
        }

        Snake* cur = this;   
        while (cur != nullptr) {   
            // Рисуем змейку на поле
            if (cur->x >= 0 && cur->x < 20 && cur->y >= 0 && cur->y < 20) {
                field[cur->y][cur->x] = ' ';
            }
            cur = cur->next;       
        }

        system("cls");       // Очищаем экран
        for (int i = 0; i < 20; ++i) { // Выводим поле
            for (int j = 0; j < 20; ++j) {
                std::cout << field[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

Snake* snake; // Указатель на голову змейки
int main() {
    srand(time(0)); 

    // Создаем начальную змейку 
    snake = new Snake(5, 5);
    snake->next = new Snake(5, 4);


    int goX = 0;    
    int goY = 1;   
    int lastGoX = goX; 
    int lastGoY = goY;

    while (true) { // Главный цикл игры
        // Проверяем нажатие клавиши
        if (_kbhit()) {
            int key = _getch();
            int newGoX = goX;   
            int newGoY = goY;  

           
            if (key == 72) {  
                newGoX = 0;
                newGoY = -1;
            }
            else if (key == 80) {
                newGoX = 0;
                newGoY = 1;
            }
            else if (key == 75) { 
                newGoX = -1;
                newGoY = 0;
            }
            else if (key == 77) {
                newGoX = 1;
                newGoY = 0;
            }
            // Если направление не обратное, запоминаем его
            if (newGoX != -lastGoX || newGoY != -lastGoY) {
                goX = newGoX;
                goY = newGoY;
            }
        }

        snake->go(goX, goY); // Двигаем змейку
        
        if (snake->CheckSnake(snake)) {
            std::cout << "Game Over!" << std::endl;  
            std::cout << "Score:" << snake->Score << std::endl; 
            break;
        }

        snake->drawField(); // Рисуем игровое поле
        lastGoX = goX;
        lastGoY = goY;   
        Sleep(speed);  
    }

    return 0; 
}