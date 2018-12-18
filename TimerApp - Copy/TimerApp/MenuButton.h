#pragma once
#include "wx/wx.h"
#include <wx/sound.h>
class menu;

class play;
class exit;
class SubPlay;
	
class MenuButton : public wxFrame
{
public:
	MenuButton(const wxString &title);
	void MainMenu();
	void PlayGame();
	void PlaymapsGame();
	void ExitGame();
	void fitSize();
	void paused(bool s);
	bool ispaused();
	void InitComponents();
	~MenuButton();
	play* Play;
protected:
	menu* Menu;
	bool pause = true;
	wxBoxSizer* boxSizer;
	SubPlay* Subplay;
};