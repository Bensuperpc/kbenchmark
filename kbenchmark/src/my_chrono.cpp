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
    return (stop_time - start_time).count();
}

size_t my_chrono::elapsed_ms()
{
    return elapsed_ns() / 1000;
}

void my_chrono::reset()
{
    start_time = Clock::now();
}

void my_chrono::start()
{
    my_chrono::reset();
}

void my_chrono::stop()
{
    stop_time = Clock::now();
}

my_chrono::~my_chrono()
{
}
