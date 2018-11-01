#pragma once
#include "polygon.h"
#include "regular_polygon.h"
const double pi = 3.141592;
class treangl:public regular_polygon
{
public:
	treangl() :regular_polygon(3) {};

	treangl(point *a) :regular_polygon(a, 3) {};
	point get_p1() const { return polygon::operator[](1);}
	point get_p2() const { return polygon::operator[](2);}
	point get_p3() const { return polygon::operator[](3);}
	void tipeTriangl();
	bool Convex() const override { return true; };

	friend std::istream &operator>>(std::istream &is, treangl &p)
	{
		is >> p[0] >> p[1] >> p[2];
		return is;
	}
	std::string print_to_file()
	{
		std::stringstream ss;
		ss << "T" << *this;
		std::string s;
		getline(ss, s);
		return s.erase(2,3);
	}
private:

};


class circle :public shape
{
private:
	point senter;
	double R;
public:
	circle(point senter, double R) :senter(senter), R(R) {};
	double P()const override { return 2 * pi*R; }
	double S()const override { return pi * R*R; }
	point center() const override { return senter; }
	bool Convex() const override { return true; }
};