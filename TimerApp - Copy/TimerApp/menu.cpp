#include "menu.h"

BEGIN_EVENT_TABLE(menu, wxPanel)
EVT_BUTTON(1001, menu::OnPlayButtonClick)
EVT_BUTTON(1002, menu::OnHelpButtonClick)
EVT_BUTTON(1003, menu::OnPlayButtonClick)
EVT_BUTTON(13, menu::OnExitClick)

END_EVENT_TABLE()

menu::menu(MenuButton* parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	wxButton* play = new wxButton(this, 1001, wxT("play"), wxPoint(50, 50), wxDefaultSize);
	wxButton* help = new wxButton(this, 1002, wxT("help"), wxPoint(100, 100), wxDefaultSize);
	wxButton* exit = new wxButton(this, 13, wxT("stop"), wxPoint(150, 150), wxDefaultSize);
}


menu::~menu()
{
}

void menu::OnHelpButtonClick(wxCommandEvent &event)
{
	parent->HelpMenu();
}

void menu::OnPlayButtonClick(wxCommandEvent & event)
{
	parent->PlayGame();
}

void menu::OnExitClick(wxCommandEvent & event)
{
	parent->ExitGame();
}
