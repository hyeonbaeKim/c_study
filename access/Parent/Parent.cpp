//
// Created by robin on 2026-11-18.
//

#include "Parent.h"
#include <iostream>
Parent::Parent(int x, int y, int z) {
    //자기 클래스 내부는 전부 다 접근 가능
    privateParent = x;
    protectedParent = y;
    publicParent = z;
}

void Parent::publicParentMethod() {
    std::cout << "publicParentMethod" << std::endl;
}

void Parent::protectedParentMethod() {
    std::cout << "protectedParentMethod" << std::endl;
}

void Parent::privateParentMethod() {
    std::cout << "privateParentMethod" << std::endl;
}
