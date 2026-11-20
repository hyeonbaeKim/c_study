#include <iostream>

#include "Cat.h"
#include "Cow.h"
#include "Dog.h"

void soundDog(Dog* p_dog) {
    p_dog->sound();
}

void soundCat(Cat* p_cat) {
    p_cat->sound();
}

void soundCow(Cow* p_cow) {
    p_cow->sound();
}

int main () {
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Cow* cow = new Cow();

    soundDog(dog);
    soundCat(cat);
    soundCow(cow);
    return 0;
}
