#pragma once

#include "Common.h"
#include "Player.h"

class Game
{
public:
    Game();
    virtual ~Game();

public:
    const sf::RenderWindow& GetWindow() const;

    void UpdatePlayer();
    void Update();
    void Render();

private:
    void InitWindow_();
    void InitPlayer_();

private:
    sf::RenderWindow window_;
    sf::Event ev_;
    Player* player_; //DI here? Smartpointer?

};
