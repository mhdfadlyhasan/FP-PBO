#pragma once
#include "wx/wx.h"
#include "MenuButton.h"

class help : public wxPanel
{
public:
	help(MenuButton* parent);
	~help();
private:
	MenuButton *parent;
};

