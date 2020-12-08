#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Students {
	string FIO;
	int age;
	string group;
	int course;

	Students(std::string _FIO = "ФИО", int _age = 0, string _group = "Группа", int _course = 0)
		: FIO(_FIO), age(_age), group(_group), course(_course) {
		std::cout << "Конструктор" << std::endl;
	}

	~Students() {
		std::cout << "Деструктор" << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Students& student) {
		out << student.FIO << ' ' << student.age << ' ' << student.group << ' ' << student.course;
		return out;
	}

	struct ToCompareByFIO {
		bool operator()(const Students& first, const Students& second) const {
			return first.FIO < second.FIO;
		}

		bool operator()(const std::shared_ptr<Students>& first, const std::shared_ptr<Students>& second) const {
			return first->FIO < second->FIO;
		}
	};

	struct ToCompareByAge {
		bool operator()(const Students& first, const Students& second) const {
			return first.age < second.age;
		}

		bool operator()(const std::shared_ptr<Students>& first, const std::shared_ptr<Students>& second) const {
			return first->age < second->age;
		}
	};
	struct ToCompareByGroup {
		bool operator()(const Students& first, const Students& second) const {
			return first.group < second.group;
		}

		bool operator()(const std::shared_ptr<Students>& first, const std::shared_ptr<Students>& second) const {
			return first->group < second->group;
		}
	};

	struct ToCompareByCourse {
		bool operator()(const Students& first, const Students& second) const {
			return first.course < second.course;
		}

		bool operator()(const std::shared_ptr<Students>& first, const std::shared_ptr<Students>& second) const {
			return first->course < second->course;
		}
	};
};