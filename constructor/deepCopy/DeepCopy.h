//
// Created by hyeonbae kim on 2026. 11. 18..
//

#ifndef C_STUDY_DEEPCOPY_H
#define C_STUDY_DEEPCOPY_H

#include <iostream>
class DeepCopy {
private:
    int n;
    int* m;
public:
    DeepCopy(int n);
    DeepCopy(const DeepCopy &deepCopy);
    ~DeepCopy();
};

#endif //C_STUDY_DEEPCOPY_H
