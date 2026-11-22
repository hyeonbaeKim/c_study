#include <iostream>
#include <string>

int main() {
    std::string a = "이창민";
    std::cout << "a: " << a << std::endl; //a: 이창민

    std::string b = std::move(a); // a를 rvalue처럼 만들어서 string의 이동 생성자가 선택될 수 있게 해요.
    //그래서 문자열 자원을 넘길 수 있습니다.
    std::cout << "b: " << b << std::endl; //b: 이창민
    std::cout << "a: " << a << std::endl; //a:

    int a1 =3;
    int b1 = std::move(a1); //a는 rvlue됬고 이동 연산을 선택할 수 있게 됌

    std::cout << "b: " << b1 << std::endl; //3
    std::cout << "a: " << a1 << std::endl; //3
    //->근데 a1은 int라 옮길 자원이 별도로 없어서 결과는 값 복사와 같다

    /*
     *std::move(a1)가 a1을 xvalue(만료된 값)로 바꿔서, 이동 연산이 선택될 수 있게 합니다.
     *xvalue는 rvalue의 한 종류예요.
    다만 rvalue라고 해서 무조건 이동하는 건 아닙니다.
    대상 타입에 맞는 이동 연산이 있어야 실제 이동이 일어나고, int처럼 단순한 타입은 결과가 복사와 같습니다.
    */

    char* str1 = "kim";
    char* str2 = std::move(str1); //str1을 이동 가능한 형태(char*&&)로 바꾸지만,
    //raw pointer에는 자원 소유권을 넘기는 이동 동작이 없습니다.
    std::cout << "str1: " << str1 << std::endl; //kim
    std::cout << "str2: " << str2 << std::endl; //kim
    //char*는 문자열을 관리하는 객체가 아니라 주소 하나를 담는 변수예요.
    //std::move를 해도 그 주소값이 str2에 복사될 뿐, str1은 자동으로 비워지지 않습니다.

    /*
     핵심은 std::move는 이동을 실행하는 함수가 아니라, “이 값의 자원을 가져가도 된다”고 표시하는 도구라는 점이에요.
     실제 이동은 그 타입의 이동 연산이 있을 때만 일어납니다.
     그래서 int나 char*처럼 작은 값은 가져갈 별도 자원이 없어요.
     이동 연산을 선택하더라도 숫자나 주소를 복사하는 것과 결과가 같습니다. std::move를 써도 이득이 없죠.
     반면 크거나 복사할 수 없는 자원을 다룰 땐 유용합니다.
     std::string a = "hello";
     std::string b = std::move(a);  // 문자열 저장 공간을 b가 이어받을 수 있음

     auto p = std::make_unique<int>(3);
     auto q = std::move(p);         // unique_ptr 소유권을 q로 넘김

     즉 이동 가능한 자원을 다른 객체에 넘기고 싶을 때 씁니다.
     예를 들어 unique_ptr는 복사가 금지되어 있어서 std::move로 소유권을 넘겨야 해요.
     숫자나 일반 포인터에는 보통 쓸 이유가 없습니다.
     */
    return 0;
}