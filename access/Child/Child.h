//
// Created by robin on 2026-11-18.
//

#ifndef C_STUDY_CHILD_H
#define C_STUDY_CHILD_H
#include "../Parent/Parent.h"


class Child : public Parent{
private:
    int privateChild;
protected:
    int protectedChild;
public:
    int publicChild;

public:
    Child(int x, int y, int z);
    void childPublicMethod();
protected:
    void childProtectedMethod();
private:
    void childPrivateMethod();
};


#endif //C_STUDY_CHILD_H
