#include "help.h"
BEGIN_EVENT_TABLE(help, wxPanel)
EVT_BUTTON(1001, help::OnBackButtonClick)
END_EVENT_TABLE()


help::help(MenuButton* parent) : wxPanel(parent, wxID_ANY), parent(parent)
{
	wxButton* back = new wxButton(this, 1001, wxT("Back"), wxPoint(100, 100), wxDefaultSize);
}

void help::OnBackButtonClick(wxCommandEvent & event)
{
	parent->MainMenu();
}

help::~help()
{
}
