#pragma once

enum GameState { START, INFO,UNKNOWN};

class Button
{
public:
	Button(int x, int y, int wt, int ht,GameState state);
	void setState(GameState state);
	GameState getState();
	bool isClicked(int mouseX, int mouseY);

private:

	int x;
	int y;
	int wt;
	int ht;
	GameState state;

};

