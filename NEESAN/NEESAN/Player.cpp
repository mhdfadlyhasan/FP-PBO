#include "Player.h"

Player::Player()
{
}

void Player::back()
{
	this->x = this->realx;
	this->y = this->realy;
}
Player::Player(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height), realx(x),realy(y)
{
	controls[keyUP] = WXK_CONTROL_W + 64;
	controls[keyDOWN] = WXK_CONTROL_S + 64;
	controls[keyRIGHT] = WXK_CONTROL_D + 64;
	controls[keyLEFT] = WXK_CONTROL_A + 64;
}
void Player::Draw(wxAutoBufferedPaintDC &dc, int mult)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxGREEN), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x * mult, this->y * mult), wxSize(width * mult, height * mult));
}
void Player::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

int Player::getControls(int KEY)
{
	return controls[KEY];
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}
