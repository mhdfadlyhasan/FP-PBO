#include "play.h"
#include "Box.h"
#include "LevelMap.h"

#define TIMER_ID 2000
BEGIN_EVENT_TABLE(play , wxPanel)
EVT_BUTTON(1001, play::OnBackButtonClick)
EVT_PAINT(play::OnPaint)
EVT_TIMER(TIMER_ID, play::OnTimer)
EVT_CHAR_HOOK(play::OnMovement)
EVT_BUTTON(1002, play::back)
EVT_BUTTON(1003, play::pause)
EVT_BUTTON(1004, play::playgame)
END_EVENT_TABLE()


void play::back(wxCommandEvent & event)
{
	timer->Start(50);
	parent->paused(false);
	snap();
	parent->PlayGame();
}

play::play(MenuButton * parent) : wxPanel(parent), parent(parent)
{
	wxCommandEvent event;
	SetBackgroundColour(wxColour(*wxWHITE));
	timer = new wxTimer(this, TIMER_ID);
	backs = new wxButton(this, 1001, wxT("Back to Main Menu"), wxPoint(400, 400), wxDefaultSize);
	submenus = new wxButton(this, 1002, wxT("Back to chapter select"), wxPoint(600, 400), wxDefaultSize);
	continues = new wxButton(this, 1004, wxT("continue"), wxPoint(200, 400), wxDefaultSize);
	pauses = new wxButton(this, 1003, wxT("pause game"), wxPoint(600, 400), wxDefaultSize);
	timer->Start(50);
	playgame(event);
}

void play::pause(wxCommandEvent &event)
{
	parent->paused(true);
	snap();
	timer->Stop();
}

void play::playgame(wxCommandEvent & event)
{
	parent->paused(false);
	snap();
	timer->Start(50);
}

void play::OnBackButtonClick(wxCommandEvent & event)
{
	parent->paused(false);
	snap();
	timer->Start(50);
	parent->MainMenu();
}

play::~play()
{
	timer->Stop();
	delete timer;
	delete Player[0];
	delete Player[1];
}

void play::OnPaint(wxPaintEvent &event)
{
	mulWidth = GetClientSize().GetWidth()/680;
	int TilesX = GetClientSize().GetWidth() / TileWidth * mulWidth;
	int TilesY = GetClientSize().GetHeight() / TileHeight * mulWidth;
	wxPaintDC pdc(this);
	this->Player[0]->Draw(pdc,mulWidth);
	this->Player[1]->Draw(pdc, mulWidth);
	for (int x = 0; x < TilesX; x++)
	{
		for (int y = 0; y < TilesY; y++)
		{
			char sTileID = this->currMap->GetTile(x, y);
			switch (sTileID)
			{
			case ' ': // Sky

				break;
			case '#': // Solid Block
				this->currMap->Draw(pdc, x * TileWidth, y * TileHeight, mulWidth);
				break;
			default:
				break;
			}
		}
	}
}


void play::OnTimer(wxTimerEvent &event)
{
	static int counter = 0;
	
	if (Player[0] != nullptr)
	{
		wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
		Refresh();
	}
}

void play::OnMovement(wxKeyEvent & event)
{
	int activekey = 0;
	if (!parent->ispaused())
	{
		int activekey = event.GetKeyCode();
		if (activekey == this->Player[0]->getControls(keyUP))
		{

			if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight - 1) == ' ' ||
				this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight - 1) == 'W')
			{
				this->Player[0]->Move(0, -16);
			}
			if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[1]->getY() / TileHeight - 1) == ' ' ||
				this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[1]->getY() / TileHeight - 1) == 'W')
			{
				this->Player[1]->Move(0, -16);
			}

		}
		else if (activekey == this->Player[0]->getControls(keyDOWN))
		{
			if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight + 1) == ' ' || 
				this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight + 1) == 'W')
			{
				this->Player[0]->Move(0, 16);
			}
			if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[1]->getY() / TileHeight + 1) == ' '|| 
				this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[1]->getY() / TileHeight + 1) == 'W')
			{
				this->Player[1]->Move(0, 16);
			}
		}
		if (activekey == this->Player[0]->getControls(keyRIGHT))
		{
			if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth + 1, this->Player[0]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->Player[0]->getX() / TileWidth + 1, this->Player[0]->getY() / TileHeight) == 'W')
			{
				this->Player[0]->Move(16, 0);
			}
			if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth + 1, this->Player[1]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->Player[1]->getX() / TileWidth + 1, this->Player[1]->getY() / TileHeight) == 'W')
			{
				this->Player[1]->Move(16, 0);
			}
		}
		else if (activekey == this->Player[0]->getControls(keyLEFT))
		{
			if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth - 1, this->Player[0]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->Player[0]->getX() / TileWidth - 1, this->Player[0]->getY() / TileHeight) == 'W')
			{
				this->Player[0]->Move(-16, 0);
			}
			if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth - 1, this->Player[1]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->Player[1]->getX() / TileWidth - 1, this->Player[1]->getY() / TileHeight) == 'W'
				)
			{
				this->Player[1]->Move(-16, 0);
			}
		}
		if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight) == 'W' && 
			this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[0]->getY() / TileHeight) == 'W')
		{
			parent->paused(true);
			snap();
		}
	}
}

void play::SetMap1()
{
	delete this->currMap;

	this->currMap = new Level_1();
	this->currMap->generateMap();
	Player[0] = new Box(144, 0, TileWidth, TileHeight);
	Player[1] = new Box(464, 0, TileWidth, TileHeight);

}

void play::snap()
{
	if (parent->ispaused())
	{
		pauses->Show(false);

		backs->Show(true);
		submenus->Show(true);
		continues->Show(true);
	}
	else
	{

		pauses->Show(!false);

		backs->Show(!true);
		submenus->Show(!true);
		continues->Show(!true);
	}
}

void play::SetMap2()
{
	delete this->currMap;
	this->currMap = new Level_2();
	this->currMap->generateMap();
	Player[0] = new Box(160, 0, TileWidth, TileHeight);
	Player[1] = new Box(464, 0, TileWidth, TileHeight);
}