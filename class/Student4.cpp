#include <iostream>
#include "Student.h"

/*
 Student3.cpp의 Student 객체들을 따로 하는게 아니라 타입이 같으니 배열로 묶음
 */
int main() {
    Student student1;
    student1.name = "kim";
    student1.age = 10;
    student1.grade = 90;

    Student student2;
    student2.name = "lee";
    student2.age = 9;
    student2.grade = 80;

    Student students[] = {student1, student2};

    std::cout << students[0].name << " " << students[0].age << " " << students[0].grade << std::endl;
    std::cout << students[1].name << " " << students[1].age << " " << students[1].grade << std::endl;
}