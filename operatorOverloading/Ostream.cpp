//
// Created by robin on 2026-11-17.
//

#include "Ostream.h"
#include <stdio.h>

void endl() {
    printf("\n");
}

const Ostream& Ostream::operator<<(int i) const {
    printf("%d",i);
    return *this;
}
const Ostream& Ostream::operator<<(const char* s) const {
    printf("%s",s);
    return *this;
}
const Ostream& Ostream::operator<<(float f) const {
    printf("%lf",f);
    return *this;
}
const Ostream& Ostream::operator<<( void(*fp)() ) const {
    fp();
    return *this;
}

int main() {
    Ostream cout;
    cout.operator<<(1).operator<<("hello").operator<<(3.14f) << endl;
    //endl()하게되면 void반환이라
    ////cout.operator<<(1).operator<<("hello").operator<<(3.14f) << void; 와 같음
}