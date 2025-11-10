#include "duck.h"

// Duck 클래스 멤버 함수 구현
void Duck::performFly(){
    // TODO: 현재 설정된 flyBehavior의 fly() 호출
    if (flyBehavior) {
        flyBehavior->fly();
    }
}

void Duck::performQuack(){
    // TODO: 현재 설정된 quackBehavior의 quack() 호출
    if (quackBehavior) {
        quackBehavior->quack();
    }
}

void Duck::setFlyBehavior(FlyBehavior* fb){
    // TODO: flyBehavior를 동적으로 변경 (이전 flyBehavior 메모리 해제 후 새 객체 연결)
    if (flyBehavior != fb) {
        delete flyBehavior; // 이전 행동 객체 메모리 해제
        flyBehavior = fb;
    }
}

void Duck::setQuackBehavior(QuackBehavior* qb){
    // TODO: quackBehavior를 동적으로 변경 (이전 quackBehavior 메모리 해제 후 새 객체 연결)
    if (quackBehavior != qb) {
        delete quackBehavior; // 이전 행동 객체 메모리 해제
        quackBehavior = qb;
    }
}


// 구체적인 오리 클래스 생성자 구현 (기본 행동 설정)
MallardDuck::MallardDuck() {
    // TODO: 기본 행동: FlyWithWings, Quack
    flyBehavior = new FlyWithWings();
    quackBehavior = new Quack();
}

RedheadDuck::RedheadDuck() {
    // TODO: 기본 행동: FlyWithWings, Quack
    flyBehavior = new FlyWithWings();
    quackBehavior = new Quack();
}

RubberDuck::RubberDuck() {
    // TODO: 기본 행동: FlyNoWay, Squeak
    flyBehavior = new FlyNoWay();
    quackBehavior = new Squeak();
}

DecoyDuck::DecoyDuck() {
    // TODO: 기본 행동: FlyNoWay, MuteQuack
    flyBehavior = new FlyNoWay();
    quackBehavior = new MuteQuack();
}

ModelDuck::ModelDuck() {
    // TODO: 기본 행동: FlyNoWay, MuteQuack
    flyBehavior = new FlyNoWay();
    quackBehavior = new MuteQuack();
}