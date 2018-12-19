#pragma once
#include "wx/wx.h"
#include "Game.h"


class TitleScreen : public wxPanel
{
public:
	TitleScreen(Game* parent);
	~TitleScreen();
	
	void OnPlayButtonClick(wxCommandEvent &event);
	void OnExitClick(wxCommandEvent &event);
private:
	Game *parent;
	DECLARE_EVENT_TABLE()
};