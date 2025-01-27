// Compare this program with studentoperator.cpp 
// (in particular, the method sort)

#include <iostream>
#include <cstdlib>
#include "Student2.h"

using namespace std;

const int maxsize = 50;

void sort(Student*, int);
void print_list(Student*, int);

int main(int argc, char** argv) {

	Student *list; //important point
	int attending, i;
	char buf[maxsize];

	cout << "\nHow many students? (max 100)";
	cin >> attending;
	cin.get();

	list = new Student[attending]; //dynamic array

	int year;
	float grade;
	string name;

	for (i = 0; i < attending; i++) {
		cout << "\n\nStudent #" << i << endl;
		cout << "Name:";
		cin.getline(buf,maxsize);
		name = string(buf);
		list[i].setName(name);
		cout << "Grade:";
		cin >> grade;
		list[i].setGrade(grade);
		cout << "Year of birth:";
		cin >> year;
		cin.get();
		list[i].setYear(year);
	}

	sort(list, attending);
	print_list(list, attending);

	delete []list;
}

void print_list(Student* list,int n) {
	cout << "Sorted list of students:" << endl;
	cout << "------------------------" << endl;
	for (int i = 0 ; i < n ; i++ )
	list[i].print();  
}

/* Naive bubble sort algorithm */
void sort(Student *list, int n) { //bubble sort 
  
	int i,j;
	Student tmp;

	for (j = n - 1; j > 0; j--)
		for (i = 0; i < j; i++) {
			if (list[i].getGrade() > list[i+1].getGrade()) {
				tmp = list[i];
				list[i] = list[i+1];
				list[i+1] = tmp;
			}
		}
}