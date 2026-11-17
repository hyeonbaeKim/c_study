
#ifndef C_STUDY_STRING_H
#define C_STUDY_STRING_H


#include <cstring>

class String {
    //외부함수 너는 String클래스 이용해도 좋아.
    friend String operator+ (const char* left, const String& right);
private:
    char buffer[100];

public:
    String(const char* str = nullptr) {
        if (str == nullptr) {
            buffer[0] = '\0';
        } else {
            strcpy(buffer, str);
        }
    }

    //앞 const : 반환값을 자바의 final하는것. 즉 반환값을 수정할 수 없음
    //뒤 const : 멤버함수 const로서 이 멤버함수가 멤버변수 수정할 수 없음
    const char* getBuffer() const;

    //반환값이 그냥 값임. 왜냐면 *this로 객체자체를 수정하지 않기 위함 ex) a+b+a의 결과로 a+b를해서 a가 a+b가 되면
    //a+b+a = a+b+(a+b)가 되는 것임
    String operator+ (const char* right);

    //=는 대입으로 피연산자 객체 자체를 수정하게 되는 것이라 멤버함수 const도 안들어가고 반환값이 참조형
    String& operator= (const String& right);
};


#endif //C_STUDY_STRING_H
