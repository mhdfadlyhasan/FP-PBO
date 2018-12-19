#include <wx\wx.h>
#include "Game.h"


class MyApp : public wxApp
{
public:
	virtual bool OnInit();

};
IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	Game *frame = new Game("Game");
	frame->Show();
	return true;
}