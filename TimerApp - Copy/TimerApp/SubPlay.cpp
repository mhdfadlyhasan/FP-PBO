#include "SubPlay.h"

BEGIN_EVENT_TABLE(SubPlay, wxPanel)
EVT_BUTTON(1001, SubPlay::OnBackButtonClick)
EVT_BUTTON(1002, SubPlay::OnPlayChapter1)
END_EVENT_TABLE()


SubPlay::SubPlay(MenuButton *parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	wxButton* menu = new wxButton(this, 1001, wxT("Back to menu"), wxPoint(600, 400), wxDefaultSize);
	wxButton* play1 = new wxButton(this, 1002, wxT("Map1"), wxPoint(200, 400), wxDefaultSize);
}


void SubPlay::OnBackButtonClick(wxCommandEvent & event)
{
	parent->MainMenu();
}

void SubPlay::OnPlayChapter1(wxCommandEvent & event)
{
	parent->Playmaps1Game();
}


SubPlay::~SubPlay()
{
}
