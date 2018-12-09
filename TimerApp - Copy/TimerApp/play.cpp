#include "play.h"

BEGIN_EVENT_TABLE(play , wxPanel)
EVT_BUTTON(1001, play::OnBackButtonClick)
END_EVENT_TABLE()

play::play(MenuButton* parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	wxButton* back = new wxButton(this, 1001, wxT("Back to Main Menu"), wxPoint(100, 100), wxDefaultSize);
}


void play::OnBackButtonClick(wxCommandEvent & event)
{
	parent->MainMenu();
}

play::~play()
{
}
