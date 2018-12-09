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
	void Move(int activeKey, int xAmount, int yAmount, int maxX, int maxY);
};