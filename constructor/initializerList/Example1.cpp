//
// Created by robin on 2026-11-19.
//

#include "Example1.h"
#include <iostream>
Example1::Example1(int id, int &value) : id(id), value(value){ //초기화리스트는 .cpp에서 정의한다!
        std::cout << "const멤버는 생성 후 값을 바꿀 수 없어서 생성 시 초기화 해야함" << std::endl;
        std::cout << "참조멤버는 반드시 생성 시 참조 대상을 정해야 함" <<  std::endl;
}

int main() {
        int a = 4;
        Example1 ex1(3,a);
}

