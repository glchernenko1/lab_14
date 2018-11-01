#pragma once

#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
class  polygon;
class  polygon;
const double precision = 1E-10;
class point
{
private:
	double x, y;
public:
	point();
	point(double x, double y);
	point(const point &p);
	~point();

	double get_x() const;
	double get_y() const;

	void set_x(double x);
	void set_y(double y);



	double distance_to(const point &target) const;

	friend class polygon;
	friend std::istream &operator>>(std::istream &is, point &p);
};

bool operator==(const point &p1, const point &p2);
bool operator!=(const point &p1, const point &p2);

std::ostream &operator<<(std::ostream &os, const point &p);

point get_point();
void print(const point &p);







class shape
{
public:
	virtual double P()const = 0 {};
	virtual double S()const = 0 {};
	virtual bool Convex() const = 0 {};
	virtual point center() const = 0 {};
};











class  polygon: public shape
{
protected:
	point  *peak;
	int sz;


public:
	polygon(int n = 3) :sz(n)
	{
		point a;
		peak = new point[sz];
		for (int i = 0; i < sz; ++i) peak[i] = a;
	}
	polygon(point  *p, int n) :sz(n)
	{
		peak = new point[sz];
		for (int i = 0; i < sz; ++i) peak[i] = p[i];
	}
	polygon(const polygon &a)
	{
		sz = a.sz;
		peak = new point[sz];
		for (int i = 0; i < sz; ++i)
			peak[i] = a.peak[i];
	}
	polygon & operator = (const polygon &a)
	{
		if (this != &a)
		{
			delete[]peak;
			sz = a.sz;
			peak = new point[sz];
			for (int i = 0; i < sz; ++i)
				peak[i] = a.peak[i];
		}
		return *this;
	}
	~polygon() { delete[] peak; }
	 point center() const
	{
		double x = 0, y = 0;
		for (int i = 0; i < sz; ++i)
		{
			x += peak[i].get_x();
			y += peak[i].get_y();
		}
		return point(x / sz, y / sz);
	}

	 bool Convex() const
	{
		int i, j, k;
		int flag = 0;
		double z;
		if (sz < 3)
			return(false);
		for (i = 0; i < sz; i++)
		{
			j = (i + 1) % sz;
			k = (i + 2) % sz;
			z = (peak[j].x - peak[i].x) * (peak[k].y - peak[j].y);
			z -= (peak[j].y - peak[i].y) * (peak[k].x - peak[j].x);
			if (z < 0)
				flag |= 1;
			else if (z > 0)
				flag |= 2;
			if (flag == 3)
				return(false);
		}
		if (flag != 0)
			return(true);
		else
			return(0);
	};


	  double P() const
	{
		double p = 0;
		for (int i = 0; i < sz - 1; ++i)
			p += peak[i].distance_to(peak[i + 1]);
		return p += peak[0].distance_to(peak[sz - 1]);
	}
	 double S() const
	{
		double s = 0;
		for (int i = 0; i < sz - 1; ++i)
		{

			s += peak[i].x*peak[i + 1].y;
			s -= peak[i + 1].x*peak[i].y;

		}
		return abs(s + peak[sz - 1].x*peak[0].y - peak[0].x*peak[sz - 1].y) / 2;
	}

	virtual std::string print_to_file()
	{
		std::stringstream ss;
		ss << "N" << *this;
		std::string s;
		getline(ss, s);
		return s;
	}


	bool operator ==(polygon a);

	bool operator !=(polygon a);


	point operator [](int i) const { return peak[i]; }
	point & operator [] (int i) { return peak[i]; }

	friend std::ostream & operator<<(std::ostream & os, const polygon & p);
	friend std::istream &operator>>(std::istream &is, polygon &p);
};


class circled : public polygon
{
public:
	circled(int n = 3) : polygon(n) {};
	circled(point *p, int n) :polygon(p, n) {};
	circled(circled &a) : polygon(a) {};
	virtual circled & operator = (const circled &a)
	{
		if (this != &a)
		{
			delete[]peak;
			sz = a.sz;
			peak = new point[sz];
			for (int i = 0; i < sz; ++i)
				peak[i] = a.peak[i];
		}
		return *this;
	}
	virtual double R() const =0 ;
	virtual double r() const =0;
private:

};
