#include <iostream>
#include <iterator>
#include "Student.h"
int main() {
    std::string name[] = {"kim","lee"};
    //std::string name2[2] = {"kim","lee"};
    //std::string name2[]{"kim","lee"};
    int age[] = {10,9};
    int grade[] = {90,80};

    /*
     [JAVA]
        String[] name = {"kim", "lee"};
        name.length;       // 배열 원소 수: 2
        name[0].length(); // 첫 번째 문자열 길이: 3
     [C++]
     배열 원소 수는 std::size(name),
     각 std::string의 글자 수는 name[i].length()
     */

    for (int i=0; i < std::size(name); i++) {
        std::cout << name[i] << " " << age[i] << " " << grade[i] << std::endl;
    }

    /*
     타입이 같은 것들끼리 배열처리하였다.
     3번째 학생을 추가하기 위해서는 3번째에 정확히 원소를 다 새로 넣어야 하고
     2번째 학생을 지우기 위해서는 2번째에 정확히 원소를 다 지워져야 한다.
     */
}
