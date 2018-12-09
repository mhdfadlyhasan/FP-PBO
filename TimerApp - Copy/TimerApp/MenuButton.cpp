#include "MenuButton.h"
#include "menu.h"
#include "play.h"
#include "help.h"

MenuButton::MenuButton(const wxString & title) : wxFrame(NULL,wxID_ANY,title)
{
	this->InitComponents();
}

void MenuButton::MainMenu()
{
	this->Menu->Show(true);
}

void MenuButton::InitComponents()
{
	this->Menu = new menu(this);
	this->Menu->Show(false);

	this->Help = new help(this);
	this->Help->Show(false);

	this->Play = new play(this);
	this->Play->Show(false);

	MainMenu();
}

MenuButton::~MenuButton()
{
}
