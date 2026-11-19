//
// Created by robin on 2026-11-19.
//

#include "MemberConstruct.h"
#include <iostream>
/*
 std::string은 문자열 내용을 관리하므로 this->name = name;처럼 대입하면 name의 문자열 내용이 복사됩니다.
 그래서 매개변수가 사라져도 멤버 name은 유효합니다. 이런 의미에서 std::string은 깊은 복사처럼 동작한다고 볼 수 있어요.
 반면 const char* 멤버에 문자열을 대입하면 문자열을 복사하는 게 아니라 주소만 저장합니다.
 그리고 const char*가 가리키는 곳에는 쓸 수 없으므로 strcpy(this->name, name)도 안전하게 할 수 없습니다.
 */
MemberConstruct::MemberConstruct(std::string name, int age, int grade) {
    this->name = name;
    this->age = age;
    this->grade = grade;
    std::cout << this->name << " " << this->age << " " << this->grade << std::endl;
}

MemberConstruct::MemberConstruct(std::string name, int age) {
    this->name = name;
    this->age = age;
    this->grade = 67; //멤버변수는 총3개인데 매개변수로 2개 들어와서 하나는 defualt로
    std::cout << this->name << " " << this->age << " " << this->grade << std::endl;
}

int main() {
    MemberConstruct memberConstruct("kim",32);
    MemberConstruct memberConstruct2("Lee",33,10);

    /*
        생성자를 오버로딩 한 덕분에 성적입력이 꼭 필요한 경우에는 grade가 있는 생성자를 호출하면 되고
        그렇지 않은 경우에는 grade가 없는 생성자를 호출하면 된다.
     */
}



