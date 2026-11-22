#include <utility>
#include <iostream>
#include <string>

void storeByValue(std::string s) {
    std::string b = s;
}
void storeByLRef(std::string &s) {
    std::string b = s;
}
void storeByRRef(std::string &&s) {
    std::string b = std::move(s);
    //Rvalue s로 받았어도 함수안에서는 s를 재사용할 수 있기 때문에 다시 rvalue로 바꾸어줌
}
void storeByConstLRef(const std::string& s) { //Lvalue, Rvalue다 받을 수 있는데
    std::string b = s; // 여기서는 b를 만들기 위해 복사
    //const키워드는 rvalue취급시킬 수 없음 즉 std::move(s)불가능
}

int main() {

    int a = 0; //l value 와 r value
    int b = a; // l value 와 r value
    //즉 r value는 한번만 쓰여지는 값 (temporary)
    int c = std::move(a); //l value와 std::move를 통해 a를 temporary한 r value로 변환

    std::string str = "abc";
    storeByValue(str);
    storeByLRef(str);
    //storeByRRef(str); //wrong!
    storeByRRef(std::move(str));
    storeByRRef("abc");
    return 0;
}

/*값은 복사가 되며 std::string들이 "abc"를 복사되어 갖는다. -> 2copy
 *a
 *s
 *b
 *---
 *"abc"
 *"abc"
 *"abc"
*/

/*StoreByLRef -> 1copy
 *a
 *&s //는 lvalue를 넘겨받아 a와 같은 abc를 가리키게되고
 *b //얜 값을 복사받아 abc를 새롭게 갖는다.
 *----
 *abc
 *
 *abc
 */

/*StoreByRRef -> 0 copy
 *&&s rvlaue Ref로서 "abc"를 갖는다.
 *b가 std::move를 통해 abc의 소유권을 갖는다
 *----
 *abc
 *
 */