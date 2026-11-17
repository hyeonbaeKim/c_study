//
// Created by robin on 2026-11-17.
//

#include "A.h"

void B::b_public_func() {
    //A.h의 A클래스안에서 frined class B;를 해줬기 때문에 class B는 A의 어떤것에도 접근 가능
    A a;
    a.a_private_func();
    a.a_private_num = 2;
}

void func() {
    //A.h의 A클래스안에서 frined void func();를 해줬기 때문에 void func()는 A의 어떤것에도 접근 가능
    A a;
    a.a_private_func();
    a.a_private_num = 3;
}

int main(){}