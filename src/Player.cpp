#include "Player.h"

Player::Player(sf::Color playerColor)
{
    _rect = new sf::RectangleShape(sf::Vector2f(10, 60));
    _rect->setFillColor(playerColor);
    _speed = 6.f;
    _defaultSpeed = 6.f;
}

Player::~Player()
{

}

float Player::getSpeed() const {return _speed;}

bool Player::canMoveUp()
{
    if(_rect->getPosition().y - _speed >= 0){return true;}
    return false;
}

bool Player::canMoveDown()
{
    if(_rect->getPosition().y + _rect->getSize().y + _speed <= 720){return true;}
    return false;
}

void Player::moveUp()
{
    _rect->move(0,- _speed);
}

void Player::moveDown()
{
    _rect->move(0,_speed);
}

void Player::increaseSpeed() {_speed = _defaultSpeed*1.5f;}
void Player::decreaseSpeed() {_speed = _defaultSpeed*0.75f;}
void Player::resetSpeed() {_speed = _defaultSpeed;}

sf::RectangleShape* Player::getRect() const {return this->_rect;}
