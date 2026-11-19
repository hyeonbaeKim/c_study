#include <iostream>
#include "../Parent.h"
#include "../Child.h"

int main() {
    Parent* poly = new Child();
    //poly->childMethod(); 컴파일에러(왜? 위에서 아래로 찾지 못하니까) -> 다운캐스팅으로 해결할 수 있다.

    Child* child = (Child*)poly; //Child* child; 라는 포인터변수가 하나 더 추가되고 그게 poly가 가리키는 것을 가르키게함
    //
    //즉, child와 poly모두 Child객체 가리키는 것
    child->childMethod(); //다운캐스팅으로 해결

    //여전히 그냥 Child* child = new Child(); 하는게 더 나은거 같은데?
    return 0;
}