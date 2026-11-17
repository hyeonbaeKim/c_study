//
// Created by robin on 2026-11-17.
//

#ifndef C_STUDY_OSTREAM_H
#define C_STUDY_OSTREAM_H


class Ostream {
public:
    const Ostream& operator<<(int i) const;
    const Ostream& operator<<(const char* s) const;
    const Ostream& operator<<(float f) const;
    const Ostream& operator<<( void(*fp)() ) const;
};

void endl();

#endif //C_STUDY_OSTREAM_H
