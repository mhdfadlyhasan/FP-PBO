#include "LevelSelect.h"

BEGIN_EVENT_TABLE(LevelSelect, wxPanel)
EVT_BUTTON(1001, LevelSelect::OnBackButtonClick)
EVT_BUTTON(1002, LevelSelect::OnPlayChapter1)
EVT_BUTTON(1003, LevelSelect::OnPlayChapter2)
END_EVENT_TABLE()


LevelSelect::LevelSelect(Game *parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	wxButton* TitleScreen = new wxButton(this, 1001, wxT("Back to TitleScreen"), wxPoint(600, 400), wxDefaultSize);
	wxButton* Level1 = new wxButton(this, 1002, wxT("Map1"), wxPoint(200, 400), wxDefaultSize);
	wxButton* Level2 = new wxButton(this, 1003, wxT("Map2"), wxPoint(400, 400), wxDefaultSize);
}

void LevelSelect::OnBackButtonClick(wxCommandEvent & event)
{
	parent->MainMenu();
}

void LevelSelect::OnPlayChapter1(wxCommandEvent & event)
{
	parent->PlayGame();
	parent->level->SetMap1();
	parent->paused(false);
}

void LevelSelect::OnPlayChapter2(wxCommandEvent & event)
{
	parent->PlayGame();
	parent->level->SetMap2();
	parent->paused(false);
}


LevelSelect::~LevelSelect()
{
}