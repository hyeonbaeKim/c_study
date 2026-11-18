//
// Created by hyeonbae kim on 2026. 11. 18..
//

#ifndef C_STUDY_SHALLOWCOPY_H
#define C_STUDY_SHALLOWCOPY_H


class ShallowCopy {
private:
    int n;
    int m;
public:
    ShallowCopy(int n, int m);
    ShallowCopy(const ShallowCopy &);
    ~ShallowCopy();
};


#endif //C_STUDY_SHALLOWCOPY_H
