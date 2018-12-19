#include "Game.h"
#include "TitleScreen.h"


BEGIN_EVENT_TABLE(TitleScreen, wxPanel)
EVT_BUTTON(1001, TitleScreen::OnPlayButtonClick)

EVT_BUTTON(1003, TitleScreen::OnPlayButtonClick)
EVT_BUTTON(13, TitleScreen::OnExitClick)

END_EVENT_TABLE()

TitleScreen::TitleScreen(Game* parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	wxButton* Level = new wxButton(this, 1001, wxT("Play"), wxPoint(50, 50), wxSize(200, 50));	
	wxButton* exit = new wxButton(this, 13, wxT("Quit"), wxPoint(50, 150), wxSize(200,50));
	SetBackgroundColour(wxColour(*wxWHITE));
}





TitleScreen::~TitleScreen()
{
}

void TitleScreen::OnPlayButtonClick(wxCommandEvent & event)
{
	parent->LevelSelection();
}

void TitleScreen::OnExitClick(wxCommandEvent & event)
{
	parent->ExitGame();
}