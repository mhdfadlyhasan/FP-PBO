#pragma once

#include "wx/wx.h"
#include "Game.h"
#include "MazeMap.h"
#include "Level_1.h"
#include "Level_2.h"
class Player;
class MazeMap;

class Level : public wxPanel
{
public:
	
	Level(Game * parent);
	void back(wxCommandEvent &event);
	void pause(wxCommandEvent &event);
	void playgame(wxCommandEvent &event);
	void OnBackButtonClick(wxCommandEvent &event);
	~Level();
	void OnPaint(wxPaintEvent &event);
	void PaintBackground(wxDC & dc);
	void OnTimer(wxTimerEvent &event);
	void OnMovement(wxKeyEvent &event);
	void SetMap1();
	void snap();
	void SetMap2();
	void retrys(wxCommandEvent &event);
	void RepositionButton();

private:
	wxButton* backs;
	wxButton* retry;
	wxButton* submenus;
	wxButton* continues;
	wxButton* pauses;
	const int TileWidth = 16;
	const int TileHeight = 16;
	wxTimer *timer;
	Player *player[2];
	MazeMap *currMap;
	int mulWidth;
	Game *parent;
	DECLARE_EVENT_TABLE()
};