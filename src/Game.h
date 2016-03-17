#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
    public:
        sf::RenderWindow* window;
        Game(unsigned int width, unsigned int height, std::string winName);
        virtual ~Game();

        void newGame(sf::Color p1_color= sf::Color::White, sf::Color p2_color = sf::Color::Red);

        void movePlayers();

        void update();
        void draw();
    protected:
        std::vector<Player*> _players;
    private:
};
