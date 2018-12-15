#pragma once
#include "wx\wx.h"
#include <wx\dcclient.h>
#define CONTROL 4

enum contKey
{
	keyUP = 0,
	keyDOWN,
	keyLEFT,
	keyRIGHT
};
class Box
{
private:
	int x;
	int y;
	int width;
	int height;
	int controls[CONTROL];
	
public:
	Box();
	Box(int x, int y, int width, int height);
	void Draw(wxPaintDC &dc);
	void Move(int x, int y);
	void setPos(int x, int y);
	int getControls(int KEY);
	int getX();
	int getY();



};