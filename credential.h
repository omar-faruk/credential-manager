#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <QDialog>

namespace Ui {
class credential;
}

class credential : public QDialog
{
    Q_OBJECT

public:
    explicit credential(QWidget *parent = 0);
    ~credential();

};

#endif // CREDENTIAL_H
