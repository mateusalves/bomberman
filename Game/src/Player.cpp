#include "Player.h"


Player::Player()
{
    InitTexture_();
    InitSprite_();
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Render(sf::RenderTarget& target)
{
    target.draw(sprite_);
}

void Player::InitTexture_()
{
}

void Player::InitSprite_()
{
}

