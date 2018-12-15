#pragma once
#include "wx/wx.h"
#include "MenuButton.h"

class SubPlay : public wxPanel
{
public:
	SubPlay(MenuButton *parent);
	void OnBackButtonClick(wxCommandEvent &event);
	void OnPlayChapter1(wxCommandEvent &event);
	~SubPlay();
private:
	MenuButton *parent;
	DECLARE_EVENT_TABLE()
};

