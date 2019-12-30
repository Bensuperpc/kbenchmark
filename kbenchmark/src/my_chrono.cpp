/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** my_chrono.c
*/

#include "my_chrono.hpp"

my_chrono::my_chrono()
{
}

size_t my_chrono::elapsed_ns()
{
    if( is_started == false)
        return -1;
    return (
        std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time))
        .count();
}

size_t my_chrono::elapsed_ms()
{
    if( is_started == false)
        return -1;
    return (std::chrono::duration_cast<std::chrono::nanoseconds>(
                stop_time - start_time))
               .count()
           / 1000000;
}

void my_chrono::reset()
{
    start_time = Clock::now();
    is_started = true;
}

void my_chrono::start()
{
    my_chrono::reset();
    is_started = true;
}

void my_chrono::stop()
{
    stop_time = Clock::now();
    is_started = false;
}

my_chrono::~my_chrono()
{
}
