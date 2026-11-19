//
// Created by robin on 2026-11-19.
//

#include "MemberInit.h"
#include <iostream>

int main() {
    MemberInit* member1 = new MemberInit(); //MemberInit() 이것은 기본생성자 호출한 것.
    member1->name = "kim";
    member1->age = 32;
    member1->grade = 100;

    MemberInit* member2 = new MemberInit(); //MemberInit() 이것은 기본생성자 호출한 것.
    member2->name = "LeeChangMin";
    member2->age = 34;
    member2->grade = 67;

    //타입이 같기에 배열화 할 수 있다.
    MemberInit* members[2] = {member1, member2};

    for (MemberInit* p_member : members) {
        std::cout << p_member->name << " " << p_member->age << " " << p_member->grade << std::endl;
    }

    /* [생성자가 왜 필요한가?]
        아마도 회원객체를 제대로 사용하기 위해서는 객체를 생성하자 마자 저렇게 초깃값을 설정해줘야 할 것이다.
        그러나 이 코드에서는 회원 객체르 만들고 그 후 회원의 초깃값을 설정하는 부분이 반복된다.
        메서드를 사용해서 반복을 제거해보자.
    */
    return 0;
}