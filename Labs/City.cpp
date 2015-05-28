#include "City.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "graph1.h"

using namespace std;

City::City(void)
{
	name = NULL;
	highway = NULL;
    elevation = 0;
	location.setPoint(0, 0);
}


City::~City(void)
{
	delete[] name;
	delete[] highway;
}

void City::setData(char* fn)
{
	int rand_no = 0;
	int word_count = 0;
	char word[1000];
	int x;
	int y;
	char highway[500];
	int elevation;

	srand(time(0));

	rand_no = rand()% NUMBER_CITIES - 1;

	//open fstream file
	fstream in_file(fn, ios::in);

	if(!in_file)
	{
		cout<< "Cannot open " << fn <<endl;
		exit(-1);
	}

	while(true)
	{
		//Read a word at a time
		in_file >> word;
		in_file >> x;
		in_file >> y;
		in_file >> highway;
		in_file >> elevation;


		//test for eof

		if(in_file.eof())
		{
			break;
		}
		//compare word_count to rand_no
		if (word_count == rand_no)
			break;

		//OW increment word counter
		word_count++;
	}
	
	this->name = new char[strlen(word) + 1];
	strcpy(this->name, word);

	this->highway = new char[strlen(highway)+1];
	strcpy(this->highway, highway);
	this ->elevation = elevation;

	location.setPoint(x, y);
	
}
char* City::getName()
{
	char* buffer = new char[strlen(name) + 1];
	strcpy(buffer, name);
	return buffer;
}
char* City::getHighway()
{
	char* buffer = new char[strlen(highway) + 1];
	strcpy(buffer, highway);
	return buffer;
}
GenPoint City::getLocation()
{
	return location;
}
int City::getElevation()
{
	return elevation;
}
double City::computeDistance()
{
	double LR_miles_x = 0.6 * 306;
	double LR_miles_y = 0.6 * 240;
	double city_miles_x = 0.6 * location.getX();
	double city_miles_y = 0.6 * location.getY();
	double distance = sqrt(pow(LR_miles_x - city_miles_x, 2) + pow(LR_miles_y - city_miles_y,2));
	return distance;
}
void City::draw()
{
	int obj;
	displayBMP("arkansas1.bmp", 0, 0);
	obj = drawLine(306, 240, location.getX(), location.getY(), 2);
	setColor(obj, 0, 0, 255);
}
