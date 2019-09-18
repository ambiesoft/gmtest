#include <iostream>
#include "Turtle.h"

class TurtleImpl : public Turtle
{
public:
	virtual ~TurtleImpl() {}
	virtual void PenUp() {
		std::cout << __FUNCTION__ << std::endl;
	}
	virtual void PenDown() {
		std::cout << __FUNCTION__ << std::endl;
	}
	virtual void Forward(int distance) {
		std::cout << __FUNCTION__ << std::endl;
	}
	virtual void Turn(int degrees) {
		std::cout << __FUNCTION__ << std::endl;
	}
	virtual void GoTo(int x, int y) {
		std::cout << __FUNCTION__ << std::endl;
	}
	virtual int GetX() const {
		std::cout << __FUNCTION__ << std::endl;
		return 100;
	}
	virtual int GetY() const {
		std::cout << __FUNCTION__ << std::endl;
		return 200;
	}
	static TurtleImpl* Create() {
		return new TurtleImpl();
	}
};