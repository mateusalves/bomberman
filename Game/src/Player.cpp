#include "Player.h"


Player::Player()
{
    InitVariables_();
    InitTexture_();
    InitSprite_();
    InitAnimations_();
    InitPhysics_();
}

Player::~Player()
{

}

void Player::Update()
{
    UpdateMovement_();
    UpdateAnimations_();
    UpdatePhysics_();
}

void Player::Render(sf::RenderTarget& target)
{
    target.draw(sprite_);
}

void Player::InitTexture_()
{
    if(!textureSheet_.loadFromFile("../Textures/player_sheet.png"))
        std::cout << "[ERROR]: Player Class could not load the player sheet!\n";
}

void Player::InitSprite_()
{
    sprite_.setTexture(textureSheet_);
    currentFrame_ = sf::IntRect(0, 0, 40, 50); //bomberman 32, 32

    sprite_.setTextureRect(currentFrame_);
    sprite_.setScale(5.5f, 5.5f);
}

void Player::InitVariables_()
{
    animState_ = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::Move_(const float dir_x, const float dir_y)
{
    //Acceleration
    velocity_.x += dir_x * acceleration_;
    //velocity_.y += dir_y * acceleration_; //Gravity

    //Limit Velocity
    if(std::abs(velocity_.x) > velocityMax_)
    {
        velocity_.x = velocityMax_ * ((velocity_.x < 0.f)? -1.f: 1.f);
    }
}

void Player::UpdateMovement_()
{
    animState_ = PLAYER_ANIMATION_STATES::IDLE;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
    {
        //was: sprite_.move(-1.f, 0.f);
        Move_(-1.f, 0.f);
        animState_ = PLAYER_ANIMATION_STATES::MOVING_LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
    {
        //was: sprite_.move(1.f, 0.f);
        Move_(1.f, 0.f);
        animState_ = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
    }

    //else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //top
    //{
        //sprite_.move(0.f, -1.f);
    //}
    //else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
    //{
        //sprite_.move(0.f, 1.f);
    //}
}

void Player::InitAnimations_()
{
    animationTimer_.restart();
    animationSwitch = true;
}

void Player::UpdateAnimations_()
{
    if(animState_ == PLAYER_ANIMATION_STATES::IDLE)
    {
        if (animationTimer_.getElapsedTime().asSeconds() >= 0.2f || GetAnimSwitch_())
        {
            currentFrame_.top = 0.f;
            currentFrame_.left += 40.f;
            if (currentFrame_.left >= 160.f)
                currentFrame_.left = 0;

            animationTimer_.restart();
            sprite_.setTextureRect(currentFrame_);
        }
    }
    else if(animState_ == PLAYER_ANIMATION_STATES::MOVING_RIGHT || GetAnimSwitch_())
    {
        if (animationTimer_.getElapsedTime().asSeconds() >= 0.1f)
        {
            currentFrame_.top = 50.f;
            currentFrame_.left += 40.f;
            if (currentFrame_.left >= 360.f)
                currentFrame_.left = 0;

            animationTimer_.restart();
            sprite_.setTextureRect(currentFrame_);
        }
    }
    else
        animationTimer_.restart();
}

void Player::InitPhysics_()
{
    velocityMax_ = 15.f;
    velocityMin_ = 1.f;
    acceleration_ = 2.f;
    drag_ = 0.94f;
    gravity_ = 4.f;
    velocityMaxY_ = 15.f;
}

void Player::UpdatePhysics_()
{
    //Gravity
    velocity_.y += 1.0 * gravity_;

    if(std::abs(velocity_.y) > velocityMaxY_)
    {
        velocity_.y = velocityMaxY_ * ((velocity_.y < 0.f)? -1.f: 1.f);
    }

    //Deceleration
    velocity_ *= drag_;

    //Limit Deceleration
    if (std::abs(velocity_.x) < velocityMin_)
        velocity_.x = 0.f;
    if (std::abs(velocity_.y) < velocityMin_)
        velocity_.y = 0.f;

    sprite_.move(velocity_);
}

void Player::ResetAnimationTimer()
{
    animationTimer_.restart();
    animationSwitch = true;
}

const bool Player::GetAnimSwitch_()
{
    bool anim_switch = animationSwitch;
    if(animationSwitch)
        animationSwitch = false;
    return anim_switch;
}
