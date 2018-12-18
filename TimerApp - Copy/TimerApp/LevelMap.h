#pragma once
#include <string>
#include <wx\dcclient.h>
class LevelMap
{
protected:
	int LevelWidth;
	int LevelHeight;
	std::string Map;
public:
	LevelMap();
	char GetTile(int x, int y);
	void Draw(wxPaintDC & dc, int x, int y, int mult);
	virtual void generateMap() = 0;
	~LevelMap();
};

