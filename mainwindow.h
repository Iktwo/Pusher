#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTimer>
#include <QTime>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    // Note that this will only have an effect on Symbian and Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

private slots:
    void on_btnUp_pressed();

    void on_btnDown_pressed();

    void on_btnLeft_pressed();

    void on_btnRigth_pressed();

    void on_btnReset_pressed();

    void on_btnClose_pressed();

    void on_actionUp_triggered();

    void on_actionDown_triggered();

    void on_actionLeft_triggered();

    void on_actionRigth_triggered();

    void on_actionUp_2_triggered();

    void on_actionDown_2_triggered();

    void on_actionLeft_2_triggered();

    void on_actionRigth_2_triggered();

    void on_btnMenu_pressed();

    void on_actionNew_Game_triggered();

    void on_actionLoad_Game_triggered();

private:
    Ui::MainWindow *ui;

    void drawLevel();
    void isWinner();
    void incLevel();
    void randomColors();

    int wallColor;// = random.randint(0,9);
    int fieldColor;// = random.randint(0,1);
    int playerColor;// = random.randint(0,1);
    int  boxColor;// = random.randint(0,1);
    int destinationColor;// = random.randint(0,2);

    int currentLevel;
    int numberOfLevels;

    int moves;
    int playerCurrentX;
    int playerCurrentY;

    QLabel *currentImages[16][16];
    int currentContent[16][16];
    int resetContent[16][16];
    int levels[20][16][16];
};

#endif // MAINWINDOW_H
