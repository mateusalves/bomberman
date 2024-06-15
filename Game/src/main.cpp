#include "Game.h"

int main()
{
    Game game;

    while(game.GetWindow().isOpen())
    {
        game.Update();
        game.Render();
    }

    return 0;
}
