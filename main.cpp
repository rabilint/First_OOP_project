#include <iostream>
#include "action.cpp"
#include "struct.h"

int main() {
   goods price{0, 0, 0};
   goods result = calculate(price);

   std::cout << "Фінальна сума: " << result.grn << " грн " << result.kop << " коп\n";
   return 0;
}
