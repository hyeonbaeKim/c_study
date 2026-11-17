#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
class Animal {
public:
    virtual void sound() {
        printf("동물소리");
    }
    void test() {
        printf("Animal::test()\n");
    }
    void walk() {
        printf("Animal::walk()\n");
    }
};

class Cat : public Animal {
    public:
    void sound() { //메서드 오버라이딩 됨
        printf("냐옹\n");
    }
    void test2() {
        printf("Cat::test2()\n");
    }
    void walk() { //메서드 오버라이딩 되지 않아 씹힘
        printf("Cat::walk()\n");
    }
};

int main() {
    Animal *animal = new Cat();
    animal->sound();//냐옹
    animal->test();//Animal::test()
    //animal->test2(); 찾을 수 없음
    animal->walk(); //Animal::walk()
    return 0;
}