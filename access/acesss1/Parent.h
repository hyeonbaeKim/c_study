//
// Created by robin on 2026-11-18.
//

#ifndef C_STUDY_PARENT_H
#define C_STUDY_PARENT_H


class Parent {
private:
    int privateParent;
protected:
    int protectedParent;
public:
    int publicParent;
public:
    Parent(int x, int y, int z);
    void publicParentMethod();
private:
    void privateParentMethod();
protected:
    void protectedParentMethod();
};


#endif //C_STUDY_PARENT_H
