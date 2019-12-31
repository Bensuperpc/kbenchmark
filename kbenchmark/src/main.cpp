#include <iostream>
#include "my_chrono.hpp"
#include "odd/odd.hpp"

int main()
{
    const size_t tapsize = 1000;
    const size_t allocsize = 2;
    const size_t iternum = 10000;

    double result_malloc = 0.0;
    double result_new = 0.0;

    my_chrono chrono;
    char **strs = (char **)malloc(sizeof(char *) * tapsize);
    char **str = new char *[tapsize];
    for (size_t j = 0; j < iternum; j++) {
        chrono.start();
        for (size_t i = 0; i < tapsize; i++) {
            str[i] = new char[allocsize];
        }
        chrono.stop();
        for (size_t i = 0; i < tapsize; i++) {
            delete[] str[i];
        }
        result_new = result_new + (tapsize * allocsize) / (chrono.elapsed_ns() / 100000000.0) / iternum;
        chrono.start();
        for (size_t i = 0; i < tapsize; i++) {
            strs[i] = (char *)malloc(sizeof(char) * allocsize);
        }
        chrono.stop();
        for (size_t i = 0; i < tapsize; i++) {
            free(strs[i]);
        }
        result_malloc = result_malloc + (tapsize * allocsize) / (chrono.elapsed_ns() / 100000000.0) / iternum;
    }
    free(strs);
    delete[] str;
    std::cout << "malloc :" << std::fixed << result_malloc / 1000000.0 << " Mo/sec" << std::endl;
    std::cout << "new :" << std::fixed << result_new / 1000000.0 << " Mo/sec" << std::endl;
    return 0;
}