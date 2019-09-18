// gmtest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

#include "TurtleImpl.hpp"
int main()
{
    std::cout << "Hello World!\n";

	std::unique_ptr<Turtle> turtle(TurtleImpl::Create());
	turtle->Forward(100);

	return 0;
}
