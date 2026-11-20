#include "Child.h"
#include "Parent.h"

int main() {
    /*
    다운캐스팅은 잘못하면 심각한 런타임오류를 발생시킬 수 있다.
    */
    Parent* parent1 = new Child(); //(부모와 자식 각각 따로 만들어진 객체)

    //다운캐스팅1
    Child* child1 = (Child*)parent1; //자식은 부모를 담을 수 없으므로 반드시 형변환 (주소공유)
    child1->childMethod(); //문제없음



    Parent* parent2 = new Parent(); //부모만 만들어진 객체
    //다운캐스팅2. 런타임오류 피하려면 dynamicCast를 사용해라. 다만 부모클래스에서 virtual키워드가 존재해아함
    //if (Child* child2 = dynamic_cast<Child*>(parent2)) //parent2가 가리키는게 실제 Child*아니면 null
    //    child2->childMethod();
}
