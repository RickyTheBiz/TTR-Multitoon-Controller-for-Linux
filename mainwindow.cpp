#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QProcess>
#include <QString>
#include <sstream>
#include <QKeyEvent>
#include <QDebug>

static int win1;
static int win2;

/*void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    grabKeyboard();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_wasd_clicked()
{
//    delay(3000);
    QProcess process;
    process.start("xdotool selectwindow");
    process.waitForFinished();
    QByteArray id = process.readAllStandardOutput();
    std::stringstream ss;
    for (int i = 0; i < id.size(); i++)
    {
        char temp = id[i];
        ss << temp;
    }
    ss >> win1;
    QString cmd;
    std::stringstream ss2;
    ss2 << "xdotool keydown --window " << win1 << " ctrl";
    cmd = ss2.str().c_str();
    process.start(cmd);
    process.waitForFinished();
    ss2 << "xdotool keyup --window " << win1 << " ctrl";
    cmd = ss2.str().c_str();
    process.start(cmd);
    process.waitForFinished();
}

void MainWindow::on_arrows_clicked()
{
    //delay(3000);
    QProcess process;
    process.start("xdotool selectwindow");
    process.waitForFinished();
    QByteArray id = process.readAllStandardOutput();
    std::stringstream ss;
    for (int i = 0; i < id.size(); i++)
    {
        char temp = id[i];
        ss << temp;
    }
    ss >> win2;
    QString cmd;
    std::stringstream ss2;
    ss2 << "xdotool keydown --window " << win2 << " ctrl";
    cmd = ss2.str().c_str();
    process.start(cmd);
    process.waitForFinished();
    ss2 << "xdotool keyup --window " << win2 << " ctrl";
    cmd = ss2.str().c_str();
    process.start(cmd);
    process.waitForFinished();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->isAutoRepeat())
    {
        return;
    }
    switch (e->key())
    {
        case Qt::Key_W:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win1 << " Up";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }

        case Qt::Key_A:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win1 << " Left";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_D:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win1 << " Right";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_S:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win1 << " Down";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_E:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win1 << " Delete";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Shift:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win1 << " ctrl";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Up:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win2 << " Up";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Right:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win2 << " Right";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Left:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win2 << " Left";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Down:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win2 << " Down";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Control:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win2 << " Ctrl";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Delete:
        {
            std::stringstream s;
            s << "xdotool keydown --window " << win2 << " Delete";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Home:
        {
            std::stringstream s;
            std::stringstream s2;
            s << "xdotool keydown --window " << win1 << " Home";
            s2 << "xdotool keydown --window " << win2 << " Home";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            cmd = s2.str().c_str();
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_End:
            {
                std::stringstream s;
                std::stringstream s2;
                s << "xdotool keydown --window " << win1 << " End";
                s2 << "xdotool keydown --window " << win2 << " End";
                QString cmd = s.str().c_str();
                QProcess process;
                process.start(cmd);
                process.waitForFinished();
                cmd = s2.str().c_str();
                process.start(cmd);
                process.waitForFinished();
                break;
        }
        case Qt::Key_Q:
        {
            std::stringstream s;
            std::stringstream s2;
            s << "xdotool key --window " << win1 << " Delete";
            s2 << "xdotool key --window " << win2 << " Delete";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            cmd = s2.str().c_str();
            process.start(cmd);
            process.waitForFinished();
            break;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *r)
{
    if(r->isAutoRepeat())
        return;

    switch (r->key())
    {
        case Qt::Key_W:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win1 << " Up";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }

        case Qt::Key_A:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win1 << " Left";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }

        case Qt::Key_D:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win1 << " Right";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_S:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win1 << " Down";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_E:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win1 << " Delete";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Shift:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win1 << " ctrl";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Up:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win2 << " Up";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Right:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win2 << " Right";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Left:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win2 << " Left";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Down:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win2 << " Down";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Control:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win2 << " Ctrl";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Delete:
        {
            std::stringstream s;
            s << "xdotool keyup --window " << win2 << " Delete";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_Home:
        {
            std::stringstream s;
            std::stringstream s2;
            s << "xdotool keyup --window " << win1 << " Home";
            s2 << "xdotool keyup --window " << win2 << " Home";
            QString cmd = s.str().c_str();
            QProcess process;
            process.start(cmd);
            process.waitForFinished();
            cmd = s2.str().c_str();
            process.start(cmd);
            process.waitForFinished();
            break;
        }
        case Qt::Key_End:
            {
                std::stringstream s;
                std::stringstream s2;
                s << "xdotool keyup --window " << win1 << " End";
                s2 << "xdotool keyup --window " << win2 << " End";
                QString cmd = s.str().c_str();
                QProcess process;
                process.start(cmd);
                process.waitForFinished();
                cmd = s2.str().c_str();
                process.start(cmd);
                process.waitForFinished();
                break;
        }
    }
}
