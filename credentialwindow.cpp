#include "credentialwindow.h"
#include "crypto.h"
#include "ui_credentialwindow.h"
using namespace std;
credentialWindow::credentialWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credentialWindow)
{
    ui->setupUi(this);
    ui->keyEntry->setEchoMode(QLineEdit::Password);
    ui->passwordEntry->setEchoMode(QLineEdit::Password);
    ui->confirmPass->setEchoMode(QLineEdit::Password);

}

credentialWindow::~credentialWindow()
{
    delete ui;
}

void credentialWindow::on_searchButton_clicked()
{
    string user,pass,site,dsite,duser,dpass,kstring;
    int key,count=0;
    bool dataFound=false;
    site=ui->siteEntry->text().toStdString();
    key=atoi(ui->keyEntry->text().toStdString().c_str());

    ui->siteEntry->clear();
    ui->keyEntry->clear();

    //read data from text file & decrypt & search

    QStandardItemModel *model = new QStandardItemModel(this); //5 rows 3 columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Site")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("userID")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Password")));
    ui->tableView->setModel(model);
    fclose(stdin);
    freopen("data//db.o","r",stdin);
    while(cin>>dsite>>duser>>dpass){
        dsite=decrypt(dsite,key);
        if(dsite==site){
            dataFound=true;
            QStandardItem *website = new QStandardItem(QString(site.c_str()));
            QStandardItem *username = new QStandardItem(QString(decrypt(duser,key).c_str()));
            QStandardItem *password = new QStandardItem(QString(decrypt(dpass,key).c_str()));
            model->setItem(count,0,website);
            model->setItem(count,1,username);
            model->setItem(count,2,password);
            count++;
        }
    }
    if(!dataFound){
        ui->messageBox->setText("no entry found for this site");
    }
    fclose(stdin);

}

void credentialWindow::on_addButton_clicked()
{
    int key;
    string pass,site,user,confirm_pass;

    ui->messageBox->clear();
    site=ui->siteEntry->text().toStdString();
    user=ui->userEntry->text().toStdString();
    pass=ui->passwordEntry->text().toStdString();
    confirm_pass=ui->confirmPass->text().toStdString();
    key=atoi(ui->keyEntry->text().toStdString().c_str());

    ui->siteEntry->clear();
    ui->userEntry->clear();
    ui->passwordEntry->clear();
    ui->confirmPass->clear();
    ui->keyEntry->clear();

    if(pass==confirm_pass){
        if(entryNotFound(site,user,key)){
            freopen("data//db.o","a",stdout);
            cout<<encrypt(site,key)<<"\t"<<encrypt(user,key)<<"\t"<<encrypt(pass,key)<<endl;
            ui->messageBox->setText("Entry Successfull");
            fclose(stdout);
        }
        else{
            ui->messageBox->setText("Entry has already been stored ");
        }
    }

    else{
       ui->messageBox->setText("Password mismatch, re-enter password");
       ui->passwordEntry->clear();
       ui->confirmPass->clear();
    }

}
