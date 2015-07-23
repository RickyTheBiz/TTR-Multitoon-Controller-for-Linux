#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QProcess>
#include <QString>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    grabKeyboard();     //send all keyboard strokes to this window
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_wasd_clicked()
{
    //run the select window tool on xdotool
    QProcess process;
    process.start("xdotool selectwindow");
    process.waitForFinished();

    //get the window id from xdotool
    QByteArray id = process.readAllStandardOutput();
    win1 = id.data();

    //send a ctrl keystroke to the selected window to let the user know it is active
    //apparently TTR doesn't like it when you release ctrl too quickly so need to send both a down and up key
    //instead of just the keypress
    QString cmd;
    cmd = QString("xdotool keydown --window ") + win1 + QString(" ctrl");
    process.start(cmd);
    process.waitForFinished();

    cmd = QString("xdotool keyup --window ") + win1 + QString(" ctrl");
    process.start(cmd);
    process.waitForFinished();
}

void MainWindow::on_arrows_clicked()
{
    //run the select window tool on xdotool
    QProcess process;
    process.start("xdotool selectwindow");
    process.waitForFinished();

    //get the window id from xdotool
    QByteArray id = process.readAllStandardOutput();
    win2 = id.data();

    //send a ctrl keystroke to the selected window to let the user know it is active
    //apparently TTR doesn't like it when you release ctrl too quickly so need to send both a down and up key
    //instead of just the keypress
    QString cmd;
    cmd = QString("xdotool keydown --window ") + win2 + QString(" ctrl");
    process.start(cmd);
    process.waitForFinished();

    cmd = QString("xdotool keyup --window ") + win2 + QString(" ctrl");
    process.start(cmd);
    process.waitForFinished();
}

