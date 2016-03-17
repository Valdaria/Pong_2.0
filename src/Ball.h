#pragma once

#include <SFML/Graphics.hpp>
#include <random>
class Ball
{
    public:
        Ball(sf::Color color=sf::Color::White);
        virtual ~Ball();

        sf::RectangleShape* getRect() const;

        float getSpeed() const;

        bool canMoveUp();
        bool canMoveDown();
        bool canMoveLeft();
        bool canMoveRight();

        bool getMovingUp() const;
        bool getMovingLeft() const;
        void setIsMovingUp(bool can);
        void setIsMovingLeft(bool can);

    protected:
        sf::RectangleShape* _shape;

        bool _ismovingUp;
        bool _ismovingLeft;

        float _speed;
    private:
};
