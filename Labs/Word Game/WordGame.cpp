#include "WordGame.h"
#include <iostream>
#include <fstream>
#include "graph1.h"
using namespace std;
WordGame::WordGame()
{
	fileName = NULL;
	word = NULL;
}
WordGame::~WordGame()
{
	delete[] fileName;
	delete[] word;
}
char* WordGame::getFileName()
{
	char* buffer = new char[strlen(fileName) + 1 ];
	strcpy(buffer, fileName);
	return buffer;
}
void WordGame::setFileName(char* fn)
{
	this -> fileName = new char[strlen(fn) + 1];
	strcpy(this->fileName, fn);
}
void WordGame::setWord(int rand_no)
{
	int word_count = 0;
	char word[1000];

	//open fstream file
	fstream in_file(this->fileName, ios::in);

	if(!in_file)
	{
		cout<< "Cannot open " << this->fileName<<endl;
		exit(-1);
	}

	while(true)
	{
		//Read a word at a time
		in_file >> word;

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

	this -> word = new char[strlen(word) + 1];
	strcpy(this->word , word);
}
char* WordGame::getWord()
{
	char* buffer = new char[strlen(word) + 1];
	strcpy(buffer, word);
	return buffer;
}
void WordGame::draw()
{
	int i;
	int *obj = new int[strlen(word) + 1];
	for( i = 0; word[i]!=NULL; i++)
	{
		obj[i] = drawRect(100+(i*30), 300, 32, 32);

	}
	Sleep(2000);
	for( i = 0; word[i]!=NULL; i++)
	{
		removeObject(obj[i]);

	}
	//char buffer[7];
	//sprintf(buffer, "%c.bmp", word[i]);
	//displayBMP(buffer, 50+(i*30), 300);
}
int WordGame::play()
{
	int score = 0;
	int guess_number = strlen(word) - 1;
	char* guess= new char[strlen(word)+1];
	bool* hidden = new bool[strlen(word)+1];
	char hint;
	int i=0;
	int count = 0;

	char buffer[7];
	sprintf(buffer, "%c.bmp", word[0]);
	displayBMP(buffer, 130+(i*30), 200);
	hidden[0] = false;

	for (int i = 1; word[i]!=NULL; i++)
	{
		if(word[i] == 'a')
		{
			sprintf(buffer, "%c.bmp", word[i]);
			displayBMP(buffer, 130+(i*30), 200);
			guess_number--;
			hidden[i] = false;
		}
		else if(word[i] == 'e')
		{
			sprintf(buffer, "%c.bmp", word[i]);
			displayBMP(buffer, 130+(i*30), 200);
			guess_number--;
			hidden[i] = false;
		}
		else if(word[i] == 'i')
		{
			sprintf(buffer, "%c.bmp", word[i]);
			displayBMP(buffer, 130+(i*30), 200);
			guess_number--;
			hidden[i] = false;
		}
		else if(word[i] == 'o')
		{
			sprintf(buffer, "%c.bmp", word[i]);
			displayBMP(buffer, 130+(i*30), 200);
			guess_number--;
			hidden[i] = false;
		}
		else if(word[i] == 'u')
		{
			sprintf(buffer, "%c.bmp", word[i]);
			displayBMP(buffer, 130+(i*30), 200);
			guess_number--;
			hidden[i] = false;
		}

	}

	while(true)
	{
		
		gout<<setPos(100,120)<<"Guess Number: " << guess_number<<endg;
		cout << "Guess #"<<i+1;
		cout << "What is the word? ";
		cin >> guess;
		i++;
		
		if(strcmp(guess, word) == 0)
		{
			for(int i = 0; word[i]!=NULL; i++)
			{
				if (hidden[i] != false)
				{
					score+=10;
				}
			}
			gout<<setPos(100, 50)<<"You WIN!!"<<endg;
			break;

		}


		
		if(guess_number <= 0)
		{
			gout<<setPos(100,50)<<"You are a loser"<<endg;
			break;
		}

		if (count%2 == 0)
		{
			for(int j = 0; word[j]!=NULL; j++)
			{
				if(hidden[j] != false)
				{
					sprintf(buffer, "%c.bmp", word[j]);
					displayBMP(buffer, 130+(j*30), 200);
					hidden[j] = false;
					break;
				}
				
			}
		}
		if (count%2 != 0)
		{
			for(int j = (strlen(word)-1); j>0; j--)
			{
				if(hidden[j] != false)
				{
					sprintf(buffer, "%c.bmp", word[j]);
					displayBMP(buffer, 130+(j*30), 200);
					hidden[j] = false;
					break;
				}
			}
		}
		count ++;
		guess_number--;
	}


	return score;
}