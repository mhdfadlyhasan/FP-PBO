#pragma once
#include <wx\wx.h>
class Box;
class LevelMap;
class TimerWindow : public wxWindow
{
public:
	TimerWindow(wxFrame *frame);
	~TimerWindow();
	void OnPaint(wxPaintEvent &event);
	void OnMovementCheck();
	void OnTimer(wxTimerEvent &event);
	void OnMovement(wxKeyEvent &event);

private:
	const int TileWidth = 16;
	const int TileHeight = 16;
	wxTimer *timer;
	Box *Player[2];
	LevelMap *currMap;
	DECLARE_EVENT_TABLE()
};