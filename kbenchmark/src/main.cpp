#include <iostream>
#include "my_chrono.hpp"
#include "odd/odd.hpp"

int main()
{
    my_chrono chrono;
    char **str = new char *[10000];
    chrono.start();
    for (size_t i = 0; i < 10000; i++) {
        str[i] = new char[10];
    }
    chrono.stop();
    for (size_t i = 0; i < 10000; i++) {
        delete[] str[i];
    }
    delete[] str;
    std::cout << "new : Time :" << chrono.elapsed_ms() << " ns" << std::endl;

    char **strs = (char **)malloc(sizeof(char *) * 10000);
    chrono.reset();
    for (size_t i = 0; i < 10000; i++) {
        strs[i] = (char *)malloc(sizeof(char) * 10);
    }
    chrono.stop();
    for (size_t i = 0; i < 10000; i++) {
        free(strs[i]);
    }
    free(strs);
    std::cout << "malloc : Time :" << chrono.elapsed_ms() << " ns" << std::endl;
    return 0;
}