//
// Created by robin on 2026-11-18.
//

#include "Child.h"
#include <iostream>

Child::Child(int x, int y, int z) : Parent(x,y,z){ //부모생성자는 반드시 initializer로 호출
    privateChild = 0;
    protectedChild  = 0;
    publicChild = 0;
}
void Child::childPublicMethod() {
    std::cout << "childPublicMethod" << std::endl;
    //멤버함수는 자기 클래스의 모든 것에 접근 가능
    privateChild = 1;
    protectedChild  = 2;
    publicChild = 3;
    childProtectedMethod();
    childPrivateMethod();

    //privateParent = 1;
    protectedParent = 2;
    publicParent = 3;
    publicParentMethod();
    protectedParentMethod();
    //privateParentMethod();
}
void Child::childProtectedMethod() {
    std::cout << "childProtectedMethod" << std::endl;
}

void Child::childPrivateMethod() {
    std::cout << "childPrivateMethod" << std::endl;
}

int main() {
    /*
     Child* child = new Child(0,0,0); 이렇게 객체 생성하든
     Child child(0,0,0); 이렇게 객체생성하든
     . or -> 통해서 접근시 일단 Child클래스에 접근한다. 다형성이 아닌 이상
     아래에서 위로 접근한다!
     */
    Child* child = new Child(0,0,0);
    //이것은 child라는 포인터통해 외부접근하는것
    child->publicChild  = 3; //public은 어디서나 접근 가능
    //child->protectedChild  =2; //protected는 자신과 상속 클래스내부에서만 접근가능
    //child->privateChild  = 1 ; //pribate는 자기클래스내부에서만 접근가능

    child->childPublicMethod(); //public은 어디서나 접근 가능
    //child->childProtectedMethod(); //protected는 자기클래스와 상속 클래스내부에서만 접근 가능
    //child->childPrivateMethod(); //private는 자기클래스내부에서만 접근가능

    child->publicParentMethod(); //public은 어디서나 접근 가능
    //child->protectedParentMethod(); ///protected는 자기클래스와 상속 클래스내부에서만 접근 가능
    //child->privateParentMethod();//private는 자기클래스내부에서만 접근가능
}