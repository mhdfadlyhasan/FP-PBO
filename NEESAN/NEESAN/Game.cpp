#include "Game.h"
#include "TitleScreen.h"
#include "Level.h"

#include "LevelSelect.h"

Game::Game(const wxString & title) : wxFrame(NULL,wxID_ANY,title)
{
	this->InitComponents();
}

void Game::MainMenu()
{
	this->level->Show(false);
	this->titlescreen->Show(true);
	
	this->level->Show(false);
	fitSize();
}

void Game::PlayGame()
{
	this->level->Show(true);
	this->levelselect->Show(false);
	level->SetFocus();
	this->titlescreen->Show(false);
	fitSize();
}

void Game::LevelSelection()
{
	this->levelselect->Show(true);
	this->level->Show(false);
	level->SetFocus();
	
	this->titlescreen->Show(false);
	fitSize();
}

void Game::ExitGame()
{
	
	delete level;
	
	delete titlescreen;
	delete this;
}

void Game::fitSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1080, 720));
	this->Layout();
}

void Game::paused(bool s)
{
	this->pause = s;
}

bool Game::ispaused()
{
	return this->pause;
}

void Game::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->titlescreen = new TitleScreen(this);
	this->titlescreen->Show(false);
	this->boxSizer->Add(titlescreen, 1, wxEXPAND, 0);

	this->levelselect = new LevelSelect(this);
	this->levelselect->Show(false);
	this->boxSizer->Add(levelselect, 1, wxEXPAND, 0);


	this->level = new Level(this);
	this->level->Show(false);
	this->boxSizer->Add(level, 1, wxEXPAND, 0);


	SetSizer(boxSizer);
	MainMenu();
}

Game::~Game()
{
}