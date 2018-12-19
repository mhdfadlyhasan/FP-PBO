#include "MazeMap.h"



MazeMap::MazeMap()
{

}

char MazeMap::GetTile (int x, int y)
{
	if (x >= 0 && x < LevelWidth && y >= 0 && y < LevelHeight)
		return Map[y * LevelWidth + x];
	else
		return '*';
}

void MazeMap::Draw(wxAutoBufferedPaintDC & dc, int x, int y, int mult)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLACK), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(x * mult, y * mult), wxSize(16 * mult, 16 * mult));
}


MazeMap::~MazeMap()
{
}
