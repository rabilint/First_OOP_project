#include <iostream>
#include "struct.h"
#include <fstream>

Goods calculate() {
    Goods result{0, 0};

    Goods price{0, 0};
    int amount=1;
    int n =100;
    char* file = new char[n +1];
    std::ifstream inFile;
    inFile.open("/home/rabilint/CLionProjects/untitled/input.txt");

    if (!inFile || !inFile.is_open()) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile.getline(file,n,';')) {
        int total;

        if (sscanf(file, "%*[^,], %d грн %d коп, %d шт;", &price.grn, &price.kop, &amount) == 3) {
            total = (price.kop + price.grn * 100) * amount;
            result.grn += total / 100;
            result.kop += total % 100;
        }else {
            std::cout << "Помилка! Неправильний формат рядка:\n" << file << std::endl;
            std::cout << "Очікуваний формат: Назва, X грн Y коп, Z шт;\n";
            break;
        }
    }
    std::cout << "Фінальна сума без округлення: " << result.grn << " грн " << result.kop << " коп\n";
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
    std::cout << "Фінальна сума з округленням: " << result.grn << " грн " << result.kop << " коп\n";
    inFile.close();
    delete[] file;
    return result;
}
