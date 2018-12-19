#include "Level.h"
#include "Player.h"
#include "MazeMap.h"

#define TIMER_ID 2000
BEGIN_EVENT_TABLE(Level , wxPanel)
EVT_BUTTON(1001, Level::OnBackButtonClick)
EVT_PAINT(Level::OnPaint)
EVT_TIMER(TIMER_ID, Level::OnTimer)
EVT_CHAR_HOOK(Level::OnMovement)
EVT_BUTTON(1002, Level::back)
EVT_BUTTON(1003, Level::pause)
EVT_BUTTON(1004, Level::playgame)
EVT_BUTTON(1005, Level::retrys)
END_EVENT_TABLE()

Level::Level(Game * parent) : wxPanel(parent), parent(parent)
{
	wxCommandEvent event;
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	timer = new wxTimer(this, TIMER_ID);
	backs = new wxButton(this, 1001, wxT("Back to Main Menu"), wxPoint(400, 320 ), wxDefaultSize);
	submenus = new wxButton(this, 1002, wxT("Back to chapter select"), wxPoint(600, 320), wxDefaultSize);
	pauses = new wxButton(this, 1003, wxT("Pause Game"), wxPoint(600, 320), wxDefaultSize);
	continues = new wxButton(this, 1004, wxT("continue"), wxPoint(200, 320), wxDefaultSize);
	retry = new wxButton(this, 1005, wxT("retry game"), wxPoint(300, 320), wxDefaultSize);
	timer->Start(50);
	this->retry->Show(true);
	playgame(event);
}

void Level::back(wxCommandEvent & event)
{
	

	timer->Start(50);
	parent->paused(false);
	snap();
	parent->LevelSelection();

}


void Level::pause(wxCommandEvent &event)
{

	wxPoint test = this->GetPosition();
	parent->paused(true);
	snap();

}

void Level::playgame(wxCommandEvent & event)
{
	parent->paused(false);
	snap();
	timer->Start(50);
}

void Level::OnBackButtonClick(wxCommandEvent & event)
{
	parent->paused(false);
	snap();
	timer->Start(50);
	parent->MainMenu();
}

Level::~Level()
{
	timer->Stop();
	delete timer;
	delete player[0];
	delete player[1];
}

void Level::OnPaint(wxPaintEvent &event)
{
	mulWidth = GetClientSize().GetWidth() / 680; //mulWidth digunakan untuk me-resize isi level
	int TilesX = GetClientSize().GetWidth() / TileWidth * mulWidth;
	int TilesY = GetClientSize().GetHeight() / TileHeight * mulWidth;
	RepositionButton(); //digunakan untuk mengatur posisi button jika di-resize
	wxAutoBufferedPaintDC pdc(this); // double buffering agar tidak flicker
	PaintBackground(pdc);
	this->player[0]->Draw(pdc,mulWidth);
	this->player[1]->Draw(pdc, mulWidth);
	for (int x = 0; x < TilesX; x++)// digunakan untuk menggambar map berdasarkan string yang ada di LevelMap
	{
		for (int y = 0; y < TilesY; y++)
		{
			char TileID = this->currMap->GetTile(x, y);
			if (TileID == '#') 
			{
				this->currMap->Draw(pdc, x * TileWidth, y * TileHeight, mulWidth);
			}

		}
	}
}

void Level::PaintBackground(wxDC & dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxWHITE)));
	dc.SetPen(wxPen(wxColour(*wxWHITE), 1));
	wxRect windowRect(wxPoint(0, 0), GetClientSize());
	dc.DrawRectangle(windowRect);
}

void Level::OnTimer(wxTimerEvent &event)
{
	static int counter = 0;
	
	if (player[0] != nullptr)
	{
		wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
		Refresh();
	}
}

