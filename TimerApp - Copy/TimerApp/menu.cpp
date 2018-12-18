#include "menu.h"
#include "wx/sound.h"

BEGIN_EVENT_TABLE(menu, wxPanel)
EVT_BUTTON(1001, menu::OnPlayButtonClick)

EVT_BUTTON(1003, menu::OnPlayButtonClick)
EVT_BUTTON(13, menu::OnExitClick)

END_EVENT_TABLE()

menu::menu(MenuButton* parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	wxButton* play = new wxButton(this, 1001, wxT("play"), wxPoint(50, 50), wxSize(200, 50));	
	wxButton* exit = new wxButton(this, 13, wxT("stop"), wxPoint(50, 150), wxSize(200,50));
	SetBackgroundColour(wxColour(*wxWHITE));
}


menu::~menu()
{
}

void menu::OnPlayButtonClick(wxCommandEvent & event)
{
	parent->PlayGame();
}

void menu::OnExitClick(wxCommandEvent & event)
{
	parent->ExitGame();
}