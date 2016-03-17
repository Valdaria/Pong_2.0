#include "Game.h"

Game::Game(unsigned int width, unsigned int height, std::string winName)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), winName);
    window->setFramerateLimit(60);
    sf::Image favicon;
    if (!favicon.loadFromFile("res/favicon.png"))
		std::cout << "Favicon not loaded" << std::endl;
    window->setIcon(64,64,favicon.getPixelsPtr());

    _players.push_back(new Player(sf::Color(230, 0, 145)));
    _players.push_back(new Player(sf::Color(23, 45, 15)));
    _players[1]->getRect()->setPosition(width-_players[1]->getRect()->getSize().x,0);
    update();
}

Game::~Game()
{

}

void Game::newGame(sf::Color p1_color, sf::Color p2_color)
{

}

void Game::movePlayers()
{
    bool is_p1_moving_up = false;
    bool is_p1_moving_down = false;
    bool is_p2_moving_up = false;
    bool is_p2_moving_down = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))     {is_p1_moving_down=true;is_p1_moving_up=false;}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))     {is_p1_moving_down=false;is_p1_moving_up=true;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  {is_p2_moving_down=true;is_p2_moving_up=false;}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    {is_p2_moving_down=false;is_p2_moving_up=true;}

    if(_players[0]->canMoveUp() && !is_p1_moving_down &&  is_p1_moving_up)
         _players[0]->moveUp();
    else if(_players[0]->canMoveDown() && is_p1_moving_down && !is_p1_moving_up)
        _players[0]->moveDown();

    if(_players[1]->canMoveUp() && !is_p2_moving_down &&  is_p2_moving_up)
         _players[1]->moveUp();
    else if(_players[1]->canMoveDown() && is_p2_moving_down && !is_p2_moving_up)
        _players[1]->moveDown();
}

void Game::update()
{
    movePlayers();
    draw();
}

void Game::draw()
{
    while(this->window->isOpen()){

        sf::Event e;
        while(this->window->pollEvent(e)){
            if(e.type == sf::Event::Closed)
                this->window->close();
        }

        this->window->clear();
            for(unsigned int i(0); i< _players.size(); i++){
                window->draw(*_players[i]->getRect());
            }
        this->window->display();
        update();
    }
}
