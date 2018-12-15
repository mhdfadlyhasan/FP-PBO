#include "LevelMap.h"



LevelMap::LevelMap()
{
	LevelWidth = 61;
	LevelHeight = 20;
	Map += "############  ############################  #################";
	Map += "#       #        #            # #           #               #";
	Map += "# ####### ########  #  #  #   # #  #  ####  ####  ####   #  #";
	Map += "#       #        #  #  #  #   # #  #     #        #      #  #";
	Map += "# ####  ####  #  ####  #  ##### #  ####  ##########   #  ####";
	Map += "# #     #  #  #        #      # #     #  #     #      #     #";
	Map += "# #  ####  #  ##############  # ####  #  #  ####   #######  #";
	Map += "# #        #  #      #        #    #  #  #         #        #";
	Map += "######  ####  #    # #  ####### #  #  #  ###########  #######";
	Map += "#       #     #    # #        # #  #  #            #        #";
	Map += "# #######  #  #    #########  # ####  #  #################  #";
	Map += "# #     ####  ####   #     #  #    #  #     #            #  #";
	Map += "#    #  #            #  #     # #     #  #        ########  #";
	Map += "######  #  ###########  ####  # #######  ##########      #  #";
	Map += "#       #     #         #     # #        #     #      #     #";
	Map += "# ##########  #  #######      ###   ######  #  #  ###########";
	Map += "# #           #  #         ####          #  #  #            #";
	Map += "# #  #  #######  #  ########  # ##########  ##############  #";
	Map += "#    #        #  #            #             #               #";
	Map += "###############  ############################  ##############";
}

char LevelMap::GetTile (int x, int y)
{
	if (x >= 0 && x < LevelWidth && y >= 0 && y < LevelHeight)
		return Map[y * LevelWidth + x];
	else
		return '*';
}
void LevelMap::Draw(wxPaintDC & dc, int x, int y)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLACK), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(x, y), wxSize(16,16));
}


LevelMap::~LevelMap()
{
}
