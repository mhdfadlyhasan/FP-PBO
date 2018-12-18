#pragma once
#include "wx/wx.h"
class menu;
class help;
class play;
class exit; 
class SubPlay;

class MenuButton : public wxFrame
{
public:
	MenuButton(const wxString &title);
	void MainMenu();
	void HelpMenu();
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
	help* Help;
	bool pause = true;
	wxBoxSizer* boxSizer;
	SubPlay* Subplay;
};

