#pragma once

#include "Common.h"

class Player
{
public:
    Player();
    virtual ~Player();

public:
    void Update();
    void Render(sf::RenderTarget& target);

private:
    void InitTexture_();
    void InitSprite_();


    //Animation

    //Movement

    //Core

private:
    sf::Sprite sprite_;
    sf::Texture textureSheet_;

};
