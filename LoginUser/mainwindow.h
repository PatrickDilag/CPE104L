#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>
#include <Player.h>
#include <QTextBrowser>
#include "score.h"

#include <QSpinBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString username;
    QString password;
    Player s;



private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Quit_clicked();

    void on_pushButton_Register_clicked();

    void on_pushButton_HighScore_clicked();

    void writeScore();


    void on_pushButton_search_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow * mainwindow;
    QTextBrowser * textBrowser;
    Score * score;
    QLineEdit * lineEdit_search;



};

#endif // MAINWINDOW_H
