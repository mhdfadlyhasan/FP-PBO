#include "LevelMap.h"



void LevelMap::levelmap1()
{
	LevelWidth = 43;
	LevelHeight = 11;
	Map += "#########   #################   ###########";
	Map += "#                    #                    #";
	Map += "#   #####   #    #####    #############   #";
	Map += "#   #       #        #        #           #";
	Map += "#   ##############   #####    #########   #";
	Map += "#   #            #   #            #   #   #";
	Map += "#   #   #####    #   #####    #   #   #   #";
	Map += "#   #   #        #   #        #   #   #   #";
	Map += "#   #   ##########   #    #####   #   #   #";
	Map += "#       #            #        #   #       #";
	Map += "#########   ###################   #########";
}

void LevelMap::levelmap2()
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

LevelMap::LevelMap()
{

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
