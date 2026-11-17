#include <set>
#include <iostream>

//원소가 곧 키인 set

int main() {
    std::set<int> s;
    s.insert(10); //set에 원소 추가 : insert
    s.insert(50); //시퀀스 컨테이너 처럼 어디에 insert하는지는 안적어도된다.
    s.insert(20); //내부적으로 트리구조로정렬시키면서 insert시키기 때문
    s.insert(40); //시퀀스 컨테이너가 각 상자마다 원소를 한개 씩 담고 각 상자에 번호를 매긴거라면
    s.insert(30); // 셋은 그냥 큰 상자안에 모든 원소들을 쑤셔 넣은 것
    s.insert(30); // 셋은 중복허용하지 않는다. 30은 1개만 출력될 것
    //그 상자안에 원소가 어디에 있는지는 중요한게 아니고, 그 상자안에 원소가 있냐 없냐만이 중요한 것

    /* set은 내부적으로 트리구조(왼쪽노드는 나보다 작다, 오른쪽 노드는 나보다 크다)로 정렬된다.
            30 //최상위노드 (루트 노드)
     20              40
10      null   null      50
     */

    //set은 정렬되어 나온다.
    std::cout << "s의 값은 ";
    for (int num : s)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout <<"20이 s의 원소인가요?";
    auto itr = s.find(20); //존재하지 않으면 s.end()를 리턴
    if (itr != s.end()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}