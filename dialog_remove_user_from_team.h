#ifndef DIALOG_REMOVE_USER_FROM_TEAM_H
#define DIALOG_REMOVE_USER_FROM_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_remove_user_from_team;
}

class Dialog_remove_user_from_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_remove_user_from_team(QWidget *parent = nullptr);
    ~Dialog_remove_user_from_team();

private slots:
    void on_pushButton_clicked();

    void on_remove_btn_clicked();

private:
    Ui::Dialog_remove_user_from_team *ui;
};

#endif // DIALOG_REMOVE_USER_FROM_TEAM_H
