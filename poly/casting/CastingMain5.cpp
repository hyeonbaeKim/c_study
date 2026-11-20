#include <iostream>

//dynamic_cast 예제 만들기 위해서 virtual키워드 들어간 부모클래스 생성함

class oopParent {
public :
    virtual ~oopParent() = default; // dynamic_cast에 필요한 다형성********
};

class oopChild : public oopParent {
public:
    void childMethod() {}
};

void call(oopParent* parent) {
    if (oopChild* child = dynamic_cast<oopChild*>(parent)) {
        std::cout << "Child 인스턴스 맞음" << std::endl;
        child->childMethod();
    } else {
        std::cout << "Child 인스턴스 아님 " << std::endl;
    }
}

int main() {
    oopParent* parent = new oopParent();
    call(parent); //child 인스턴스 아님

    oopParent* parent2 = new oopChild();
    call(parent2); // child인스턴스 맞음
}