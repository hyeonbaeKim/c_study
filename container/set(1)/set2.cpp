#include <iostream>
#include <set>
#include <string>

class Todo {
    int priority;
    std::string job_desc;

public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc) {}

    friend struct TodoCmp;

    friend std::ostream& operator<< (std::ostream& o, const Todo& right);
};

//추가 : Todo클래스 내부에 operator>가 없어서 하지만 셋을 사용하기 위해
//반드시 Todo 객체간의 비교를 수행해야 하기 때문에 다음과 같은 클래스를 만들었습니다.
struct TodoCmp {
    bool operator() (const Todo& left, const Todo& right) const{
        if (left.priority == right.priority)
            return left.job_desc > right.job_desc;
        return left.priority > right.priority;
    }
};

//추가 std::cout << t 위해 추가
std::ostream& operator<< (std::ostream& o, const Todo& right) {
    o << right.priority << " " << right.job_desc;
    return o;
}

int main() {
    //Todo클래스내에 operator> 를 만들지 않으면 set을 선언할 때 비교 클래스를 지정해줘야함.
    std::set<Todo, TodoCmp> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));

    for (auto& t : todos) {
        std::cout << t << std::endl;
    }
}