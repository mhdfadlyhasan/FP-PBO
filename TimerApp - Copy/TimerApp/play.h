#pragma once
#include "wx/wx.h"
#include "MenuButton.h"
#include "LevelMap.h"
#include "Level_1.h"
#include "Level_2.h"
class Box;
class LevelMap;

class play : public wxPanel
{
public:
	play(MenuButton* parent);
	void back(wxCommandEvent &event);
	void OnBackButtonClick(wxCommandEvent &event);
	~play();
	void OnPaint(wxPaintEvent &event);
	void OnMovementCheck();
	void OnTimer(wxTimerEvent &event);
	void OnMovement(wxKeyEvent &event);
	void SetMap1();
	void SetMap2();

private:
	const int TileWidth = 16;
	const int TileHeight = 16;
	wxTimer *timer;
	Box *Player[2];
	LevelMap *currMap;
	
	MenuButton *parent;
	DECLARE_EVENT_TABLE()
};