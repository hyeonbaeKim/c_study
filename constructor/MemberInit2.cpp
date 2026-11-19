#include <iostream>
#include "MemberInit.h"

void initMember(MemberInit* p_member, std::string name, int age, int grade) {
    p_member->name = name;
    p_member->age = age;
    p_member->grade = grade;
}

int main() {
    MemberInit* member1 = new MemberInit();
    initMember(member1, "kim",32,100);

    MemberInit* member2 = new MemberInit();
    initMember(member2,"leeChangMin",34,67);

    //타입이 같아서 배열화 할 수 있다.
    MemberInit* p_members[2] = {member1,member2};

    for (MemberInit* member : p_members) {
        std::cout << member->name << " " << member->age << " " << member->grade << std::endl;
    }

    /*
    [생성자 탄생 배경]
    initMember를 사용해 반복을 제거했다. 근데 이 메서드는 대부분 MemberInit 객체의 멤버변수를 사용한다.
    이런 경우 속성과 기능을 한 곳에 두는 것이 더 나은 방법이다.
    쉽게 말해서 Member가 자기 자신의 데이터를 변경하는 메서드를 제공하는 것이 낫다. ->
    */
    return 0;
}