void Level::OnMovement(wxKeyEvent & event)
{
	int activekey = 0;
	if (!parent->ispaused())
	{
		//digunakan untuk menegecek jika player sudah mencapai goal
		if (this->currMap->GetTile(this->player[0]->getX() / TileWidth, this->player[0]->getY() / TileHeight) == 'W' &&
			this->currMap->GetTile(this->player[1]->getX() / TileWidth, this->player[0]->getY() / TileHeight) == 'W')
		{
			parent->paused(true);
			snap();
			this->continues->Show(false);
		}

		int activekey = event.GetKeyCode();
		//digunakan untuk pergerakan, mengecek jika tile yang dituju valid atau tidak ('#' berarti tembok)
		if (activekey == this->player[0]->getControls(keyUP))
		{

			if (this->currMap->GetTile(this->player[0]->getX() / TileWidth, this->player[0]->getY() / TileHeight - 1) == ' ' ||
				this->currMap->GetTile(this->player[0]->getX() / TileWidth, this->player[0]->getY() / TileHeight - 1) == 'W')
			{
				this->player[0]->Move(0, -16);
			}
			if (this->currMap->GetTile(this->player[1]->getX() / TileWidth, this->player[1]->getY() / TileHeight - 1) == ' ' ||
				this->currMap->GetTile(this->player[1]->getX() / TileWidth, this->player[1]->getY() / TileHeight - 1) == 'W')
			{
				this->player[1]->Move(0, -16);
			}

		}
		else if (activekey == this->player[0]->getControls(keyDOWN))
		{
			if (this->currMap->GetTile(this->player[0]->getX() / TileWidth, this->player[0]->getY() / TileHeight + 1) == ' ' || 
				this->currMap->GetTile(this->player[0]->getX() / TileWidth, this->player[0]->getY() / TileHeight + 1) == 'W')
			{
				this->player[0]->Move(0, 16);
			}
			if (this->currMap->GetTile(this->player[1]->getX() / TileWidth, this->player[1]->getY() / TileHeight + 1) == ' '|| 
				this->currMap->GetTile(this->player[1]->getX() / TileWidth, this->player[1]->getY() / TileHeight + 1) == 'W')
			{
				this->player[1]->Move(0, 16);
			}
		}
		if (activekey == this->player[0]->getControls(keyRIGHT))
		{
			if (this->currMap->GetTile(this->player[0]->getX() / TileWidth + 1, this->player[0]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->player[0]->getX() / TileWidth + 1, this->player[0]->getY() / TileHeight) == 'W')
			{
				this->player[0]->Move(16, 0);
			}
			if (this->currMap->GetTile(this->player[1]->getX() / TileWidth + 1, this->player[1]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->player[1]->getX() / TileWidth + 1, this->player[1]->getY() / TileHeight) == 'W')
			{
				this->player[1]->Move(16, 0);
			}
		}
		else if (activekey == this->player[0]->getControls(keyLEFT))
		{
			if (this->currMap->GetTile(this->player[0]->getX() / TileWidth - 1, this->player[0]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->player[0]->getX() / TileWidth - 1, this->player[0]->getY() / TileHeight) == 'W')
			{
				this->player[0]->Move(-16, 0);
			}
			if (this->currMap->GetTile(this->player[1]->getX() / TileWidth - 1, this->player[1]->getY() / TileHeight) == ' ' ||
				this->currMap->GetTile(this->player[1]->getX() / TileWidth - 1, this->player[1]->getY() / TileHeight) == 'W'
				)
			{
				this->player[1]->Move(-16, 0);
			}
		}

	}
}

void Level::SetMap1() //digunakan untuk menampilkan level 1
{
	delete player[0], player[1];
	delete this->currMap;

	this->currMap = new Level_1();
	this->currMap->generateMap();
	player[0] = new Player(144, 0, TileWidth, TileHeight);
	player[1] = new Player(464, 0, TileWidth, TileHeight);

}

void Level::snap() // menampilkan pause menu
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

void Level::SetMap2() //digunakan untuk menampilkan level 
{
	delete player[0], player[1];
	delete this->currMap;
	this->currMap = new Level_2();
	this->currMap->generateMap();
	player[0] = new Player(160, 0, TileWidth, TileHeight);
	player[1] = new Player(464, 0, TileWidth, TileHeight);
}

void Level::retrys(wxCommandEvent &event)
{
	playgame(event);
	player[0]->back();
	player[1]->back();
}

void Level::RepositionButton() //digunakan untuk mengatur posisi button jika di-resize
{
	backs->SetPosition( wxPoint(400, 320 * mulWidth));
	submenus->SetPosition(wxPoint(600, 320 * mulWidth));
	pauses->SetPosition(wxPoint(600, 320 * mulWidth));
	continues->SetPosition(wxPoint(200, 320 * mulWidth));
	retry->SetPosition(wxPoint(300, 320 * mulWidth));
}
