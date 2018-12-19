#pragma once
#include "wx\wx.h"
#include <wx\dcclient.h>
#include <wx/dcbuffer.h>
#define CONTROL 4

enum contKey
{
	keyUP = 0,
	keyDOWN,
	keyLEFT,
	keyRIGHT
};
class Player
{
private:
	int x;
	int y;
	int width;
	int height;
	int realx;
	int realy;
	int controls[CONTROL];
public:
	Player();
	Player(int x, int y, int width, int height);
	void Draw(wxAutoBufferedPaintDC & dc, int mult);
	void Move(int x, int y);
	int getControls(int KEY);
	int getX();
	int getY();
	void back();
};