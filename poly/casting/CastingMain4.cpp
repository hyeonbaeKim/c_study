#include "Child.h"
#include "../Parent.h"

int main() {
    /*
    다운캐스팅은 잘못하면 심각한 런타임오류를 발생시킬 수 있다.
    */
    Parent* parent1 = new Child(); //(부모와 자식 각각 따로 만들어진 객체)
    //parent1->childMethod(); 오류

    //다운캐스팅1. 런타임오류 발생 안하는 경우
    Child* child1 = (Child*)parent1; //자식은 부모를 담을 수 없으므로 반드시 형변환 (주소공유)
    child1->childMethod(); //문제없음

    Parent* parent2 = new Parent(); //부모만 만들어진 객체
    //parent2->childMethod(); 오류

    /*
    다운캐스팅2. 런타임 오류 발생하는 경우
    Child* child2 = (Child*)parent2; //자식은 부모를 담을 수 없으므로 반드시 형변환 (주소공유)
    주소공유되며 parent2가 가리키는 Parent(Child는 생성되지 않음 )를 포인팅하는데 범위가 Child로 해석됨
    child2->childMethod(); //런타임에러 발생
    */

    /*
    Child* child = new Child();
    Parent* parent1 = (Parent*)child; 같은 업캐스팅
    업캐스팅의 경우는 이런 문제가 절대 발생하지 않는다. 왜냐면 객체를 생성하면 해당 타입의 상위 부모타입은 모두 함께 생성된다!
    따라서 위로만 타입을 변경하는 업캐스팅은 메모리상에 인스턴스가 모두 존재하기 때문에 항상 안전하다.
    반면 다운캐스팅의 경우는 인스턴스에 존재하지 않는 하위타입으로 캐스팅하는 문제가 발생할 수 있다. 왜냐면 객체를 생성하면
    부모타입은 모두 함께 생성되지만 자식타입은 생성되지 않는다.
    따라서 개발자가 이런 문제를 인지하고 사용해야 한다는 의미로 명시적으로 캐스팅 해주어야 한다.
     */
}
