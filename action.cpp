#include <iostream>
#include <cstdio>
#include "struct.h"

goods calculate(goods price) {
    goods result{0, 0, 0};

    bool end = false;
    char array[50];

    while (!end) {
        int total;
        std::cout << "Будь ласка, напишіть ціну та кількість товару через кому (наприклад, 19,89,3):";
        std::cin.getline(array, sizeof array);

        if (sscanf(array, "%d,%d,%d", &price.grn, &price.kop, &price.amount) != 3) {
            std::cout << "Дотримуйтесь інструкцій" << std::endl;
            continue;
        }
        total = (price.kop + price.grn * 100) * price.amount;
        result.grn += total / 100;
        result.kop += total % 100;

        int remainder;
        remainder = result.kop % 10;
        if (remainder >= 5)
            result.kop += (10 - remainder);
        else
            result.kop -= remainder;

        if (result.kop >= 100) {
            result.grn += result.kop / 100;
            result.kop %= 100;
        }

        std::cout << "Хочете продовжити?";
        char answer;
        std::cin >> answer;
        std::cin.ignore();
        if (answer == 'N' || answer == 'n') {
            end = true;
        }
    }
    std::cout << "Фінальна сума: " << result.grn << " грн " << result.kop << " коп\n";

    return result;
}
