//
// Created by robin on 2026-11-19.
//

#include "Example1.h"
#include <iostream>
Example1::Example1(int id, int &value) : id(id), value(value){ //초기화리스트는 .cpp에서 정의한다!
        std::cout << "const멤버는 생성 후 값을 바꿀 수 없어서 생성 시 초기화 해야함" << std::endl;
        std::cout << "참조멤버는 반드시 생성 시 참조 대상을 정해야 함" <<  std::endl;
}
/*
 *초기화 리스트를 생략하고 생성자 본문에서 대입할 수도 있어요.
 *다만 그러면 먼저 0과 nullptr로 초기화한 뒤 다시 값을 대입하게 되므로,
 *처음부터 원하는 값으로 초기화하는 리스트가 더 자연스럽습니다.
 *반면 참조 멤버, const 멤버, 기본 생성자가 없는 멤버처럼 기본 초기화가 불가능한 경우에는 초기화 리스트가 필요합니다.
 */

int main() {
        int a = 4;
        Example1 ex1(3,a);
}

