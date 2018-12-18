#include "MenuButton.h"
#include "menu.h"
#include "play.h"
#include "help.h"
#include "SubPlay.h"

MenuButton::MenuButton(const wxString & title) : wxFrame(NULL,wxID_ANY,title)
{
	this->InitComponents();
}

void MenuButton::MainMenu()
{
	this->Subplay->Show(false);
	this->Menu->Show(true);
	this->Help->Show(false);
	this->Play->Show(false);
	fitSize();
}

void MenuButton::HelpMenu()
{
	this->Subplay->Show(false);
	this->Help->Show(true);
	this->Menu->Show(false);
	this->Play->Show(false);
	fitSize();
}

void MenuButton::PlaymapsGame()
{
	this->Play->Show(true);
	this->Subplay->Show(false);
	Play->SetFocus();
	this->Help->Show(false);
	this->Menu->Show(false);
	fitSize();
}

void MenuButton::PlayGame()
{
	this->Subplay->Show(true);
	this->Play->Show(false);
	Play->SetFocus();
	this->Help->Show(false);
	this->Menu->Show(false);
	fitSize();
}

void MenuButton::ExitGame()
{
	
	delete Play;
	delete Help;
	delete Menu;
	delete this;
}

void MenuButton::fitSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1080, 720));
	this->Layout();
}

void MenuButton::paused(bool s)
{
	this->pause = s;
}

bool MenuButton::ispaused()
{
	return this->pause;
}

void MenuButton::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->Menu = new menu(this);
	this->Menu->Show(false);
	this->boxSizer->Add(Menu, 1, wxEXPAND, 0);

	this->Subplay = new SubPlay(this);
	this->Subplay->Show(false);
	this->boxSizer->Add(Subplay, 1, wxEXPAND, 0);

	this->Help = new help(this);
	this->Help->Show(false);
	this->boxSizer->Add(Help, 1, wxEXPAND, 0);

	this->Play = new play(this);
	this->Play->Show(false);
	this->boxSizer->Add(Play, 1, wxEXPAND, 0);


	SetSizer(boxSizer);
	MainMenu();
}

MenuButton::~MenuButton()
{
}
