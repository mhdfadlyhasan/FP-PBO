#pragma once
#include "wx/wx.h"
#include "MenuButton.h"


class play : public wxPanel
{
public:
	play(MenuButton* parent);
	void OnBackButtonClick(wxCommandEvent &event);
	~play();
private:
	MenuButton *parent;
	DECLARE_EVENT_TABLE()
};