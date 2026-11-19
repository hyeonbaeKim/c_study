//
// Created by robin on 2026-11-19.
//

#include "Vehicle.h"
#include <iostream>
Car::Car(std::string carName) {
    std::cout << "Car생성자 " << carName << std::endl;
}

Engine::Engine(int power) {
    this->power = power;
    std::cout << "Engine 생성자 완료" << std::endl;
}

Vehicle::Vehicle(int power, std::string name)
    : Engine(power), //부모 클래스 초기화. 부모 클래스에 기본 생성자가 없다면 반드시 명시해야 함
      car(name) { //일반 멤버 객체 초기화. 기본 생성자가 없는 멤버 객체라면 반드시 명시해야 함
    //포인터 멤버 객체는 초기화 할 필요X 언제나 필요할 때 메모리 생성하면 된다.
    std::cout << "Vehicle생성자 완료" << std::endl;
}

int main() {
    Vehicle* vehicle = new Vehicle(3, "German Car");
}

/*
 Engine 생성자 완료
 Car생성자 German Car
 Vehicle생성자 완료
 */