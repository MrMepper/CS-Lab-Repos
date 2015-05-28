#include "Color.h"
#include <iostream>
#include "graph1.h"

using namespace std;

Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}
Color::Color(int r, int g, int b)
{
	this -> r = r;
	this -> g = g;
	this -> b = b;
}
void Color::setColor(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	if(b > 255)
		b = 255;
	if (g>255)
		g = 255;
	if (r < 0)
		r = 0;
	if (b < 0)
		b = 0;
	if (g < 0)
		g = 0;

	this -> r = r;
	this -> g = g;
	this -> b = b;
}
int Color::getRed()
{
	return r;
}
int Color::getGreen()
{
	return g;
}
int Color::getBlue()
{
	return b;
}
Color Color::operator+(Color right)
{
	Color result;

	result.r = r + right.r;
	result.b = b + right.b;
	result.g = g + right.g;

	if(result.r > 255)
		result.r = 255;
	if(result.b > 255)
		result.b = 255;
	if(result.g > 255)
		result.g = 255;
	if(result.r < 0)
		result.r = 0;
	if(result.b < 0)
		result.b = 0;
	if(result.g < 0)
		result.g = 0;

	return (result);
}
Color Color::operator-(Color right)
{
	Color result;

	result.r = r - right.r;
	result.b = b - right.b;
	result.g = g - right.g;

	if(result.r > 255)
		result.r = 255;
	if(result.b > 255)
		result.b = 255;
	if(result.g > 255)
		result.g = 255;
	if(result.r < 0)
		result.r = 0;
	if(result.b < 0)
		result.b = 0;
	if(result.g < 0)
		result.g = 0;

	return result;
}
Color Color::operator/(int right)
{
	Color result;

	result.r = r/right;
	result.b = b/right;
	result.g = g/right;

	if(result.r > 255)
		result.r = 255;
	if(result.g > 255)
		result.g = 255;
	if(result.b > 255)
		result.b = 255;
	if(result.b < 0)
		result.b = 0;
	if(result.g < 0)
		result.g = 0;
	if(result.r < 0)
		result.r = 0;

	return result;
}
Color Color::operator*(int right)
{
	Color result;

	result.r = r*right;
	result.b = b*right;
	result.g = g*right;

	if(result.r > 255)
		result.r = 255;
	if(result.g > 255)
		result.g = 255;
	if(result.b > 255)
		result.b = 255;
	if(result.b < 0)
		result.b = 0;
	if(result.g < 0)
		result.g = 0;
	if(result.r < 0)
		result.r = 0;

	return result;
}
bool Color::operator==(Color right)
{
	if(r == right.r && g == right.g && b == right.b)
	{
		return true;
	}
	else
		return false;
}
bool Color::operator!=(Color right)
{
	if(r == right.r && g == right.g && b == right.b)
	{
		return false;
	}
	else
		return true;
}
void Color::operator=(Color right)
{
	this->r = right.r;
	this->g = right.g;
	this->b = right.b;
}
Color Color::operator!()
{
	Color result;

	result.r = 255 - r;
	result.g = 255 - g;
	result.b = 255 - b;

	return result;
}
Color Color::operator++()
{
	Color result;

	result.r = r + 25;
	result.g = g + 25;
	result.b = b + 25;

	if(result.r > 255)
		result.r = 255;
	if(result.g > 255)
		result.r = 255;
	if(result.b > 255)
		result.r = 255;

	return result;
}
Color Color::operator++(int dummy)
{
	Color result = (*this);
	result.r = r + 25;
	result.g = g + 25;
	result.b = b + 25;

	if(result.r > 255)
		result.r = 255;
	if(result.g > 255)
		result.r = 255;
	if(result.b > 255)
		result.r = 255;
	
	return result;
}
Color Color::operator--()
{
	Color result;

	result.r = r - 25;
	result.g = g - 25;
	result.b = b - 25;

	if(result.r < 0)
		result.r = 0;
	if(result.g < 0)
		result.r = 0;
	if(result.b < 0)
		result.r = 0;

	return result;
}
Color Color::operator--(int dummy)
{
	Color result = (*this);
	result.r = r - 25;
	result.g = g - 25;
	result.b = b - 25;

	if(result.r < 0)
		result.r = 0;
	if(result.g < 0)
		result.r = 0;
	if(result.b < 0)
		result.r = 0;

	return result;
}
bool Color::operator<(Color right)
{
	double mag_left;
	double mag_right;

	mag_right = sqrt(pow((double)right.r, 2) + pow((double)right.g, 2) + pow((double)right.b, 2));
	mag_left = sqrt(pow((double)r, 2) + pow((double)g, 2) + pow((double)b, 2));

	if(mag_left < mag_right)
		return true;
	else
		return false;
}
bool Color::operator>(Color right)
{
	double mag_left;
	double mag_right;

	mag_right = sqrt(pow((double)right.r, 2) + pow((double)right.g, 2) + pow((double)right.b, 2));
	mag_left = sqrt(pow((double)r, 2) + pow((double)g, 2) + pow((double)b, 2));

	if(mag_left > mag_right)
		return true;
	else
		return false;
}
void Color::draw(int x, int y, int w, int h)
{
	int rect;

	rect = drawRect(x,y,w,h);
	::setColor(rect, r, g, b);
}