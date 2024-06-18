#pragma once

#include "Common.h"

enum PLAYER_ANIMATION_STATES
{
    IDLE = 0,
    MOVING_LEFT,
    MOVING_RIGHT,
    MOVING_UP,
    MOVING_DOWN,
    JUMPING,
    THROWING,
    DYING
};

class Player
{
public:
    Player();
    virtual ~Player();

public:
    void Update();
    void Render(sf::RenderTarget& target);
    void ResetAnimationTimer();

private:
    void Move_(const float dir_x, const float dir_y);

    void InitTexture_();
    void InitSprite_();
    void InitAnimations_();
    void InitVariables_();
    void InitPhysics_();

    void UpdateMovement_();
    void UpdateAnimations_();
    void UpdatePhysics_();

    void ResetAnimationTimer_();
    const bool GetAnimSwitch_();

private:
    sf::Sprite sprite_;
    sf::Texture textureSheet_;
    sf::Clock animationTimer_;

    //Animation
    short animState_;
    sf::IntRect currentFrame_;
    bool animationSwitch;

    //Physics
    sf::Vector2f velocity_;
    float velocityMax_;
    float velocityMin_;
    float acceleration_;
    float drag_;
    float gravity_;
    float velocityMaxY_;
};
