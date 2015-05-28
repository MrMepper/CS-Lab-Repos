#include "Lottery.h"
#include <iostream>
#include "graph1.h"

using namespace std;

Lottery::Lottery(void)
{
	no_balls = 0;
    yourNumbers = NULL;
    winningNumbers = NULL;
    matches = 0;
	counter = 0;
}


Lottery::~Lottery(void)
{
}
int Lottery::getNoBalls()
{
	return no_balls;
}
bool Lottery::setNoBalls(int no_balls)
{
	if(no_balls < 3)
	{
		this -> no_balls = 3;
		yourNumbers = new int[no_balls];
		winningNumbers = new int[no_balls];
		return false;
	}
	else if(no_balls > 10)
	{
		this -> no_balls = 10;
		yourNumbers = new int[no_balls];
		winningNumbers = new int[no_balls];
		return false;
	}
	else
	{
		this -> no_balls = no_balls;
		yourNumbers = new int[no_balls];
		winningNumbers = new int[no_balls];
		return true;
	}
}
bool Lottery::addNumber(int num)
{
	if(num < 1)
	{
		return false;
	}
	else if(num > 40)
	{
		return false;
	}
	else
	{
		yourNumbers[counter] = num;
		counter++;
		return true;
	}

}
void Lottery::displayYourNumbers()
{
	displayGraphics();
	char buffer[8];
	selectionSort();
	for(int i = 0; i < no_balls ; i++)
	{
		sprintf(buffer, "%d.bmp", yourNumbers[i]);
		displayBMP(buffer, 40 + (i * 60), 350);
	}
	gout << setPos(40, 410) << "Your Numbers"<<endg;
}

void Lottery::processWinningNumbers()
{
	int random;
	char buffer[8];
	for(int i = 0; i < no_balls; i++)
	{
		winningNumbers[i] = rand() % 40 + 1;
	}
	insertionSort();
	for(int i = 0; i < no_balls; i++)
	{
		Sleep(1000);
		sprintf(buffer, "%d.bmp", winningNumbers[i]);
		displayBMP(buffer, 40 + (i * 60), 220);
	}
}
void Lottery::selectionSort()
{
	int n = 0;
	int k = 0;
	int sm_index = 0; 
	int smallest = 0;
	int temp1 = 0;
	int temp2 = 0;
	
	for(k=0; k < no_balls -1; k++)	       // size-1 = number of passes
	{
		smallest=yourNumbers[k];
		 sm_index=k;

	  for(n= k+1; n < no_balls; n++)    // size = # elem. to look at
	  {
	   if(yourNumbers[n] < smallest)
	   {	
	     smallest=yourNumbers[n];
		    sm_index=n;
	   }
	  }
    
	  if (smallest < yourNumbers[k])
	  {
		    temp1=yourNumbers[k];
		    yourNumbers[k]=yourNumbers[sm_index];
	   yourNumbers[sm_index] = temp1;  
	  }
	}
}
void Lottery::insertionSort()
{
	 //Variable Declaration/Initialization
  int i = 0;
  int j = 0; 
  int v = 0;

	// For each element after the first:
	for (i = 1; i < no_balls; i++) 
	{	
    // Look back through the previous (sorted) elts.
		// Insert this elt after first that is smaller,
		// moving the others up as you go by them.
		v = winningNumbers[i];

		for (j = i-1; j >= 0 && winningNumbers[j] > v; j--)
		{
			// a[j] is bigger; move it up
			winningNumbers[j+1] = winningNumbers[j];
		}
		
		// a[j] <= v; put v after a[j]
		winningNumbers[j+1] = v;
	}
}
int Lottery::getMatches()
{
	return matches;
}
int Lottery::binarySearch(int target)
{
  int low = 0;
  int high = 0;
  int middle = 0;
  bool found = false;
  int index = -1;

  //Initialize low/high
  low = 0;
  high = no_balls - 1;

  while((low <= high) && (!found))
  {
    middle = (low + high)/2;

    if (winningNumbers[middle] == target)
       found = true;
    else if (target > winningNumbers[middle])
       low = middle + 1;
    else 
      high = middle -1;
  }

  if (!found)
  {
    index = -1;
  }
  else
  {
    index = middle;
  }
  return(index); 
}
int Lottery::computeWinnings()
{
	int score=0;
	for(int i = 0; i <no_balls; i++)
	{
		bool k = binarySearch(yourNumbers[i]);
		if(k==true)
		{
			score++;
		}
	}
	return score;
}