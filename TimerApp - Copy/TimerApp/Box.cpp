#include "Box.h"

Box::Box()
{
}
Box::Box(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height)
{
	controls[keyUP] = WXK_CONTROL_W;
	controls[keyDOWN] = WXK_CONTROL_S;
	controls[keyRIGHT] = WXK_CONTROL_D;
	controls[keyLEFT] = WXK_CONTROL_A;
}
void Box::Draw(wxPaintDC &dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxGREEN), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(this->width,
		this->height));
}
void Box::Move(int activekey, int xAmount, int yAmount, int maxX, int maxY)
{
	if (activekey == controls[keyUP])
	{

	}
	else if (activekey == controls[keyDOWN])
	{

	}
	else if (activekey == controls[keyRIGHT])
	{

	}
	else if (activekey == controls[keyLEFT])
	{

	}
}