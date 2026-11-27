#include <utility>

class Example {
private:
    int n{}; // 0으로 초기화
    int* p{}; // nullptr로 초기화

public:
    explicit Example(int count) : n(count), p(new int[count]{}) {}

    ~Example() {
        delete[] p;
    }

    Example(const Example&) = delete;
    Example& operator=(const Example&) = delete;

    Example(Example&& rhs) noexcept : n(rhs.n), p(rhs.p) { //이동생성자
        //이동생성자에서 n(rhs.n), p(rhs.p)부분을 본문에 넣으면 먼저 0,nullptr로 초기화 한 후 대입하는거라
        //비효율적이게 된다. 그래서 그냥 객체생성과 동시에 값 넣어주려고 초기화리스트 사용한것.
        //delete[] p; 이동생성자에는 이 코드 넣지 않는다. 왜냐면 이동대입연산자와는 달리 새로 생기는 객체라
        //기존객체가 소유하던 p가 없기 때문임
        rhs.n = 0;
        rhs.p = nullptr;
    }

    Example& operator=(Example&& rhs) noexcept { //이동대입연산자
        if (this != &rhs) { //this는 Example*타입이고 rhs는 참조그자체(Example)라 &rhs해야 주소값 표현함.
            delete[] p; //rhs.p를 이동시킬거고 현재 객체의 p를 해제시킨다.
            n = rhs.n;
            p = rhs.p; //rhs.p의 소유권 획득
            rhs.n = 0;
            rhs.p = nullptr;
        }
        return *this; //객체 그 자체가 이동대입연산자로 인해 변하기 때문에 Example&형 리턴
    }
};

int main() {
    Example ex(3);
    Example ex2(4);
    ex2 = std::move(ex); //이동 대입 연산자
    Example ex3(std::move(ex2)); //이동 생성자
    return 0;
}