#include "TimerWindow.h"
#include "Box.h"
#define TIMER_ID 2000
BEGIN_EVENT_TABLE(TimerWindow, wxWindow)
EVT_PAINT(TimerWindow::OnPaint)
EVT_TIMER(TIMER_ID, TimerWindow::OnTimer)
EVT_KEY_UP(TimerWindow::OnMovement)
END_EVENT_TABLE()
TimerWindow::TimerWindow(wxFrame *frame)
	: wxWindow(frame, wxID_ANY)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	timer = new wxTimer(this, TIMER_ID);
	timer->Start(50);
	box = new Box(10, 10, 50, 50);
}
TimerWindow::~TimerWindow()
{
	timer->Stop();
	delete timer;
	delete box;
}
void TimerWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	this->box->Draw(pdc);
}
void TimerWindow::OnMovement(wxKeyEvent & event)
{
	this->box->Move(event.GetKeyCode());
	
}
void TimerWindow::OnTimer(wxTimerEvent &event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
	if (box != nullptr)
	{
		this->OnMovement();
		Refresh();
	}
}


