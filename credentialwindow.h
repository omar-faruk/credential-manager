#ifndef CREDENTIALWINDOW_H
#define CREDENTIALWINDOW_H

#include <QDialog>
#include <QtGui>

namespace Ui {
class credentialWindow;
}

class credentialWindow : public QDialog
{
    Q_OBJECT

public:
    explicit credentialWindow(QWidget *parent = 0);
    ~credentialWindow();

private slots:
    void on_searchButton_clicked();

    void on_addButton_clicked();

private:
    Ui::credentialWindow *ui;
};

#endif // CREDENTIALWINDOW_H
