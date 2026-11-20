

#include <iostream>

#include "Cat.h"
#include "Cow.h"
#include "Dog.h"

int main() {
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Cow* cow = new Cow();

    dog->sound(); //멍멍
    cat->sound(); //냐옹
    cow->sound(); //음메


    /*
    만약 여기서 까마귀가 추가된다면? 까마귀 클래스를 또 만들고 여기서 객체생성하고 울음소리 내줘야함
    객체->sound(); //중복됨
    중복을 제거하기 위해서는 메서드를 사용하거나, 배열, for문이 필요. 근데 클래스가 서로 완전히 다름
     */
    return 0;
}
