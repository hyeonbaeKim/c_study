#include <iostream>
#include <memory>
#include <string>

class Weapon {
private:
    std::string name;

public:
    Weapon(std::string name) : name(name) { std::cout << name << " 생성!" << std::endl; }
    ~Weapon() { std::cout << name << " 파괴됨!" << std::endl; }
    void attack() { std::cout << name << "로 공격!" << std::endl; }
};

class Person {
private:
    std::string name;
    std::unique_ptr<Weapon> weapon; // 각 Person만 소유

public:
    // 생성자에서 무기를 유니크 포인터로 초기화
    Person(std::string name, std::string weaponName)
    : name(name), weapon(std::make_unique<Weapon>(weaponName)) {}
    void useWeapon() {
        std::cout << name << ": ";
        if (weapon) weapon->attack();
    }
};
int main() {
    // 두 명의 캐릭터 생성
    Person p1("전사", "검");
    Person p2("마법사", "지팡이");
    // 각각 무기 사용
    p1.useWeapon();
    p2.useWeapon();

    return 0;
    // main 함수가 끝나면 p1, p2가 소멸되면서
    // 내부의 weapon들도 자동으로 메모리 해제됨
}