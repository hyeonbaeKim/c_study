#include "DeepCopy.h"

#include <cstring>
#include <iostream>

DeepCopy::DeepCopy(int n) {
    this->n = n;
    m = new int[n];
    for (int i = 0; i < n; i++) {
        m[i] = i;
    }
}

DeepCopy::DeepCopy(const DeepCopy &deepCopy) {
    n = deepCopy.n;
    m = new int[n]; //포인터는 복사 할때 메모리 할당이 반드시 필요하다.
    //포인터 복사생성자란 같은 메모리를 참조하는게 아니기 때문
    for (int i = 0; i < n; i++) {
        m[i] = deepCopy.m[i];
    }
}

DeepCopy::~DeepCopy() { //멤버변수에 포인터있으면 소멸자에서 반드시 해제시켜야함
    if (m) {
        delete[] m;
    }
}

int main() {
    DeepCopy dc(5);
    DeepCopy dc2(dc);
}
