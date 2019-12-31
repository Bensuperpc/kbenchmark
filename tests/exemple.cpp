/*
** EPITECH PROJECT, 2019
** kbenchmark
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <sstream>

int error(void);
void redirect_all_stdout(void);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_gomoku, START_cmd_test)
{
    std::string expected = START_OK + static_cast<std::string>("\n9,9\nnone\n");
    ;
    gomoku gomoku_class;

    // Save old buff
    std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
    std::streambuf *oldCerrStreamBuf = std::cerr.rdbuf();
    std::streambuf *oldCinStreamBuf = std::cin.rdbuf();

    // Create buff
    std::ostringstream strCout;
    std::ostringstream strCerr;
    std::istringstream strCin("START 20\nBEGIN\nEND");

    // Redirect buff
    std::cout.rdbuf(strCout.rdbuf());
    std::cerr.rdbuf(strCerr.rdbuf());
    std::cin.rdbuf(strCin.rdbuf());

    int ret = gomoku_class.game();
    cr_assert_eq(ret, 1, "Result : %i, expected : %i", ret, 1);

    // Save in std::string
    std::string out = strCout.str();
    std::string err = strCerr.str();

    // Restore std::cout
    std::cout.rdbuf(oldCoutStreamBuf);
    std::cerr.rdbuf(oldCerrStreamBuf);
    std::cin.rdbuf(oldCinStreamBuf);
    cr_assert_str_eq(out.c_str(), expected.c_str(), "Result : %s, expected : %s", out.c_str(), expected.c_str());
}

Test(test_gomoku, END_cmd, .init = redirect_all_stdout)
{
    std::string message = "END";
    std::string expected = "none\n";
    gomoku gomoku_class;
    int ret = gomoku_class.game(message);
    cr_assert_eq(ret, 1, "Result : %i, expected : %i", ret, 1);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}
