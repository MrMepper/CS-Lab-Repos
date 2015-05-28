#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void getInformation(struct StudentRecord student[], int num_std);
void enterKey(char key[]);
void calculateAveAndLetter (struct StudentRecord student[], int number_of_students, char key[]);
void displayResults(struct StudentRecord student[], int number_of_students);
void searchIDandDisplay(struct StudentRecord student [], int number_of_students);


const int MAX_SIZE=50;
struct Answers
{
	char answers[5];
};
struct StudentRecord
{
	int ID;
	string student_name;
	Answers answer;
	double score;
	double average;
	char letter_grade;
};
void main()
{
	struct StudentRecord stu[MAX_SIZE];
	int number_of_students;
	char key[5];//array of 5 for five answers

	cout <<"Please enter the number of students: "<<endl;
	cin >> number_of_students;

	enterKey(key);
	getInformation(stu, number_of_students);
	calculateAveAndLetter (stu, number_of_students, key);
	displayResults(stu, number_of_students);
	searchIDandDisplay(stu, number_of_students);
}

void getInformation(StudentRecord student[], int num_of_students)
{
	for (int i=0; i<num_of_students; i++)
	{
		string name;
		cout<<"Enter student "<<i+1<<" information:"<<endl;

		cout<<"Enter name: ";
		cin.ignore();
		getline(cin, name);
		student[i].student_name = name;
		

		cout<<"Enter ID: ";
		cin >> student[i].ID;
		

		cout<<"Enter the student's five answers: ";
		for (int j=0; j<5; j++)
		{
		cin >> student[i].answer.answers[j];
		}

	}
}

void enterKey(char key[])
{
	cout << "Please input your answer key: "<<endl;
	for (int i = 0; i < 5; i++)
		cin >> key[i];

}

void calculateAveAndLetter (StudentRecord student[], int number_of_students, char key[])
{
	double totalpossible = 50;
	double average = 0;
	//This below for loop calculates the average and total score of the student
	for (int i = 0; i < number_of_students; i++)
	{
		double possiblescore = 0;
		for ( int j = 0; j < 5; j++)
		{
			if (student[i].answer.answers[j] == key[j])
			{
				possiblescore = possiblescore + 10;
			}
			//What is going to happen below bugs me, but it is the only way I can find that it would work.
			//the for loop is going to constantly overwrite the array, so it is gradually going to increment up the value of possiblescore and the average.
			//Slow, but ehhh...I tried

			student[i].score= possiblescore;
			average = possiblescore / totalpossible * 100;
			student[i].average = average;
		}
	}

	//This below will calculate the letter grade of student
	for (int i = 0; i < number_of_students; i++)
	{
		if ( student[i].average >= 90)
		{
			student[i].letter_grade = 'A';
		}

		else if (student[i].average >= 80)
		{
			student[i].letter_grade = 'B';
		}

		else if (student[i].average >= 70)
		{
			student[i].letter_grade = 'C';
		}

		else if (student[i].average >= 60)
		{
			student[i].letter_grade = 'D';
		}
		else if (student[i].average >= 0)
		{
			student[i].letter_grade = 'F';
		}

		else
		{
			cout <<"This shouldn't of happened.."<<endl;
		}
	}

}

void displayResults(StudentRecord student[], int number_of_students)
{
	cout << "Student ID  "<<" Student Name  " << " Answers  " << "   Total Pts.  "<<" Average  "<< " Letter Grade"<<endl;
	cout << "----------  "<<" ------------  " << " -------  " << "   ----------  "<<" -------  "<< " ------------"<<endl;

	for (int i = 0; i < number_of_students; i++)
	{

		cout <<setw(6)<< student[i].ID<<setw(19)<<student[i].student_name<<setw(4);
		for (int j = 0; j < 5; j++)
			{
				cout <<student[i].answer.answers[j]<< " ";
			}
		cout << setw(10)<< student[i].score<<setw(10)<<student[i].average<<setw(10)<<student[i].letter_grade<<endl;
	}

	cout << endl<<endl<<"Students Admitted to the Graduate Program:"<<endl;
	cout<<endl<<endl;

	cout << "Student ID  "<<" Student Name  " <<" Total Pts.  "<<" Average  "<< " Letter Grade"<<endl;
	cout << "----------  "<<" ------------  " <<" ----------  "<<" -------  "<< " ------------"<<endl;

	for (int i = 0; i< number_of_students; i++)
	{
		if (student[i].letter_grade == 'A' || student[i].letter_grade == 'B')
		{
			cout <<setw(6)<< student[i].ID<<setw(19)<<student[i].student_name;
			cout << setw(10)<< student[i].score<<setw(10)<<student[i].average<<setw(10)<<student[i].letter_grade<<endl;
		}
	}

	cout <<endl<<endl<<"Students with Conditional Admission to the Graduate Program:"<<endl<<endl;

	cout << "Student ID  "<<" Student Name  " <<" Total Pts.  "<<" Average  "<< " Letter Grade"<<endl;
	cout << "----------  "<<" ------------  " <<" ----------  "<<" -------  "<< " ------------"<<endl;

	for (int i = 0; i< number_of_students; i++)
	{
		if (student[i].letter_grade == 'C')
		{
			cout <<setw(6)<< student[i].ID<<setw(19)<<student[i].student_name;
			cout << setw(10)<< student[i].score<<setw(10)<<student[i].average<<setw(10)<<student[i].letter_grade<<endl;
		}
	}

	cout <<"Students Not Allowed Admission: "<<endl<<endl;

	cout << "Student ID  "<<" Student Name  " <<" Total Pts.  "<<" Average  "<< " Letter Grade"<<endl;
	cout << "----------  "<<" ------------  " <<" ----------  "<<" -------  "<< " ------------"<<endl;

	for (int i = 0; i< number_of_students; i++)
	{
		if (student[i].letter_grade == 'D' || student[i].letter_grade == 'F')
		{
			cout <<setw(6)<< student[i].ID<<setw(19)<<student[i].student_name;
			cout << setw(10)<< student[i].score<<setw(10)<<student[i].average<<setw(10)<<student[i].letter_grade<<endl;
		}
	}
}

void searchIDandDisplay(StudentRecord student[], int number_of_students)
{
	int choice, IDchoice;
	cout <<"Would you like to search for a particular student to display his/her information? (1 for yes or 0 for no):"<<endl;
	cin >> choice;
	do 
	{

		if (choice == 1)
		{
			cout <<"Please enter the ID of the student to search for: "<<endl;
			cin >> IDchoice;

			for (int i = 0; i < number_of_students; i++)
			{
				if(IDchoice == student[i].ID)
				{
					cout << "Student ID  "<<" Student Name  " <<" Total Pts.  "<<" Average  "<< " Letter Grade"<<endl;		// I am very proud of this
					cout << "----------  "<<" ------------  " <<" ----------  "<<" -------  "<< " ------------"<<endl;
					cout <<setw(6)<< student[i].ID<<setw(19)<<student[i].student_name;
					cout << setw(10)<< student[i].score<<setw(10)<<student[i].average<<setw(10)<<student[i].letter_grade<<endl;
				}
				else
					cout<<"** This student did not take the exam or you entered the wrong ID **"<<endl;
			}
		}

		else
		{
			cout <<"Bye bye!"<<endl;
			return;
			}
		cout<<"Would you like to search for another student to display their grade(1 for yes or 0 for no?)"<<endl;
		cin>>choice;
	}while(choice == 1);
	cout << "Bye bye!"<<endl;
}