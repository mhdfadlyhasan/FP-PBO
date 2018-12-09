#pragma once
#include "wx/wx.h"
#include "MenuButton.h"

class menu : public wxPanel
{
public:
	menu(MenuButton* parent);
	~menu();
private:
	MenuButton *parent;
	//DECLARE_EVENT_TABLE()
};

