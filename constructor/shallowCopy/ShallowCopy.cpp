//
// Created by hyeonbae kim on 2026. 11. 18..
//

#include "ShallowCopy.h"

ShallowCopy::ShallowCopy(int n, int m) {
    this->n = n;
    this->m = m;
}

ShallowCopy::~ShallowCopy() {

}

ShallowCopy::ShallowCopy(const ShallowCopy &copy) {
    this->n = copy.n;
    this->m = copy.m;
}

int main() {
    ShallowCopy sc(1,2);
    ShallowCopy sc2(sc);
    return 0;
}