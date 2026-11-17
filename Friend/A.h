#ifndef C_STUDY_FRIEND_H
#define C_STUDY_FRIEND_H

class A {
private:
    void a_private_func(){}
    int a_private_num;

    friend class B;

    friend void func();
};

class B {
public:
    void b_public_func();
};

void func();

#endif //C_STUDY_FRIEND_H
