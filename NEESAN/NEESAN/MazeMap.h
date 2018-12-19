#pragma once
#include <string>
#include <wx\dcclient.h>
#include <wx/dcbuffer.h>
class MazeMap
{
protected:
	int LevelWidth;
	int LevelHeight;
	std::string Map; //digunakan untuk menggambarkan map(hitbox dan goal)
public:
	MazeMap();
	char GetTile(int x, int y); // digunakan untuk me-return char yang menggambarkan map
	void Draw(wxAutoBufferedPaintDC & dc, int x, int y, int mult);
	virtual void generateMap() = 0;
	~MazeMap();
};

