#include <stdio.h>

int RecursiveSalary(int salary, int time) { //salary where the following salary is the previous salary * 2 - 50

	if (time <= 0) { // if the value we entered is less or 0, ie, we have finished work.
		return 0;
	}
	return (salary + RecursiveSalary(salary * 2 - 50, time - 1)); // else return this
}

int Salary(int salary , int hours, int rate) { //regular salary where we have a base that we then just add every hour that passes
	for (int i = 1; i < hours; i++) {
		salary = salary + rate;
	}
	return salary;	
}

int main() {

	
	int regularRate = 1072; //hourly rate
	int hours = 8; //hours worked
	int salary; //hourly rate

	int recursiveStartSalary = 100; //start salary of the recursive salary
	int recursiveSalary; //recursive rate

	salary = Salary(regularRate, hours, regularRate); //regular salary
	recursiveSalary = RecursiveSalary(recursiveStartSalary, hours); //recursive salary

	printf("一般的な賃金　＝　%d\n", salary);
	printf("再帰的な賃金　＝　%d\n", recursiveSalary);

	return 0;
}