#include <iostream>
#include <memory> //스마트 포인
//RAII를 실제로 구현
//std::unique_ptr : 하나의 주인만 있는 포인터
//std::shared_ptr : 여러 객체가 공유 가능한 포인터

void uniquePointerTest() {
    std::unique_ptr<int> p = std::make_unique<int>(10);
    //std::unique_ptr<int> p2 = std::(p); 에러
    //std::unique_ptr<int> p3 = std::move(p); //ok 소유권이전
}

void sharedPointerTest() { //포인팅 횟수(참조 카운팅)을 계산해서 0이 되면 대상을 삭제한다.
    std::shared_ptr<int> p = std::make_unique<int>(10);
    std::shared_ptr<int> p2 = p;
    //지금 이 상황에선 p2와 p가 같은 heap공간의 int를 포인팅하는데
    //p2가 delete하고 p에서 접근하면 에러생김
    //근데 shared ptr은 내부적으로 참조 카운팅을 갖고 있어서

    std::cout << p.use_count() << std::endl; //2
    {
        std::shared_ptr<int> p3 = p;
        std::cout << p.use_count() << std::endl; //3
    }//원래는 스코프 종료되면서 p3가 delete되는데 참조카운팅이 남아있으므로 그러지 않음.
    //즉 참조카운팅이 1일때 스코프 벗어나거나 이러면 동적메모리 삭제함 
    //즉 p3만 사라지고 동적메모리는 살아있음
    std::cout << p.use_count() << std::endl; //2
}


