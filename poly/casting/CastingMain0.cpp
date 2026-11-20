#include "../Parent.h"
#include "../Child.h"
int main() {
    Parent* parent = new Parent(); //new Parent(); 통해 Parent객체만 생성되고 parent로 Parent객체만 포인팅
    parent->parentMethod();

    Child* child = new Child(); //new Child(); 통해 Parent객체+Child객체 생성되고 child로 Child객체만 포인팅
    child->parentMethod(); //child가 Child객체만 포인팅중이지만 Child객체에서 못 찾으면 상속받은 부모클래스로 가서 찾는다.
    child->childMethod(); //child가 Child객체만 포인팅중이라서 Child객체에서 찾은 것.

    //다형성 (부모는 자식을 담을 수 있다.)
    Parent* poly = new Child(); //new Child(); 통해 Parent객체+Child객체 생성되고 poly로 Parent객체만 포인팅
    /*
     여기서 poly는 Parent만 알지 Child는 알 수 없어서 Parent에서 못 찾는다고해서 Child로 내려가서 찾을 수 없음
     즉 일반적으로 아래에서 위로 찾을 순 있지만 위에서 아래로 찾을 순 없음
     */
    poly->parentMethod(); //poly가 Parent객체만 포인팅중이라서 Parent객체에서 찾은 것.

    /*
     이렇게 위에서 아래로 찾고 싶은 경우엔 캐스팅이 필요하다.
     아니 근데 그냥 Child* child = new Child(); 하지 왜 캐스팅까지 써가면서 굳이 위에서 아래로 찾으려할까?
     */
    return 0;
}