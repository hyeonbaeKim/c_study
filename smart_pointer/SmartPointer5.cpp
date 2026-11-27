#include <iostream>

//RAII (Resource Acquisition Is Initialization)
//자원을 획득하면, 객체의 생명주기로 관리하라!
class IntWrapper {
private:
    int *ptr;
public:
    IntWrapper(int value) {
        ptr = new int(value);
    }
    ~IntWrapper() {
        delete ptr; //객체안에서 new나 free로 동적으로 할당된 것이 있다면 소멸자에서 반드시 해제해야함
    }
};

bool somethingWrong() {
    return true;
}

int main() {
    int *ptr = new int [100];

    if (somethingWrong())
            return 0; //메모리 누수되는 상황발생 !!!!!!!!! memoryLeak !!!!!!!!!!!!!!!
    delete[] ptr; // 100개 int 배열 삭제 -> new나 free로 할당된 메모리는 delete 등으로 메모리 해제를 직접 무조건해줘야함
}//스코프 해제되며 ptr변수 삭제