#pragma once
#include "wx/wx.h"

class TitleScreen;
class Level;
class LevelSelect;
	
class Game : public wxFrame
{
public:
	Game(const wxString &title);
	void MainMenu();
	void LevelSelection();
	void PlayGame();
	void ExitGame();
	void fitSize();
	void paused(bool s);
	bool ispaused();
	void InitComponents();
	~Game();
	Level* level;
private:


	TitleScreen* titlescreen;
	bool pause = true;
	wxBoxSizer* boxSizer;
	LevelSelect* levelselect;
};