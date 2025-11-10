#pragma once

#include <iostream>
using namespace std;

//---------------------------------------------------
// 인터페이스 클래스: 날기 행동
class FlyBehavior {
public:
    virtual void fly() = 0;
    // 가상 소멸자 포함
    virtual ~FlyBehavior() {} 
};

// 전략 구현 클래스들
class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        cout << "I can Fly!" << endl;
    }
    virtual ~FlyWithWings() {}
};

class FlyNoWay : public FlyBehavior {
public:
    // TODO: FlyNoWay::fly() 구현
    void fly() override {
        cout << "I can't fly..." << endl;
    }
    virtual ~FlyNoWay() {}
};

//---------------------------------------------------
// 인터페이스 클래스: 꽥꽥 행동
class QuackBehavior {
public:
    virtual void quack() = 0;
    // 가상 소멸자 포함
    virtual ~QuackBehavior() {}
};

// 전략 구현 클래스들
class Quack : public QuackBehavior {
public:
    // TODO: Quack::quack() 구현
    void quack() override {
        cout << "Quack!" << endl;
    }
    virtual ~Quack() {}
};

class Squeak: public QuackBehavior {
public:
    void quack() override {
        cout << "Squeak!" << endl;
    }
    virtual ~Squeak() {}
};

class MuteQuack : public QuackBehavior {
public:
    // TODO: MuteQuack::quack() 구현
    void quack() override {
        cout << "<<Silent>>" << endl;
    }
    virtual ~MuteQuack() {}
};

// 오리 클래스 (추상 클래스)
class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    // 기본 생성자는 사용하지 않으므로 제거하거나 private/protected로 변경 가능하나, 
    // 예시 구조를 따름.
    Duck(): flyBehavior(nullptr), quackBehavior(nullptr) {}
    // 하위 클래스에서 기본 행동 설정 시 사용할 생성자
    Duck(FlyBehavior* fb, QuackBehavior* qb)
        : flyBehavior(fb), quackBehavior(qb) {}

    virtual void display() = 0;
    
    void performFly();
    void performQuack();
    void setFlyBehavior(FlyBehavior* fb);
    void setQuackBehavior(QuackBehavior* qb);

    // 가상 소멸자 (메모리 누수 방지를 위해 동적으로 할당된 행동 객체 해제)
    virtual ~Duck() {
        delete flyBehavior;
        delete quackBehavior;
    }
};

// 구체적인 오리 클래스
class MallardDuck : public Duck {
public:
    MallardDuck(); 
    void display() override {
        cout << "I'm a Mallar Duck." << endl;
    }
};

class RedheadDuck: public Duck{
public:
    RedheadDuck();
    void display() override {
        cout << "I'm a Redhead Duck." << endl;
    }
};

class RubberDuck: public Duck{
public:
    RubberDuck(); 
    void display() override {
        cout << "I'm a Rubber Duck." << endl;
    }
};

class DecoyDuck: public Duck{
public:
    DecoyDuck();
    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};

class ModelDuck: public Duck{
public:
    ModelDuck(); 
    // ModelDuck의 display 출력은 DecoyDuck과 동일
    void display() override {
        cout << "I'm a Decoy Duck." << endl; 
    }
};