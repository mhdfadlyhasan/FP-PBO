#pragma once
#include "wx/wx.h"
#include "MenuButton.h"
#include "LevelMap.h"
class Box;
class LevelMap;

class play : public wxPanel
{
	

public:
	play(MenuButton* parent);
	void OnBackButtonClick(wxCommandEvent &event);
	~play();
	void OnPaint(wxPaintEvent &event);
	void OnMovementCheck();
	void OnTimer(wxTimerEvent &event);
	void OnMovement(wxKeyEvent &event);

private:
	const int TileWidth = 16;
	const int TileHeight = 16;
	wxTimer *timer;
	Box *Player[2];
	LevelMap *currMap;
	MenuButton *parent;
	DECLARE_EVENT_TABLE()
};