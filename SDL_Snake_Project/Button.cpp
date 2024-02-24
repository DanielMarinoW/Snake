#include "Button.h"

Button::Button(int x, int y, int wt, int ht, GameState state)
{
    this->x = x;
    this->y = y;
    this->wt = wt;
    this->ht = ht;
    setState(state);

}

void Button::setState(GameState state)
{
    this->state = state;
}

GameState Button::getState()
{
    return this->state;
}

bool Button::isClicked(int mouseX, int mouseY)
{
    return (mouseX >= x && mouseX <= wt &&
        mouseY >= y && mouseY <= ht);

}
