#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
class Animal {
public:
    virtual void sound() {
        printf("동물소리");
    }
    void test() {
        printf("Animal::test()");
    }
};

class Cat : public Animal {
    public:
    void sound() {
        printf("냐옹\n");
    }
    void test2() {
        printf("Animal::test2()\n");
    }
};

int main() {
    Animal *animal = new Cat();
    animal->sound();//냐옹
    animal->test();//Animal::test()
    //animal->test2(); 찾을 수 없음
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}