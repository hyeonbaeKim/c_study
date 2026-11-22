#include "Dog.h"
#include "Cat.h"
#include "Cow.h"

void soundCow(Cow* p_cow) {
    p_cow->sound();
}

int main() {
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Cow* cow = new Cow();

    /*
    Cow* cowArr[] = {dog,cat,cow};
    for(Cow* cow : cowArr){
        cow->soundCow();
    }
    */
}

/*
중복을 없애고자 배열화 하려고 해도 타입이 맞지 않아 배열도 못만듬
뭐 cow,cow1,cow2등 cow배열들을 넣을 순 있겠지만 우리가 원하는 것은 서로 다른 타입들을 중복없이 한꺼번에
관리하고 싶은것임
*/