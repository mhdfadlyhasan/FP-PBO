#pragma once
#include "wx/wx.h"
#include "MenuButton.h"

class help : public wxPanel
{
public:
	help(MenuButton* parent);
	void OnBackButtonClick(wxCommandEvent &event);
	~help();
private:
	MenuButton *parent;
	DECLARE_EVENT_TABLE()
};

