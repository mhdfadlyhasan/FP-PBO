#pragma once
#include <string>
#include <wx\dcclient.h>
#include <wx/dcbuffer.h>
class MazeMap
{
protected:
	int LevelWidth;
	int LevelHeight;
	std::string Map;
public:
	MazeMap();
	char GetTile(int x, int y);
	void Draw(wxAutoBufferedPaintDC & dc, int x, int y, int mult);
	virtual void generateMap() = 0;
	~MazeMap();
};