//for when a certain key is pressed, run through a switch/case to determine the key
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->isAutoRepeat())
    {
        //keystrokes auto-repeat if held down so when this happens we simply ignore it
        return;
    }
    switch (e->key())
    {
//Window 1 (WASD) controls
        case Qt::Key_W:
        {
            //when the W key is pressed send arrow key up to window 1 (WASD window)
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Up");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }

        case Qt::Key_A:
        {
            //when the A key is pressed send arrow key left to window 1 (WASD window)
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Left");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_D:
        {
            //when the D key is pressed send arrow key right to window 1 (WASD window)
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Right");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_S:
        {
            //when the S key is pressed send arrow key down to window 1 (WASD window)
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Down");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Shift:
        {
            //when the shift key is pressed send ctrl to window 1 (WASD window)
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" ctrl");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_E:
        {
            //when the E key is pressed send escape to window 1 (WASD window)
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Escape");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Z:
        {
            //when the numpad 4 key is pressed freeze window 1 (useful for current glitch with DA and CGC)
            QByteArray pid;
            QProcess process;

            //find out the process id of the window
            process.start(QString("xdotool getwindowpid ") + win1);
            process.waitForFinished();
            pid = process.readAllStandardOutput();

            //send the window the freeze command
            process.start(QString("kill -s SIGSTOP ") + QString(pid.data()));
            process.waitForFinished();
            break;
        }

//Window 2 (arrows) controls
        case Qt::Key_Up:
        {
            //when the Arrow key up key is pressed send arrow key up to window 2 (arrows window)
            QString cmd = QString("xdotool keydown --window ") + win2 + QString(" Up");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Right:
        {
            //when the Arrow key right key is pressed send arrow key right to window 2 (arrows window)
            QString cmd = QString("xdotool keydown --window ") + win2 + QString(" Right");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
            }
        case Qt::Key_Left:
        {
            //when the Arrow key left key is pressed send arrow key left to window 2 (arrows window)
            QString cmd = QString("xdotool keydown --window ") + win2 + QString(" Left");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Down:
        {
            //when the Arrow key down key is pressed send arrow key down to window 2 (arrows window)
            QString cmd = QString("xdotool keydown --window ") + win2 + QString(" Down");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Control:
        {
            //when the ctrl key is pressed send ctrl to window 2 (arrows window)
            QString cmd = QString("xdotool keydown --window ") + win2 + QString(" Ctrl");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        //runs if either 0 or insert is pressed (numpad 0 turns into insert if shift key is pressed on other toon)
        case Qt::Key_0:
        case Qt::Key_Insert:
        {
            //when the numpad 0 key is pressed send escape to window 2 (arrows window)
            QString cmd = QString("xdotool keydown --window ") + win2 + QString(" Escape");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }

    case Qt::Key_X:
    {
        //when the numpad 4 key is pressed freeze window 2 (useful for current glitch with DA and CGC)
        QByteArray pid;
        QProcess process;

        //find out the process id of the window
        process.start(QString("xdotool getwindowpid ") + win2);
        process.waitForFinished();
        pid = process.readAllStandardOutput();

        //send the window the freeze command
        process.start(QString("kill -s SIGSTOP ") + QString(pid.data()));
        process.waitForFinished();
        break;
    }

//controls for both windows
        case Qt::Key_Alt:
        {
            //When alt key is pressed send alt to both windows

            //send to win1
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Alt");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keydown --window ") + win2 + QString(" Alt");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Delete:
        {
            //When delete key is pressed send delete to both windows

            //send to win1
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Delete");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keydown --window ") + win2 + QString(" Delete");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Home:
        {
            //When home key is pressed send home to both windows

            //send to win1
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" Home");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keydown --window ") + win2 + QString(" Home");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_End:
        {
            //When end key is pressed send end to both windows

            //send to win1
            QString cmd = QString("xdotool keydown --window ") + win1 + QString(" End");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keydown --window ") + win2 + QString(" End");
            process.start(cmd);
            process.waitForFinished();
            break;
        }

        //a little different than normal, this one sends just a keypress and there is no key release counter part
        case Qt::Key_Q:
        {
            //When Q key is pressed send Delete keystroke to both windows
            //this function sends just a keystroke which releases quickly regardless of how long it is pressed

            //send to win1
            QString cmd = QString("xdotool key --window ") + win1 + QString(" Delete");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool key --window ") + win2 + QString(" Delete");
            process.start(cmd);
            process.waitForFinished();
            break;
        }

    }
}

//for when a certain key is released, run through a switch/case to determine the key
void MainWindow::keyReleaseEvent(QKeyEvent *r)
{
    if(r->isAutoRepeat())
    {
        //keystrokes auto-repeat if held down so when this happens we simply ignore it
        return;
    }

    switch (r->key())
    {
//Window 1 (WASD) controls
        case Qt::Key_W:
        {
            //when the W key is released release arrow key up for window 1 (WASD window)
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Up");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }

        case Qt::Key_A:
        {
            //when the A key is released release arrow key left for window 1 (WASD window)
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Left");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_D:
        {
            //when the D key is released release arrow key right for window 1 (WASD window)
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Right");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_S:
        {
            //when the S key is released release arrow key down for window 1 (WASD window)
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Down");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Shift:
        {
            //when the shift key is released release ctrl for window 1 (WASD window)
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" ctrl");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_E:
        {
            //when the E key is released release escape for window 1 (WASD window)
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Escape");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Z:
        {
            //when the numpad 4 key is pressed freeze window 2 (useful for current glitch with DA and CGC)
            QByteArray pid;
            QProcess process;

            //find out the process id of the window
            process.start(QString("xdotool getwindowpid ") + win1);
            process.waitForFinished();
            pid = process.readAllStandardOutput();

            //send the window the freeze command
            process.start(QString("kill -s SIGCONT ") + QString(pid.data()));
            process.waitForFinished();
            break;
        }

//Window 2 (arrows) controls
        case Qt::Key_Up:
        {
            //when the Arrow key up key is released release arrow key up for window 2 (arrows window)
            QString cmd = QString("xdotool keyup --window ") + win2 + QString(" Up");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Right:
        {
            //when the Arrow key right key is released release arrow key right for window 2 (arrows window)
            QString cmd = QString("xdotool keyup --window ") + win2 + QString(" Right");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
            }
        case Qt::Key_Left:
        {
            //when the Arrow key left key is released release arrow key left for window 2 (arrows window)
            QString cmd = QString("xdotool keyup --window ") + win2 + QString(" Left");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Down:
        {
            //when the Arrow key down key is released release arrow key down for window 2 (arrows window)
            QString cmd = QString("xdotool keyup --window ") + win2 + QString(" Down");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Control:
        {
            //when the ctrl key is released release ctrl for window 2 (arrows window)
            QString cmd = QString("xdotool keyup --window ") + win2 + QString(" Ctrl");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        //runs if either 0 or insert is pressed (numpad 0 turns into insert if shift key is pressed on other toon)
        case Qt::Key_0:
        case Qt::Key_Insert:
        {
            //when the numpad 0 key is released release escape for window 2 (arrows window)
            QString cmd = QString("xdotool keyup --window ") + win2 + QString(" Escape");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_X:
        {
            //when the numpad 4 key is released un-freeze window 2 (useful for current glitch with DA and CGC)
            QByteArray pid;
            QProcess process;

            //find out the process id of the window
            process.start(QString("xdotool getwindowpid ") + win2);
            process.waitForFinished();
            pid = process.readAllStandardOutput();

            //send the window the freeze command
            process.start(QString("kill -s SIGCONT ") + QString(pid.data()));
            process.waitForFinished();
            break;
        }

//controls for both windows
        case Qt::Key_Alt:
        {
            //When alt key is released release alt for both windows

            //send to win1
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Alt");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keyup --window ") + win2 + QString(" Alt");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Delete:
        {
            //When delete key is released release delete for both windows

            //send to win1
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Delete");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keyup --window ") + win2 + QString(" Delete");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Home:
        {
            //When home key is released release home for both windows

            //send to win1
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" Home");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keyup --window ") + win2 + QString(" Home");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_End:
        {
            //When end key is released release end for both windows

            //send to win1
            QString cmd = QString("xdotool keyup --window ") + win1 + QString(" End");
            QProcess process;
            process.start(cmd);
            process.waitForFinished();

            //send to win2
            cmd = QString("xdotool keyup --window ") + win2 + QString(" End");
            process.start(cmd);
            process.waitForFinished();
            break;
        }
    }
}
