#include <utility>

class Example {
private:
    int n{};
    int* p{};

public:
    explicit Example(int count) : n(count), p(new int[count]{}) {}

    ~Example() {
        delete[] p;
    }

    Example(const Example&) = delete;
    Example& operator=(const Example&) = delete;

    Example& operator=(Example&& rhs) noexcept {
        if (this != &rhs) {
            delete[] p;
            n = rhs.n;
            p = rhs.p;
            rhs.n = 0;
            rhs.p = nullptr;
        }
        return *this;
    }
};

int main() {
    Example ex(3);
    Example ex2(4);
    ex2 = std::move(ex);
    return 0;
}