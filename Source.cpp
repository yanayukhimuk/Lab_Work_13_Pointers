#include "Students.h"
#include <list>
#include<algorithm>
#include <Windows.h>
#include<vector>

using namespace std; 


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 

	auto showStudentsList = [](const list<Students>& students) {
		cout << "Cписок студентов: " << endl;
		for_each(students.cbegin(), students.cend(), [](const Students& student) {
			cout << student << endl;
			});
		cout << endl;
		cout << endl;
		cout << endl;
	};

	Students Student_1("Иванов Иван Иванович", 18, "AB-21", 1);
	Students Student_2("Петров Пётр Петрович", 18, "AB-21", 1);
	Students Student_3("Сидоров Николай Олегович", 21, "ИС-24", 4);
	Students Student_4("Янчук Мария Степановна", 19, "AB-22", 2);
	Students Student_5("Жук Василиса Юрьевна", 20, "ИС-23", 3);

	list<Students> students = { Student_1, Student_2, Student_3, Student_4, Student_5 };
	showStudentsList(students);

	students.sort(Students::ToCompareByAge());
	showStudentsList(students);

	auto showStudentsVector = [](const vector<shared_ptr<Students>>& students) {
		cout << "Сортировка студентов: " << endl;
		for_each(students.cbegin(), students.cend(), [](const shared_ptr<Students>& student) {
			cout << *student << endl;
			});
		cout << endl;
		cout << endl;
		cout << endl;
	};

	shared_ptr<Students> ptrStudent_1(new Students(Student_1));
	shared_ptr<Students> ptrStudent_2(new Students(Student_2));
	shared_ptr<Students> ptrStudent_3(new Students(Student_3));
	shared_ptr<Students> ptrStudent_4(new Students(Student_4));
	shared_ptr<Students> ptrStudent_5(new Students(Student_5));

	vector<shared_ptr<Students>> studentsPointers{ ptrStudent_1, ptrStudent_2, ptrStudent_3, ptrStudent_4, ptrStudent_5};
	sort(studentsPointers.begin(), studentsPointers.end(), Students::ToCompareByFIO());
	showStudentsVector(studentsPointers);

	studentsPointers.clear();

	return 0; 
}