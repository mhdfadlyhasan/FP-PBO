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
	this->Help->Show(false);
	this->Play->Show(false);
	fitSize();
}

void MenuButton::HelpMenu()
{
	this->Help->Show(true);
	this->Menu->Show(false);
	this->Play->Show(false);
	fitSize();
}

void MenuButton::PlayGame()
{
	this->Play->Show(true);
	this->Help->Show(false);
	this->Menu->Show(false);
	fitSize();
}

void MenuButton::ExitGame()
{
	delete this;
}

void MenuButton::fitSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(2000, 1000));
	this->Layout();
}

void MenuButton::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->Menu = new menu(this);
	this->Menu->Show(false);
	this->boxSizer->Add(Menu, 1, wxEXPAND, 0);

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
