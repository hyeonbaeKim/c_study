#include <iostream>
/*
예를 들어 inheritance/main.cpp처럼 새 폴더와 main.cpp를 만듭니다.
CLion에서 File → Reload CMake Project를 한 번 눌러 줍니다.
Run 설정 드롭다운에 inheritance가 생기면, 골라서 빌드하거나 실행하면 됩니다.
*/

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