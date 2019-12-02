/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** my_chrono.c
*/

#include "functions/my_chrono.hpp"

my_chrono::my_chrono()
{
}

size_t my_chrono::elapsed_ns()
{
    return (
        std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - start_time))
        .count();
}

size_t my_chrono::elapsed_ms()
{
    return (std::chrono::duration_cast<std::chrono::nanoseconds>(
                Clock::now() - start_time))
               .count()
           / 1000000;
}

void my_chrono::reset()
{
    start_time = Clock::now();
}

my_chrono::~my_chrono()
{
}