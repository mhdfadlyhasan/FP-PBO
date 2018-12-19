#pragma once
#include "wx/wx.h"
#include "Game.h"
#include "Level.h"

class Level;

class LevelSelect : public wxPanel
{
public:
	LevelSelect(Game *parent); //menu untuk memilih level
	void OnBackButtonClick(wxCommandEvent &event);
	void OnPlayChapter1(wxCommandEvent &event);
	void OnPlayChapter2(wxCommandEvent &event);
	~LevelSelect();
	void hide();
	void shows();
private:
	Game *parent;
	DECLARE_EVENT_TABLE()
	wxButton* Level1;
	wxButton* Level2;
	wxButton* TitleScreen;
};