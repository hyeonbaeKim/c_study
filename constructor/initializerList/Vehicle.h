//
// Created by robin on 2026-11-19.
//

#ifndef C_STUDY_VEHICLE_H
#define C_STUDY_VEHICLE_H
#include <string>

class Car {
public:
    Car(std::string carName);
};

class Engine {
private:
    int power;
public:
    Engine(int power);
};

class Vehicle : public Engine {
private:
    Car car;
    /*
     Car car;	Car 객체 자체를 멤버로 소유, 생성자에서 초기화 할 필요
     Car* car;	Car 객체를 가리키는 포인터, 생성자에서 초기화 할 필요X
     */
public:
    Vehicle(int power, std::string name);
};


#endif //C_STUDY_VEHICLE_H
