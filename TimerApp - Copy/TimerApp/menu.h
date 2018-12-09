#pragma once
#include "wx/wx.h"
#include "MenuButton.h"

class menu : public wxPanel
{
public:
	menu(MenuButton* parent);
	~menu();
	void OnHelpButtonClick(wxCommandEvent &event);
	void OnPlayButtonClick(wxCommandEvent &event);
	void OnExitClick(wxCommandEvent &event);
private:
	MenuButton *parent;
	DECLARE_EVENT_TABLE()
};

