//
// Created by hyeonbae kim on 2026. 11. 21..
//

#include "Animal.h"
#include "Cow.h"
#include "Dog.h"
#include "Cat.h"

void soundAnimal(Animal* animal) { //부모는 자식을 담을 수 있다.
    animal->sound();
}

int main() {
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Cow* cow = new Cow();

    soundAnimal(cat);
    soundAnimal(cow);
    soundAnimal(dog);

    /*
   다형성 덕분에 이후에 동물을 추가해도 가령 elepant, 이후에 soundAnimal함수를 재활용할 수 있다. soundAnimal(elepant)
   물론 다형성을 사용하기 위해 새로운 동물은 Animal을 상속받아야한다.
    */
    return 0;
}


