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

void Game::RenderPlayer()
{
    player_->Render(window_);
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

        if (ev_.type == sf::Event::KeyReleased &&
                (ev_.key.code == sf::Keyboard::A ||
                 ev_.key.code == sf::Keyboard::D ||
                 ev_.key.code == sf::Keyboard::W ||
                 ev_.key.code == sf::Keyboard::S ))
            player_->ResetAnimationTimer();
    }

    UpdatePlayer();
}

void Game::Render()
{
    window_.clear();

    //Render game
    RenderPlayer();


    window_.display();
}

void Game::InitWindow_()
{
    window_.create(sf::VideoMode(800, 600), "Bomberman",
            sf::Style::Close | sf::Style::Titlebar);
    window_.setFramerateLimit(60);
}

void Game::InitPlayer_()
{
    player_ = new Player();
}
