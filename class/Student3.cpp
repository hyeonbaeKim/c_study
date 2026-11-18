#include <iostream>
#include <iterator>

#include "Student.h"

/*
    Student2.cpp에서 배열을 사용해서 코드를 최소화 하는데엔 성공했지만
    한 학생의 데이터가 3개의 배열에 나눠져 있어서
    4번째 학생을 추가하기 위해서는 각각의 배열에 값을 일일히 채워 넣어 줘야함
    2번 학생을 지우기 위해서는 각각의 배열마다 사람이 정확히 두번째 요소에 지워야한다.
    -->즉,사람이 관리하기 좋은 방식은 학생이라는 개념을 하나로 묶는것.
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

    std::cout << student1.name << " " << student1.age << " " << student1.grade << std::endl;
    std::cout << student2.name << " " << student2.age << " " << student2.grade << std::endl;
}