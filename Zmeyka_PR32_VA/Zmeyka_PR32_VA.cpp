#include <iostream>
#include <conio.h>
#include <windows.h>

const int width = 40;
const int height = 20;

class Snake {
public:
    void Draw(int head, int heady) {
        for (int i = 0; i < width; i++) {
            std::cout << "#";
        }
        std::cout << std::endl;
        for (int x = 1; x < height - 1; x++) {
            std::cout << "#";
            for (int y = 1; y < width - 1; y++) {
                if (y == head && x == heady) {
                    std::cout << "o";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << "#" << std::endl;
        }
        for (int i = 0; i < width; i++) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(0, "rus");
    Snake a;
    int head = width / 2;
    int heady = height / 2;
    int direction = 0;

    std::cout << "Добро пожаловать в Змейку\n";
    std::cout << "Управление: W-Вверх, A-Влево, S-Вниз, D-Вправо\n";

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'w' || key == 'W') direction = 0;
            else if (key == 'd' || key == 'D') direction = 1; 
            else if (key == 's' || key == 'S') direction = 2; 
            else if (key == 'a' || key == 'A') direction = 3; 
        }

        if (direction == 0) heady--;
        else if (direction == 1) head++; 
        else if (direction == 2) heady++; 
        else if (direction == 3) head--; 

        if (head < 1 || head >= width - 1 || heady < 1 || heady >= height - 1) {
            std::cout << "Игра окончена! Вы вышли за границы поля." << std::endl;
            break; 
        }
        system("cls");
        a.Draw(head, heady);
        Sleep(100); 
    }
    return 0;
}
