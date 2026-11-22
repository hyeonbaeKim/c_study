#include "Cow.h"
#include "Dog.h"
#include "Cat.h"

int main() {
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Cow* cow = new Cow();

    Animal* animalArr[] = { dog, cat, cow }; //다형성을 통해 Animal을 공통형으로 배열 처리할 수 있게 되었다.
    //Animal* animalArr2[] = { new Dog(), new Cat(), new Cow() }; //다형성을 통해 Animal을 공통형으로 배열 처리할 수 있게 되었다.

    for (Animal* animal : animalArr) { //다형성을 통해 Animal을 공통형으로 for문 처리할 수 있게 되었다.
        animal->sound();
    }
    return 0;
}
/*
아주 잘 작성된 코드 같아 보이지만 잠재적인 문제점이 있다.
1.Animal클래스를 생성할 수 있는 문제
Animal animal = new Animal(); 사실 이 클래스는 다형성을 위해서 필요한 것이지 직접 인스턴스를 사용할 일은 없다.
그치만 이렇게 생성된 클래스는 작동은 하지만 제대로 된 기능을 수행하지는 않는다.

2.sound()를 오버라이딩 하지 않을 수도 있는 문제
우리가 Animal클래스를 상속해서 Pig클래스를 만든다고 가정해보자. sound()를 오버라이딩해서 "꿀꿀"소리가 나오게 하고 싶다.
근데 개발자가 실수로 빼트렸다. 그러면 Animal의 sound를 상속받는다. 따라서 코드에 이상은 없지만 기능을 못할 수 있다.

--> 좋은 프로그램은 제약이 있는 프로그램이다.
 */