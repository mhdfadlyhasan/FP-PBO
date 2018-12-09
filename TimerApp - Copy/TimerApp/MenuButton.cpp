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

void MenuButton::fitSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(640, 480));
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

	this->Play = new play(this);
	this->Play->Show(false);

	SetSizer(boxSizer);
	MainMenu();
}

MenuButton::~MenuButton()
{
}
