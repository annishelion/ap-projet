#ifndef DIALOG_CREATE_TEAM_H
#define DIALOG_CREATE_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_create_team;
}

class Dialog_create_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_create_team(QWidget *parent = nullptr);
    ~Dialog_create_team();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_create_team *ui;
};

#endif // DIALOG_CREATE_TEAM_H
