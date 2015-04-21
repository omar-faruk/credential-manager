#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "credentialwindow.h"
#include <qdebug.h>
using namespace std;

bool firstUse=false;

loginWindow::loginWindow(QWidget *parent) :
   QMainWindow(parent),ui(new Ui::loginWindow)
{

    string first_use_check;
    freopen("data//up.o","r+",stdin);
    getline(cin,first_use_check);
    ui->setupUi(this);
    connect(ui->password,SIGNAL(returnPressed()),ui->loginButton,SIGNAL(clicked()));

    if(first_use_check.size()<2){
        firstUse=true;
        ui->username->setProperty("placeholderText","set username");
        ui->password->setProperty("placeholderText","set password");
    }

    ui->password->setEchoMode(QLineEdit::Password);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_loginButton_clicked()
{
    string user,pass;
    string user_s,pass_s;

    user=ui->username->text().toStdString();
    pass=ui->password->text().toStdString();

    if(firstUse){
        freopen("data//up.o","a+",stdout);
        cout<<user<<endl<<pass<<endl;
        fclose(stdin);
        this->hide();
        credentialWindow cw;
        cw.setModal(true);
        cw.exec();
    }
    else{
        freopen("data//up.o","r+",stdin);
        cin>>user_s;
        cin>>pass_s;
        if(user==user_s && pass==pass_s){
            fclose(stdin);
            this->hide();
            credentialWindow cw;
            cw.setModal(true);
            cw.exec();
        }
        else{
            ui->messageBox->setText("username & password mismatch, try again");
            ui->username->clear();
            ui->password->clear();
        }

    }

}
