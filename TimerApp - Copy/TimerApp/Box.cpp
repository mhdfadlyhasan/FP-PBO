#include "Box.h"

Box::Box()
{
}

void Box::back()
{
	this->x = this->realx;
	this->y = this->realy;
}
Box::Box(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height), realx(x),realy(y)
{
	controls[keyUP] = WXK_CONTROL_W + 64;
	controls[keyDOWN] = WXK_CONTROL_S + 64;
	controls[keyRIGHT] = WXK_CONTROL_D + 64;
	controls[keyLEFT] = WXK_CONTROL_A + 64;
}
void Box::Draw(wxPaintDC &dc, int mult)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxGREEN), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x * mult, this->y * mult), wxSize(width * mult, height * mult));
}
void Box::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}
void Box::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Box::getControls(int KEY)
{
	return controls[KEY];
}

int Box::getX()
{
	return x;
}

int Box::getY()
{
	return y;
}
