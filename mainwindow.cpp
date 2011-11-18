#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
		#########################################
		# 0 empty
		# 1 field
		# 2 wall
		# 3 destination
		# 4 box
		# 5 completed box
		# 6 player
		# 7 player on destination
		#########################################
		*/

    int levels[20][16][16] = {
        {	//LEVEL 1
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,0,2,1,3,2,0,0,0,0,0,0,0},
                {0,0,0,0,0,2,1,1,2,2,2,0,0,0,0,0},
                {0,0,0,0,0,2,5,6,1,1,2,0,0,0,0,0},
                {0,0,0,0,0,2,1,1,4,1,2,0,0,0,0,0},
                {0,0,0,0,0,2,1,1,2,2,2,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 2
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0},
                {0,0,0,0,2,1,1,1,1,1,2,0,0,0,0,0},
                {0,0,0,0,2,1,2,6,1,1,2,0,0,0,0,0},
                {0,0,0,0,2,1,4,5,1,1,2,0,0,0,0,0},
                {0,0,0,0,2,1,3,5,1,2,0,0,0,0,0,0},
                {0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0},
                {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 3
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,2,2,1,1,2,2,2,0,0,0,0,0},
                {0,0,0,2,1,1,1,1,1,4,1,2,0,0,0,0},
                {0,0,0,2,1,2,1,1,2,4,1,2,0,0,0,0},
                {0,0,0,2,1,3,1,3,2,6,1,2,0,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 4
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0},
                {0,0,0,0,2,1,1,1,1,1,2,0,0,0,0,0},
                {0,0,0,0,2,1,3,4,3,1,2,0,0,0,0,0},
                {0,0,0,0,2,1,4,6,4,1,2,0,0,0,0,0},
                {0,0,0,2,1,1,3,4,3,1,2,0,0,0,0,0},
                {0,0,0,2,1,1,1,1,1,1,2,0,0,0,0,0},
                {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 5
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0},
                {0,0,0,2,1,1,1,1,1,1,2,0,0,0,0,0},
                {0,0,0,2,1,3,5,5,4,6,2,0,0,0,0,0},
                {0,0,0,2,1,1,1,1,1,1,2,0,0,0,0,0},
                {0,0,0,0,2,2,2,2,1,1,2,0,0,0,0,0},
                {0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 6
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,0,2,3,1,1,2,0,0,0,0,0,0},
                {0,0,0,0,2,1,4,6,4,1,2,0,0,0,0,0},
                {0,0,0,0,2,1,1,4,3,1,2,0,0,0,0,0},
                {0,0,0,0,0,2,1,1,3,2,0,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 7
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
                {0,0,2,3,1,1,1,1,1,1,1,1,1,2,0,0},
                {0,0,2,1,2,2,2,1,1,1,1,1,1,2,0,0},
                {0,0,2,1,1,1,3,1,1,1,1,1,1,2,0,0},
                {0,0,2,1,2,2,2,1,1,1,1,1,1,2,0,0},
                {0,0,2,1,1,4,1,4,4,1,1,1,1,2,0,0},
                {0,0,2,3,2,1,1,1,1,1,1,1,6,2,0,0},
                {0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 8
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,0,2,6,1,2,2,2,2,1,1,1,1,1,2,0},
                {0,0,2,1,4,1,2,2,2,1,1,1,1,1,2,0},
                {0,0,2,1,1,4,1,2,2,1,1,1,2,3,2,0},
                {0,0,2,1,3,1,4,1,2,2,1,1,2,2,2,0},
                {0,0,2,1,1,1,1,1,1,1,1,1,1,1,2,0},
                {0,0,2,1,1,1,1,1,1,1,3,1,1,1,2,0},
                {0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 9
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,2,2,1,1,3,2,2,0,0,0,0,0},
                {0,0,0,2,1,3,4,1,4,1,1,2,0,0,0,0},
                {0,0,0,2,1,1,4,6,4,1,1,2,0,0,0,0},
                {0,0,0,2,1,3,1,2,1,1,1,2,0,0,0,0},
                {0,0,0,0,2,2,1,2,3,2,2,0,0,0,0,0},
                {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 10
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0},
                {0,0,2,6,1,1,2,0,2,2,2,0,0,0,0,0},
                {0,0,2,1,4,4,2,0,2,3,2,2,2,2,0,0},
                {0,0,2,1,1,1,1,2,1,3,1,3,1,2,0,0},
                {0,0,2,2,1,1,1,1,1,1,1,4,1,2,0,0},
                {0,0,0,2,1,1,1,1,1,1,2,2,2,2,0,0},
                {0,0,0,2,1,1,1,2,1,1,2,0,0,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 11
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,2,2,2,2,2,0,2,2,2,2,2,0,0,0},
                {0,0,2,1,1,1,2,2,2,1,1,1,2,0,0,0},
                {0,0,2,1,5,1,1,6,1,1,4,1,2,0,0,0},
                {0,0,2,1,4,1,1,2,1,5,2,2,2,0,0,0},
                {0,0,2,1,3,2,2,2,1,1,1,3,2,0,0,0},
                {0,0,2,2,2,2,0,2,2,2,2,2,2,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 12
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
                {0,2,2,3,1,1,1,1,1,1,1,1,2,2,0,0},
                {0,2,1,2,1,1,1,1,1,1,1,2,1,2,0,0},
                {0,2,1,1,2,1,1,1,1,1,2,1,1,2,0,0},
                {0,2,1,1,4,1,1,1,1,1,1,1,1,2,0,0},
                {0,2,1,1,1,2,2,2,4,2,1,1,1,2,0,0},
                {0,2,4,1,2,6,5,1,1,3,4,1,1,2,0,0},
                {0,2,3,2,2,2,2,2,1,2,1,1,1,2,0,0},
                {0,2,2,3,1,5,1,1,1,1,1,1,1,2,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 13
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0},
                {0,0,0,2,3,1,1,1,1,3,2,0,0,0,0,0},
                {0,0,0,2,1,2,1,2,1,2,2,0,0,0,0,0},
                {0,0,0,2,4,1,4,1,4,1,2,0,0,0,0,0},
                {0,0,0,2,3,1,1,1,4,7,2,0,0,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {	//LEVEL 14
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0},
                {0,0,2,3,1,3,1,3,1,1,1,3,2,0,0,0},
                {0,0,2,2,4,2,4,2,4,2,1,2,2,0,0,0},
                {0,0,2,1,1,4,1,4,1,4,1,3,2,0,0,0},
                {0,0,2,4,1,1,1,1,1,1,4,1,2,0,0,0},
                {0,0,2,3,2,1,2,7,2,1,2,3,2,0,0,0},
                {0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{	//LEVEL 15
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                {0,2,3,3,2,3,3,2,2,2,2,2,1,1,1,2},
                {0,2,3,3,2,1,1,1,1,4,1,1,1,4,1,2},
                {0,2,1,1,1,4,1,2,2,2,2,2,1,2,2,2},
                {0,2,1,1,1,1,1,1,1,1,1,1,4,1,1,2},
                {0,2,1,1,2,4,1,1,4,1,1,1,1,1,2,2},
                {0,2,4,4,2,1,4,1,1,1,1,1,1,1,1,2},
                {0,2,3,3,2,1,1,4,4,2,2,4,1,1,1,2},
                {0,2,3,3,2,1,1,1,1,2,7,1,1,2,3,2},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{	//LEVEL 16
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,2,3,3,2,3,3,2,2,2,2,2,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,4,1,1,1,4,1,2},
		{0,2,1,1,1,4,1,2,2,2,2,2,1,2,2,2},
		{0,2,1,1,1,1,1,1,1,1,1,1,4,1,1,2},
		{0,2,1,1,2,4,1,1,4,1,1,1,1,1,2,2},
		{0,2,4,4,2,1,4,1,1,1,1,1,1,1,1,2},
		{0,2,3,3,2,1,1,4,4,2,2,4,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,2,6,1,1,2,3,2},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{	//LEVEL 17
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,2,3,3,2,3,3,2,2,2,2,2,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,4,1,1,1,4,1,2},
		{0,2,1,1,1,4,1,2,2,2,2,2,1,2,2,2},
		{0,2,1,1,1,1,1,1,1,1,1,1,4,1,1,2},
		{0,2,1,1,2,4,1,1,4,1,1,1,1,1,2,2},
		{0,2,4,4,2,1,4,1,1,1,1,1,1,1,1,2},
		{0,2,3,3,2,1,1,4,4,2,2,4,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,2,6,1,1,2,3,2},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{	//LEVEL 18
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,2,3,3,2,3,3,2,2,2,2,2,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,4,1,1,1,4,1,2},
		{0,2,1,1,1,4,1,2,2,2,2,2,1,2,2,2},
		{0,2,1,1,1,1,1,1,1,1,1,1,4,1,1,2},
		{0,2,1,1,2,4,1,1,4,1,1,1,1,1,2,2},
		{0,2,4,4,2,1,4,1,1,1,1,1,1,1,1,2},
		{0,2,3,3,2,1,1,4,4,2,2,4,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,2,6,1,1,2,3,2},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{	//LEVEL 19
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,2,3,3,2,3,3,2,2,2,2,2,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,4,1,1,1,4,1,2},
		{0,2,1,1,1,4,1,2,2,2,2,2,1,2,2,2},
		{0,2,1,1,1,1,1,1,1,1,1,1,4,1,1,2},
		{0,2,1,1,2,4,1,1,4,1,1,1,1,1,2,2},
		{0,2,4,4,2,1,4,1,1,1,1,1,1,1,1,2},
		{0,2,3,3,2,1,1,4,4,2,2,4,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,2,6,1,1,2,3,2},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{	//LEVEL 20
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,2,3,3,2,3,3,2,2,2,2,2,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,4,1,1,1,4,1,2},
		{0,2,1,1,1,4,1,2,2,2,2,2,1,2,2,2},
		{0,2,1,1,1,1,1,1,1,1,1,1,4,1,1,2},
		{0,2,1,1,2,4,1,1,4,1,1,1,1,1,2,2},
		{0,2,4,4,2,1,4,1,1,1,1,1,1,1,1,2},
		{0,2,3,3,2,1,1,4,4,2,2,4,1,1,1,2},
		{0,2,3,3,2,1,1,1,1,2,6,1,1,2,3,2},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	}
    };

    numberOfLevels=20;
    moves=0;
    currentLevel=15;
    ui->lblLevel->setText("Level "+QString::number(currentLevel+1));

    for (int n = 0; n < numberOfLevels; ++n) {
        for (int x = 0; x < 16; ++x) {
            for (int y = 0; y < 16; ++y) {
                this->levels[n][x][y]=levels[n][x][y];
                if (n==currentLevel){
                    currentContent[x][y]=levels[n][x][y];
                    resetContent[x][y]=levels[n][x][y];
                     if (currentContent[x][y] ==6 || currentContent[x][y] ==7){
                        playerCurrentX = x;
                        playerCurrentY = y;
                    }
                }
            }
        }
    }

    for (int x = 0; x < 16; ++x) {
        for (int y = 0; y < 16; ++y) {
            currentImages[y][x] = new QLabel(this);
            currentImages[y][x]->setGeometry(x*30,y*30,30,30);
        }
    }
    drawLevel();
    this->addAction(ui->actionUp);
    this->addAction(ui->actionDown);
    this->addAction(ui->actionLeft);
    this->addAction(ui->actionRigth);
    this->addAction(ui->actionUp_2);
    this->addAction(ui->actionDown_2);
    this->addAction(ui->actionLeft_2);
    this->addAction(ui->actionRigth_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOrientation(ScreenOrientation orientation)
{
#if defined(Q_OS_SYMBIAN)
    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }
#endif // Q_OS_SYMBIAN

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}

void MainWindow::showExpanded()
{
#ifdef Q_OS_SYMBIAN
    showFullScreen();
#elif defined(Q_WS_MAEMO_5)
    showFullScreen();
#else
    show();
#endif
}

void MainWindow::randomColors(){

    srand (QTime::currentTime().msec());

    wallColor  = rand() % 10;
    srand (QTime::currentTime().msec());

    fieldColor = rand() % 2;
    srand (QTime::currentTime().msec());

    playerColor = rand() % 2;
    srand (QTime::currentTime().msec());

    boxColor = rand() % 2;
    srand (QTime::currentTime().msec());

    destinationColor = rand() % 3;
}

void MainWindow::drawLevel(){
    /*
                #########################################
                # 0 empty
                # 1 field
                # 2 wall
                # 3 destination
                # 4 box
                # 5 completed box
                # 6 player
                # 7 player on destination
                #########################################
                */

    for (int j = 0;j < 16; ++j) {
        for (int i = 0; i< 16; ++i) {
            if (currentContent[i][j] == 0){
                currentImages[i][j]->setStyleSheet("");
            }else if (currentContent[i][j] == 1){
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
            }else if (currentContent[i][j] == 2){
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/walls/wall_"+QString::number(wallColor)+".png);}");
            }else if (currentContent[i][j] == 3){
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
            }else if ( currentContent[i][j] == 4){
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
            }else if ( currentContent[i][j] == 5) {
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
            }else if ( currentContent[i][j] == 6){
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
            }else if ( currentContent[i][j] == 7){
                currentImages[i][j]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
            }else{
                currentImages[i][j]->setStyleSheet("");
            }
        }
    }
}

void MainWindow::isWinner(){
    this->repaint();
    ui->lblMoves->setText("Moves "+QString::number(moves)+"");
    int boxesNotCompleted = 0;

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (currentContent[i][j]==4){
                boxesNotCompleted++;
            }
        }
    }
    if (boxesNotCompleted == 0){
        ui->lblMoves->setText("Level Completed");
        this->repaint();
        if (currentLevel<numberOfLevels-1){
            incLevel();
        }else{
            ui->lblMoves->setText("Game finished");
        }
    }
}

