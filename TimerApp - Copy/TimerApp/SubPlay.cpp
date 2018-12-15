#include "SubPlay.h"

BEGIN_EVENT_TABLE(SubPlay, wxPanel)
EVT_BUTTON(1001, SubPlay::OnBackButtonClick)
END_EVENT_TABLE()


SubPlay::SubPlay(MenuButton *parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	wxButton* back = new wxButton(this, 1001, wxT("Back"), wxPoint(600, 400), wxDefaultSize);
}


void SubPlay::OnBackButtonClick(wxCommandEvent & event)
{
	parent->MainMenu();
}

SubPlay::~SubPlay()
{
}
