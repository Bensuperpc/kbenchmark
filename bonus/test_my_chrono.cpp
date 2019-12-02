/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions/my_chrono.hpp"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32


Test(my_chrono_tests, simple_1) {
        unsigned int delay = 100;
        my_chrono chrono_time;
        #ifdef _WIN32
        Sleep(delay);
        #else
        usleep(delay * 1000);
        #endif // _WIN32
        cr_assert_geq(chrono_time.elapsed_ns(), delay * 1000, "The result was %i. Expected %i", chrono_time.elapsed_ns(), delay * 1000);
}

Test(my_chrono_tests, simple_2) {
        unsigned int delay = 10;
        my_chrono chrono_time;
        #ifdef _WIN32
        Sleep(delay);
        #else
        usleep(delay * 1000);
        #endif // _WIN32
        cr_assert_geq(chrono_time.elapsed_ms(), delay, "The result was %i. Expected %i", chrono_time.elapsed_ms(), delay);
}

Test(my_chrono_tests, reset_1) {
        my_chrono chrono_time;
        chrono_time.reset();
        cr_assert_geq(chrono_time.elapsed_ms(), 0, "The result was %i. Expected %i", chrono_time.elapsed_ms(), 0);
        chrono_time.reset();
        cr_assert_geq(chrono_time.elapsed_ms(), 0, "The result was %i. Expected %i", chrono_time.elapsed_ms(), 0);
        chrono_time.reset();
        cr_assert_geq(chrono_time.elapsed_ms(), 0, "The result was %i. Expected %i", chrono_time.elapsed_ms(), 0);
}