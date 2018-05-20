#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

#include "rgb.hpp"

template<typename Function>
void animate(Picture pic, Function f, 
	double fromX, double toX, int stepsX, 
	double fromY, double toY, 
	double fromT, double toT, int stepsT, 
	RGB background, RGB foreground) {
	double stepT = (toT - fromT)/stepsT;
	for (double t=fromT; t<=toT; t+=stepT) {
		pic.setBackground(background);
		auto f_t = [f=f,t=t](double x){return f(x,t);};
		pic.plot(f_t, fromX, toX, stepsX, fromY, toY, foreground);
		pic.toFile("func.ppm");
	    this_thread::sleep_for(chrono::milliseconds(200));
	}
}

int main() {
	Picture pic(300,300);
	auto f = [](double x, double t){return std::sin(x*t);};
	animate(pic, f, -4.0,4.0,1200,  -1.1,1.1, 0,1,100, {255,255,0}, {0,0,255});
	return 0;
}
