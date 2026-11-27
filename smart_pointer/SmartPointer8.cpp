#include <iostream>
#include <memory>
#include <string>

class Background {
private:
    std::string name;

public:
    Background(std::string name) : name(name) {
        std::cout << "[배경] " << name << " 로딩 완료!" << std::endl;
    }
    ~Background() {
        std::cout << "[배경] " << name << " 메모리에서 제거됨." << std::endl;
    }
};

class Person {
private:
    std::string name;
    std::shared_ptr<Background> sharedBg; // 배경 공유

public:
    Person(std::string name, std::shared_ptr<Background> bg)
    : name(name), sharedBg(bg) {}
    void showInfo() {
        std::cout << name << "가 현재 배경을 참조 중 (참조 횟수: "
                  << sharedBg.use_count() << ")" << std::endl;
    }
};
int main() {
    // 배경 객체 생성 (shared_ptr로 관리)
    auto map = std::make_shared<Background>("황야의 맵");
    {
        Person p1("전사", map);
        Person p2("마법사", map);

        p1.showInfo();
        p2.showInfo();
    } // p1, p2가 소멸되어도 map은 아직 참조 중이므로 배경은 유지됨

    std::cout << "참조 횟수가 0이 되면 배경이 자동 소멸됩니다." << std::endl;
    return 0;
}