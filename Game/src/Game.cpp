#include "Game.h"

Game::Game()
{
    InitWindow_();
    InitPlayer_();
}

Game::~Game()
{
    delete player_;
}

const sf::RenderWindow& Game::GetWindow() const
{
    return window_;
}

void Game::UpdatePlayer()
{
    player_->Update();
}

void Game::Update()
{
    //Polling window events
    while(window_.pollEvent(ev_))
    {
        if(ev_.type == sf::Event::Closed)
            window_.close();
        else if (ev_.type == sf::Event::KeyPressed && ev_.key.code == sf::Keyboard::Escape)
            window_.close();

    }

    UpdatePlayer();
}

void Game::Render()
{
    window_.clear();

    //Render game



    window_.display();
}

void Game::InitWindow_()
{
    window_.create(sf::VideoMode(800, 600), "Bomberman",
            sf::Style::Close | sf::Style::Titlebar);
}

void Game::InitPlayer_()
{
    player_ = new Player();
}
