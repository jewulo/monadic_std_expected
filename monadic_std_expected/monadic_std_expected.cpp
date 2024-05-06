// monadic_std_expected.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://www.cppstories.com/2024/expected-cpp23-monadic/

#include <iostream>

#include "and_then_1.h"
#include "and_then_2.h"
#include "or_else.h"
#include "transform.h"
#include "transform_error.h"
#include "wrap_up.h"

int main()
{
    and_then_1::run();
    and_then_2::if_else::run();
    and_then_2::monadic::run();

    transform::ex1::run();
    transform::ex2::run();

    or_else::run_1();
    or_else::run_2();
    or_else::run_3();

    transform_error::run();

    wrap_up::run("2024-04-28"); // This is a Saturday
    wrap_up::run("2024-04-30");	// This is a Monday
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