void MainWindow::incLevel(){
    moves=0;
    randomColors();
    currentLevel = currentLevel ++;
    ui->lblLevel->setText("Level "+QString::number(currentLevel+1));
    for (int i=0;i<16;i++){
        for (int j=0;j<16;j++){
            currentContent[i][j] = levels[currentLevel][i][j];
            resetContent[i][j] = levels[currentLevel][i][j];
            if (currentContent[i][j] ==6 || currentContent[i][j] ==7){
                playerCurrentX = i;
                playerCurrentY = j;
            }
        }
    }
    drawLevel();

}

void MainWindow::on_btnLeft_pressed(){
    bool hasMoved = false;

    if (playerCurrentY > 0){
        if (currentContent[playerCurrentX][playerCurrentY-1] == 1 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX][playerCurrentY-1] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX][playerCurrentY-1] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }else if (currentContent[playerCurrentX][playerCurrentY-1] == 3 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX][playerCurrentY-1] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX][playerCurrentY-1] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }
    }

    if (playerCurrentY > 1 && hasMoved == false){
        if (currentContent[playerCurrentX][playerCurrentY] == 6){
            if ( currentContent[playerCurrentX][playerCurrentY-1] == 4  && hasMoved == false){
                if ( currentContent[playerCurrentX][playerCurrentY-2] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX][playerCurrentY-1] = 6;
                    currentContent[playerCurrentX][playerCurrentY-2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if (currentContent[playerCurrentX][playerCurrentY-2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX][playerCurrentY-1] = 6;
                    currentContent[playerCurrentX][playerCurrentY-2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }else if (currentContent[playerCurrentX][playerCurrentY-1] == 5 && hasMoved == false){
                if (currentContent[playerCurrentX][playerCurrentY-2] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX][playerCurrentY-1] = 7;
                    currentContent[playerCurrentX][playerCurrentY-2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX][playerCurrentY-2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY]= 1;
                    currentContent[playerCurrentX][playerCurrentY-1] = 7;
                    currentContent[playerCurrentX][playerCurrentY-2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
            if (currentContent[playerCurrentX][playerCurrentY-1] == 4  && hasMoved == false){
                if (currentContent[playerCurrentX][playerCurrentY-2] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY-1] = 6;
                    currentContent[playerCurrentX][playerCurrentY-2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX][playerCurrentY-2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY-1] = 6;
                    currentContent[playerCurrentX][playerCurrentY-2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }else if (currentContent[playerCurrentX][playerCurrentY-1] == 5 && hasMoved == false){
                if (currentContent[playerCurrentX][playerCurrentY-2]== 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY-1] = 7;
                    currentContent[playerCurrentX][playerCurrentY-2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX][playerCurrentY-2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY-1] = 7;
                    currentContent[playerCurrentX][playerCurrentY-2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY-2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }
    }
}

void MainWindow::on_btnRigth_pressed(){
    bool hasMoved = false;
    if (playerCurrentY > 0){
        if (currentContent[playerCurrentX][playerCurrentY+1] == 1 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX][playerCurrentY+1] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX][playerCurrentY+1] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }else if (currentContent[playerCurrentX][playerCurrentY+1] == 3 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX][playerCurrentY+1] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX][playerCurrentY+1] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentY = playerCurrentY+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }
    }

    if (playerCurrentY > 1 && hasMoved == false){
        if (currentContent[playerCurrentX][playerCurrentY] == 6){
            if ( currentContent[playerCurrentX][playerCurrentY+1] == 4  && hasMoved == false){
                if ( currentContent[playerCurrentX][playerCurrentY+2] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX][playerCurrentY+1] = 6;
                    currentContent[playerCurrentX][playerCurrentY+2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if (currentContent[playerCurrentX][playerCurrentY+2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX][playerCurrentY+1] = 6;
                    currentContent[playerCurrentX][playerCurrentY+2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }else if (currentContent[playerCurrentX][playerCurrentY+1] == 5 && hasMoved == false){
                if (currentContent[playerCurrentX][playerCurrentY+2] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX][playerCurrentY+1] = 7;
                    currentContent[playerCurrentX][playerCurrentY+2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX][playerCurrentY+2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY]= 1;
                    currentContent[playerCurrentX][playerCurrentY+1] = 7;
                    currentContent[playerCurrentX][playerCurrentY+2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
            if (currentContent[playerCurrentX][playerCurrentY+1] == 4  && hasMoved == false){
                if (currentContent[playerCurrentX][playerCurrentY+2] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY+1] = 6;
                    currentContent[playerCurrentX][playerCurrentY+2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX][playerCurrentY+2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY+1] = 6;
                    currentContent[playerCurrentX][playerCurrentY+2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }else if (currentContent[playerCurrentX][playerCurrentY+1] == 5 && hasMoved == false){
                if (currentContent[playerCurrentX][playerCurrentY+2]== 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY+1] = 7;
                    currentContent[playerCurrentX][playerCurrentY+2] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX][playerCurrentY+2] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX][playerCurrentY+1] = 7;
                    currentContent[playerCurrentX][playerCurrentY+2] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+1]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX][playerCurrentY+2]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentY = playerCurrentY+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }
    }
}

void MainWindow::on_btnUp_pressed(){
    bool hasMoved = false;
    if (playerCurrentX < 15){
        if (currentContent[playerCurrentX-1][playerCurrentY] == 1 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX-1][playerCurrentY] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX-1][playerCurrentY] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }

        else if (currentContent[playerCurrentX-1][playerCurrentY] == 3 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX-1][playerCurrentY] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if ( currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX-1][playerCurrentY] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX-1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }
    }

    if ( playerCurrentX < 14 && hasMoved == false){
        if ( currentContent[playerCurrentX][playerCurrentY] == 6){
            if ( currentContent[playerCurrentX-1][playerCurrentY] == 4  && hasMoved == false){
                if ( currentContent[playerCurrentX-2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX-1][playerCurrentY] = 6;
                    currentContent[playerCurrentX-2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX-2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX-1][playerCurrentY] = 6;
                    currentContent[playerCurrentX-2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }else if ( currentContent[playerCurrentX-1][playerCurrentY] == 5 && hasMoved == false){
                if ( currentContent[playerCurrentX-2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX-1][playerCurrentY] = 7;
                    currentContent[playerCurrentX-2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX-2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX-1][playerCurrentY] = 7;
                    currentContent[playerCurrentX-2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
            if (currentContent[playerCurrentX-1][playerCurrentY] == 4  && hasMoved == false){
                if (currentContent[playerCurrentX-2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX-1][playerCurrentY] = 6;
                    currentContent[playerCurrentX-2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX-2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX-1][playerCurrentY] = 6;
                    currentContent[playerCurrentX-2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
            else if (currentContent[playerCurrentX-1][playerCurrentY] == 5 && hasMoved == false){
                if (currentContent[playerCurrentX-2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX-1][playerCurrentY] = 7;
                    currentContent[playerCurrentX-2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX-2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX-1][playerCurrentY] = 7;
                    currentContent[playerCurrentX-2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX-1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX-2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX-1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }
    }
}

void MainWindow::on_btnDown_pressed(){
    bool hasMoved = false;
    if (playerCurrentX < 15){
        if (currentContent[playerCurrentX+1][playerCurrentY] == 1 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX+1][playerCurrentY] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX+1][playerCurrentY] = 6;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }

        else if (currentContent[playerCurrentX+1][playerCurrentY] == 3 && hasMoved == false){
            if (currentContent[playerCurrentX][playerCurrentY] == 6){
                currentContent[playerCurrentX][playerCurrentY] = 1;
                currentContent[playerCurrentX+1][playerCurrentY] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }else if ( currentContent[playerCurrentX][playerCurrentY] == 7){
                currentContent[playerCurrentX][playerCurrentY] = 3;
                currentContent[playerCurrentX+1][playerCurrentY] = 7;
                currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                playerCurrentX = playerCurrentX+1;
                moves = moves + 1;
                isWinner();
                hasMoved = true;
            }
        }
    }

    if ( playerCurrentX < 14 && hasMoved == false){
        if ( currentContent[playerCurrentX][playerCurrentY] == 6){
            if ( currentContent[playerCurrentX+1][playerCurrentY] == 4  && hasMoved == false){
                if ( currentContent[playerCurrentX+2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX+1][playerCurrentY] = 6;
                    currentContent[playerCurrentX+2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX+2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX+1][playerCurrentY] = 6;
                    currentContent[playerCurrentX+2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }else if ( currentContent[playerCurrentX+1][playerCurrentY] == 5 && hasMoved == false){
                if ( currentContent[playerCurrentX+2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX+1][playerCurrentY] = 7;
                    currentContent[playerCurrentX+2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX+2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 1;
                    currentContent[playerCurrentX+1][playerCurrentY] = 7;
                    currentContent[playerCurrentX+2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }else if (currentContent[playerCurrentX][playerCurrentY] == 7){
            if (currentContent[playerCurrentX+1][playerCurrentY] == 4  && hasMoved == false){
                if (currentContent[playerCurrentX+2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX+1][playerCurrentY] = 6;
                    currentContent[playerCurrentX+2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX+2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX+1][playerCurrentY] = 6;
                    currentContent[playerCurrentX+2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/players/player_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
            else if (currentContent[playerCurrentX+1][playerCurrentY] == 5 && hasMoved == false){
                if (currentContent[playerCurrentX+2][playerCurrentY] == 1 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX+1][playerCurrentY] = 7;
                    currentContent[playerCurrentX+2][playerCurrentY] = 4;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/boxes/box_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }else if ( currentContent[playerCurrentX+2][playerCurrentY] == 3 && hasMoved == false){
                    currentContent[playerCurrentX][playerCurrentY] = 3;
                    currentContent[playerCurrentX+1][playerCurrentY] = 7;
                    currentContent[playerCurrentX+2][playerCurrentY] = 5;
                    currentImages[playerCurrentX][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/destinations/destination_"+QString::number(destinationColor)+".png);}");
                    currentImages[playerCurrentX+1][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/playersOnDestination/playerOnDestination_"+QString::number(playerColor)+".png);}");
                    currentImages[playerCurrentX+2][playerCurrentY]->setStyleSheet("QLabel{ background-image: url(:/icons/fields/field_"+QString::number(fieldColor)+".png);image: url(:/icons/completedBoxes/completedBox_"+QString::number(boxColor)+".png);}");
                    playerCurrentX = playerCurrentX+1;
                    moves = moves + 1;
                    isWinner();
                    hasMoved = true;
                }
            }
        }
    }
}

void MainWindow::on_btnReset_pressed(){
    randomColors();
    moves=0;
    ui->lblMoves->setText("Moves "+QString::number(moves)+"");
    for (int i=0;i<16;i++){
        for (int j=0;j<16;j++){
            currentContent[i][j] = resetContent[i][j];
            if (currentContent[i][j] == 6 || currentContent[i][j] == 7){
                playerCurrentX = i;
                playerCurrentY = j;
            }
        }
    }
    drawLevel();
}

void MainWindow::on_btnClose_pressed(){
    exit(0);
}

void MainWindow::on_actionUp_triggered()
{
    on_btnUp_pressed();
}

void MainWindow::on_actionDown_triggered()
{
    on_btnDown_pressed();
}

void MainWindow::on_actionLeft_triggered()
{
    on_btnLeft_pressed();
}

void MainWindow::on_actionRigth_triggered()
{
    on_btnRigth_pressed();
}

void MainWindow::on_actionUp_2_triggered()
{
     on_btnUp_pressed();
}

void MainWindow::on_actionDown_2_triggered()
{
     on_btnDown_pressed();
}

void MainWindow::on_actionLeft_2_triggered()
{
  on_btnLeft_pressed();
}

void MainWindow::on_actionRigth_2_triggered()
{
   on_btnRigth_pressed();
}

void MainWindow::on_btnMenu_pressed()
{
    if (this->windowState()==Qt::WindowFullScreen){
        showNormal();
    }else{
        showFullScreen();
    }
}

void MainWindow::on_actionNew_Game_triggered()
{
    currentLevel=0;
    moves=0;
    ui->lblLevel->setText("Level "+QString::number(currentLevel+1));
    ui->lblMoves->setText("Moves "+QString::number(moves));
    randomColors();
    for (int i=0;i<16;i++){
        for (int j=0;j<16;j++){
            currentContent[i][j] = levels[currentLevel][i][j];
            resetContent[i][j] = levels[currentLevel][i][j];
            if (currentContent[i][j] ==6 || currentContent[i][j] ==7){
                playerCurrentX = i;
                playerCurrentY = j;
            }
        }
    }
    drawLevel();

}

void MainWindow::on_actionLoad_Game_triggered()
{

}
