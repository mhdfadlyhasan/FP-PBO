#include "SubPlay.h"

BEGIN_EVENT_TABLE(SubPlay, wxPanel)
EVT_BUTTON(1001, SubPlay::OnBackButtonClick)
EVT_BUTTON(1002, SubPlay::OnPlayChapter1)
EVT_BUTTON(1003, SubPlay::OnPlayChapter2)
END_EVENT_TABLE()


SubPlay::SubPlay(MenuButton *parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	wxButton* menu = new wxButton(this, 1001, wxT("Back to menu"), wxPoint(600, 400), wxDefaultSize);
	wxButton* play1 = new wxButton(this, 1002, wxT("Map1"), wxPoint(200, 400), wxDefaultSize);
	wxButton* play2 = new wxButton(this, 1003, wxT("Map2"), wxPoint(400, 400), wxDefaultSize);
}


void SubPlay::OnBackButtonClick(wxCommandEvent & event)
{
	parent->MainMenu();
}

void SubPlay::OnPlayChapter1(wxCommandEvent & event)
{
	parent->PlaymapsGame();
	parent->Play->SetMap1();
	parent->paused(false);
}

void SubPlay::OnPlayChapter2(wxCommandEvent & event)
{
	parent->PlaymapsGame();
	parent->Play->SetMap2();
	parent->paused(false);

}


SubPlay::~SubPlay()
{
}
