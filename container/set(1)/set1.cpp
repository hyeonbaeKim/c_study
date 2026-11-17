#include <iostream>
#include <set>
#include <string>

class Todo {
private:
    int priority; //중요도. 높을 수록 급한 것.
    std::string job_desc;
public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc){}

    //insert위해 추가함
    bool operator<(const Todo& right) const{
        if (priority == right.priority) {
            return job_desc <  right.job_desc;
        }
        return priority > right.priority;
    }

    friend std::ostream& operator<<(std::ostream& o, const Todo& right);
};

//std::cout << Todo객체 하기 위해 추가됨
std::ostream& operator<<(std::ostream& o, const Todo& right) {
    //printf("priority is %d ", right.priority); 로해도 좋지만 매개변수의 의미를 살리기위해
    o << "priority is " << right.priority;
    return o;
}

int main() {
    std::set<Todo> todos; //여기까진 ok set에 내가 만든 클래스도 타입으로 들어갈 수 있음
    todos.insert(Todo(1,"농구하기")); //여기서부터 컴파일 에러
    //사실 타입이 int라면 컴파일러가 자동정렬하면서 insert하지만 컴파일러는 내가 만든 Todo클래스를 무슨 기준으로 크고 작다를 판단하는지 모름
    //그래서 operator< 가 필요함
    todos.insert(Todo(2,"수학 숙제 하기"));
    todos.insert(Todo(1,"프로그래밍 프로젝트"));
    todos.insert(Todo(3,"친구 만나기"));
    todos.insert(Todo(2,"영화 보기"));

    for (const Todo& t : todos) {
        std::cout << t << std::endl; //이번엔 operator<< (Todo) 가 없어서 컴파일 에러
        //std::cout << t의 결과로 std::cout이 나오므로 상관없다!
    }

    todos.erase(todos.find(Todo(2,"수학 숙제 하기")));

    for (const Todo& t : todos) {
        std::cout << t << std::endl;
    }

    /*
     만약에 우리가 중요도가 같을 때 따로 처리하지 않고 그냥
     bool operator<(const Todo& t) const {
        return priority > t.priority;
    } 했다면
    Todo(1, "농구 하기") < Todo(1, "프로그래밍 프로젝트");
    Todo(1, "프로그래밍 프로젝트") > Todo(1, "농구 하기");
    둘 다 false이므로 같은 원소라 판단하여 중복 허용하지 않는 set이 insert를 하지 않는다.
     */
}