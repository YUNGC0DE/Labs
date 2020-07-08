#include <iostream>
#include "int_list_t/int_list_t.h"

int main() {
    int_list_t list_1;
    for (int i = 0; i < 10; ++i) {
        list_1.push_back(i);
    }
    std::cout << list_1 << std::endl;
    int_list_t list_2 = list_1;
    list_2.push_back(12);
    list_2.push_front(11);
    std::cout << list_2.back() << std::endl;
    list_2.reverse();
    std::cout << list_2.front() << std::endl;
    list_2 = list_1.splice(3, 5);
    std::cout << list_2 << std::endl;
    return 0;
}