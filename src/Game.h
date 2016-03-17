#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class Game
{
    public:
        sf::RenderWindow* window;
        Game(unsigned int width, unsigned int height, std::string winName);
        virtual ~Game();

        void newGame(sf::Color p1_color= sf::Color::White, sf::Color p2_color = sf::Color::Red);

        void movePlayers();
        void moveBall();

        void update();
        void draw();
    protected:
        std::vector<Player*> _players;
        Ball* _ball;
        sf::RectangleShape* _split;
    private:
};
