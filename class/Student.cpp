//
// Created by robin on 2026-11-18.
//

#include "Student.h"
#include <iostream>
int main() {
    std::string student1Name = "kim";
    int student1Age = 10;
    int student1Grade = 90;

    std::string student2Name = "Lee";
    int student2Age = 9;
    int student2Grade = 80;

    std::cout << student1Name << " " << student1Age << " "  << student1Grade << std::endl;
    std::cout << student2Name << " " << student2Age << " "  << student2Grade << std::endl;

    /*
     student3를 추가하기 위해서는
     student3Name, student3Age, student3Grade 각각의 변수에 값을 할당해줘야함
     (일을 3번 더 해야함)
     또 cout도 각각의 변수 다 써줘야함
     */
    return 0;
}
