#include "Game.h"

Game::Game(unsigned int width, unsigned int height, std::string winName)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), winName);
    window->setFramerateLimit(60);
    sf::Image favicon;
    if (!favicon.loadFromFile("res/favicon.png"))
		std::cout << "Favicon not loaded" << std::endl;
    window->setIcon(64,64,favicon.getPixelsPtr());

    _players.push_back(new Player(sf::Color(102,0,204)));
    _players.push_back(new Player(sf::Color(51,153,255)));

    _ball = new Ball();

    _split = new sf::RectangleShape(sf::Vector2f(1,720));
    _split->setFillColor(sf::Color::White);
    _split->setPosition(1280/2 + 0.5f, 0);
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
    bool is_p1_moving_up   = false;
    bool is_p1_moving_down = false;
    bool is_p2_moving_up   = false;
    bool is_p2_moving_down = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))      {is_p1_moving_down=true;is_p1_moving_up=false;}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {is_p1_moving_down=false;is_p1_moving_up=true;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))   {is_p2_moving_down=true;is_p2_moving_up=false;}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){is_p2_moving_down=false;is_p2_moving_up=true;}

    if     (_players[0]->canMoveUp()   && !is_p1_moving_down &&  is_p1_moving_up)
            _players[0]->moveUp();
    else if(_players[0]->canMoveDown() && is_p1_moving_down  && !is_p1_moving_up)
            _players[0]->moveDown();

    if     (_players[1]->canMoveUp()   && !is_p2_moving_down &&  is_p2_moving_up)
            _players[1]->moveUp();
    else if(_players[1]->canMoveDown() &&  is_p2_moving_down && !is_p2_moving_up)
            _players[1]->moveDown();
}

void Game::moveBall()
{
    bool canMoveUp    = _ball->canMoveUp();
    bool canMoveDown  = _ball->canMoveDown();
    bool canMoveLeft  = _ball->canMoveLeft();
    bool canMoveRight = _ball->canMoveRight();

    if(_ball->getMovingUp()    && !canMoveUp)                                   {_ball->setIsMovingUp(false);   }
    if(!_ball->getMovingUp()   && !canMoveDown)                                 {_ball->setIsMovingUp(true);    }
    if(_ball->getMovingLeft()  && (!canMoveLeft || isBallCollidingPlayer1()))   {_ball->setIsMovingLeft(false); }
    if(!_ball->getMovingLeft() && (!canMoveRight || isBallCollidingPlayer2()))  {_ball->setIsMovingLeft(true);  }


    float moveX = 0.f;
    float moveY = 0.f;
    if  (_ball->getMovingUp()){moveY= - _ball->getSpeed();}
    else                      {moveY=   _ball->getSpeed();}

    if  (_ball->getMovingLeft()){moveX= - _ball->getSpeed();}
    else                        {moveX=   _ball->getSpeed();}
    _ball->getRect()->move(moveX, moveY);
}

bool Game::isBallCollidingPlayer1()
{
    if(_ball->getRect()->getGlobalBounds().intersects(_players[0]->getRect()->getGlobalBounds()))
    {
        _ball->getRect()->setFillColor(sf::Color(102,0,204));
        return true;
    }
    return false;

}

bool Game::isBallCollidingPlayer2()
{
    if(_ball->getRect()->getGlobalBounds().intersects(_players[1]->getRect()->getGlobalBounds()))
    {
        _ball->getRect()->setFillColor(sf::Color(51,153,255));
        return true;
    }
    return false;

}

void Game::update()
{
    movePlayers();
    moveBall();
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
            this->window->draw(*_split);
            for(unsigned int i(0); i< _players.size(); i++){
                window->draw(*_players[i]->getRect());
            }
            this->window->draw(*_ball->getRect());
        this->window->display();
        update();
    }
}
