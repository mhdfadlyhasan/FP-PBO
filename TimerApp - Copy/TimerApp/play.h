#pragma once
#include "wx/wx.h"
#include "MenuButton.h"
class play : public wxPanel
{
public:
	play(MenuButton* parent);
	~play();
private:
	MenuButton *parent;
};

