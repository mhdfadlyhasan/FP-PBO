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
	void Playmaps1Game();
	void ExitGame();
	void fitSize();
	void InitComponents();
	~MenuButton();

private:
	menu* Menu;
	help* Help;
	play* Play;
	wxBoxSizer* boxSizer;
	SubPlay* Subplay;
};

