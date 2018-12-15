#include "play.h"
#include "Box.h"
#include "LevelMap.h"

#define TIMER_ID 2000
BEGIN_EVENT_TABLE(play , wxPanel)
EVT_BUTTON(1001, play::OnBackButtonClick)
EVT_PAINT(play::OnPaint)
EVT_TIMER(TIMER_ID, play::OnTimer)
EVT_CHAR_HOOK(play::OnMovement)
END_EVENT_TABLE()


play::play(MenuButton * parent) : wxPanel(parent), parent(parent)
{
	wxButton* back = new wxButton(this, 1001, wxT("Back to Main Menu"), wxPoint(100, 100), wxDefaultSize);
	SetBackgroundColour(wxColour(*wxWHITE));
	timer = new wxTimer(this, TIMER_ID);
	timer->Start(50);
	Player[0] = new Box(0, 0, TileWidth, TileHeight);
	Player[1] = new Box(144, 144, TileWidth, TileHeight);
	currMap = new LevelMap();
}

void play::OnBackButtonClick(wxCommandEvent & event)
{
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
	int TilesX = GetClientSize().GetWidth() / TileWidth;
	int TilesY = GetClientSize().GetHeight() / TileHeight;
	wxPaintDC pdc(this);
	this->Player[0]->Draw(pdc);
	this->Player[1]->Draw(pdc);
	for (int x = 0; x < TilesX; x++)
	{
		for (int y = 0; y < TilesY; y++)
		{
			char sTileID = this->currMap->GetTile(x, y);
			switch (sTileID)
			{
			case '.': // Sky

				break;
			case '#': // Solid Block
				this->currMap->Draw(pdc, x * TileWidth, y * TileHeight);
				break;
			default:
				break;
			}
		}
	}
}
void play::OnMovementCheck()
{

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
	int activekey = event.GetKeyCode();
	if (activekey == this->Player[0]->getControls(keyUP))
	{

		if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight - 1) == '.')
		{
			this->Player[0]->Move(0, -16);
		}
		if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[1]->getY() / TileHeight - 1) == '.')
		{
			this->Player[1]->Move(0, -16);
		}

	}
	else if (activekey == this->Player[0]->getControls(keyDOWN))
	{
		if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth, this->Player[0]->getY() / TileHeight + 1) == '.')
		{
			this->Player[0]->Move(0, 16);
		}
		if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth, this->Player[1]->getY() / TileHeight + 1) == '.')
		{
			this->Player[1]->Move(0, 16);
		}
	}
	if (activekey == this->Player[0]->getControls(keyRIGHT))
	{
		if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth + 1, this->Player[0]->getY() / TileHeight) == '.')
		{
			this->Player[0]->Move(16, 0);
		}
		if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth + 1, this->Player[1]->getY() / TileHeight) == '.')
		{
			this->Player[1]->Move(16, 0);
		}
	}
	else if (activekey == this->Player[0]->getControls(keyLEFT))
	{
		if (this->currMap->GetTile(this->Player[0]->getX() / TileWidth - 1, this->Player[0]->getY() / TileHeight) == '.')
		{
			this->Player[0]->Move(-16, 0);
		}
		if (this->currMap->GetTile(this->Player[1]->getX() / TileWidth - 1, this->Player[1]->getY() / TileHeight) == '.')
		{
			this->Player[1]->Move(-16, 0);
		}
	}


}



