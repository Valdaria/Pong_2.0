#include "Ball.h"

Ball::Ball(sf::Color color)
{
    _shape = new sf::RectangleShape(sf::Vector2f(10,10));
    _shape->setFillColor(color);
    _shape->setPosition(1280/2 - _shape->getSize().x/2, 720/2 - _shape->getSize().y/2);
    _ismovingUp = (bool)rand()%2;
    _ismovingLeft = (bool)rand()%2;
    _speed = 5.f;
}

Ball::~Ball()
{
    //dtor
}

sf::RectangleShape* Ball::getRect() const {return _shape;}

float Ball::getSpeed() const {return _speed;}

bool Ball::canMoveUp()
{
    if(_shape->getPosition().y +_speed >= 0) {return true;}
    return false;
}

bool Ball::canMoveDown()
{
    if(_shape->getPosition().y +_speed <= 720 - _shape->getSize().y) {return true;}
    return false;
}

bool Ball::canMoveLeft()
{
    if(_shape->getPosition().x +_speed >= 0) {return true;}
    return false;
}

bool Ball::canMoveRight()
{
    if(_shape->getPosition().x +_speed <= 1280 - _shape->getSize().x) {return true;}
    return false;
}

bool Ball::getMovingUp() const{return _ismovingUp;}

bool Ball::getMovingLeft() const{return _ismovingLeft;}


void Ball::setIsMovingUp(bool can){_ismovingUp=can;}

void Ball::setIsMovingLeft(bool can){_ismovingLeft=can;}
