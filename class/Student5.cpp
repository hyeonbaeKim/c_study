#include <iostream>
#include "Student.h"

/*
 Student4.cpp에서 배열을 효율적으로 하는 3단계 방법
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

    //자바는 students.length는 2
    //sizeof는 전체 바이트 크기를 돌려준다. students의 전체 바이트는 student의 2배이므로 2
    for (int i = 0; i < sizeof(students)/sizeof(Student); i++) {
        std::cout << students[i].name << " " << students[i].age << " " << students[i].grade << std::endl;
    }
    for (int i = 0; i < std::size(students); i++) {
        std::cout << students[i].name << " " << students[i].age << " " << students[i].grade << std::endl;
    }
    for (int i = 0; i < std::size(students); i++) {
        Student student;
        student = students[i]; //멤버변수로 포인터가 없으므로 대입연산자가 멤버별로 잘 수행됌 깊은복사처럼
        //Student student = students[i] //멤버변수로 포인터가 없으므로 복사생성자가 멤버별로 잘 수행됌 깊은복사처럼
        std::cout << students[i].name << " " << students[i].age << " " << students[i].grade << std::endl;
    }
    for (Student student : students) {
        std::cout << student.name << " " << student.age << " " << student.grade << std::endl;
    }
}