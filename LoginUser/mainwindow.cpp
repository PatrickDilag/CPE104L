#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "game.h"
#include <QApplication>
#include <fstream>
#include <string>
#include <QPushButton>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QThread>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <regex>
#include <QTextBrowser>
#include <QIODevice>
#include <QTextStream>
#include "score.h"
#include <QString>
#include <QObject>
#include <QPixmap>
Game * game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/planes.png");
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    std::string usern;
    std::string pass;
    std::string usernn;
    std::string passs;
    QString username = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_Password->text();
    usern = username.toStdString();
    pass = password.toStdString();


    std::ifstream loginFile;
    loginFile.open("credentials.txt");
    if (!loginFile.is_open())
    {
        QMessageBox messages;
        messages.setWindowTitle("Login");
        messages.setText("Nope didn't find you!");
        messages.exec();
        return;

    }
    while (!loginFile.eof())
    {
        loginFile>>usernn>>passs;
        if ((usernn==usern)&&(passs==pass))
        {
            QMessageBox message;
            message.setWindowTitle("Login");
            message.setText("Hello user!");
            message.exec();
            close();
            loginFile.close();
            game = new Game();
            game->show();


            return;
        }
    }
    QMessageBox message;
    message.setWindowTitle("Login");
    message.setText("Nope didn't find you!");
    message.exec();
    /*QString username = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_Password->text();

   *if(username == "test" && password == "test"){
        QMessageBox::information(this, "Login", "Correct");
        hide();
        game = new Game();
        game->show();
        game->show();*

    }
    else{
        QMessageBox::warning(this, "Login", "Incorrect ");
        hide();
    }*/
}

void MainWindow::on_pushButton_Quit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_Register_clicked()
{
    std::string user;
    std::string pass;
    username = ui->lineEdit_userName->text();
    password = ui->lineEdit_Password->text();
    user = username.toStdString();
    pass = password.toStdString();
    std::ofstream signupFile;
    signupFile.open("credentials.txt",std::ios_base::app);
    signupFile<<user<<" "<<pass<<std::endl;
    signupFile.close();

}

void MainWindow::on_pushButton_HighScore_clicked()
{
    score = new Score();
    QFile file("C:\\Users\\RV\\Documents\\LoginUser\\scores.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0, "info",file.errorString());
        QTextStream in(&file);

        ui->textBrowser->setText(in.readAll());
    /*QFile
    s.loadScore();
    QFile file;
    QDir::setCurrent("/tmp");
    file.setFileName("sortedSaver.txt");
    QDir::setCurrent("/home");
    file.open(QIODevice::ReadOnly);
    QTextStream f(&file);
    ui->textBrowser->setText(f.readAll());*/
    /*QFile file("C:\\Users\\RV\\Documents\\LoginUser\\scores.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info",file.errorString());
    QTextStream in(&file);

    ui->textBrowser->setText(in.readAll());*/
}

void MainWindow::writeScore()
{
    QString filename="scores.txt";
            QFile file( filename );
            if ( file.open(QIODevice::ReadWrite) )
            {
                QTextStream stream( &file );
                stream << "something" << endl;
            }
    /*score = new Score();

    std::ofstream outFile;
    outFile.open("scores.txt",std::ios_base::app);
    outFile<<score<<" "<<score<<std::endl;
    outFile.close();*/



    QFile ("C:\\Users\\RV\\Documents\\LoginUser\\scores.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0, "info",file.errorString());
        QTextStream in(&file);

        ui->textBrowser->setText(in.readAll());
}



void MainWindow::on_pushButton_search_clicked()
{

    QFile file("C:\\Users\\RV\\Documents\\LoginUser\\scoress.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0, "info",file.errorString());
        QTextStream in(&file);

        ui->textBrowser->setText(in.readAll());
}
