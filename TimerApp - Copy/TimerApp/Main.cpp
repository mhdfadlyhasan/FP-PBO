#include <wx\wx.h>
#include "MenuButton.h"
class MyApp : public wxApp
{
public:
	virtual bool OnInit();

};
IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	MenuButton *frame = new MenuButton("Timer App");
	frame->Show();
	return true;
}