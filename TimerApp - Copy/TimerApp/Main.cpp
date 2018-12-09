#include <wx\wx.h>
#include "TimerFrame.h"
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};
IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)
bool MyApp::OnInit()
{
	TimerFrame *frame = new TimerFrame("Timer App");
	frame->Show();
	return true;
}