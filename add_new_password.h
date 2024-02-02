#ifndef ADD_NEW_PASSWORD_H
#define ADD_NEW_PASSWORD_H

#include <QDialog>

namespace Ui {
class add_new_password;
}

class add_new_password : public QDialog
{
    Q_OBJECT

public:
    explicit add_new_password(QWidget *parent = nullptr);
    ~add_new_password();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::add_new_password *ui;
};

#endif // ADD_NEW_PASSWORD_H
