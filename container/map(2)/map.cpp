#include <iostream>
#include <map>
#include <string>

//원소가 key인 set과 달리
//map은 key와 value를 std::pair<key,value>로 관리

int main() {
    std::map<std::string, double> pitcher_list;

    //map의 insert는 pair객체를 인자로 받는다.
    pitcher_list.insert(std::pair<std::string, double>("박세웅",2.23));
    pitcher_list.insert(std::pair<std::string, double>("해커",2.93));
    pitcher_list.insert(std::pair<std::string, double>("피어밴드",2.95));

    //간편히
    pitcher_list.insert(std::make_pair("차우찬", 3.04));
    pitcher_list.insert(std::make_pair("장원준", 3.05));
    pitcher_list.insert(std::make_pair("핵터", 3.09));

    //더 간편히
    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;
    pitcher_list["캘리"] = 3.90;

    for (auto& itr : pitcher_list) {
        std::cout << itr.first << " " << itr.second << std::endl;
    }

    std::cout << "Park's value is " << pitcher_list["박종훈"] << std::endl;
    /* //정렬기준은 pair.first 즉 이름순서로 사전순 정렬된다.
     니퍼트 3.56
    박세웅 2.23
    박종훈 3.76
    장원준  3.05
    차우찬 3.04
    켈리 3.9
    피어밴드  2.95
    해커  2.93
    헥터  3.09
    박종훈의 방어율은? 3.76
     */
}