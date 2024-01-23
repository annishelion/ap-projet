#ifndef DIALOG_ADD_MEMBER_TO_TEAM_H
#define DIALOG_ADD_MEMBER_TO_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_add_member_to_team;
}

class Dialog_add_member_to_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_member_to_team(QWidget *parent = nullptr);
    ~Dialog_add_member_to_team();

private slots:
    void on_show_teams_btn_clicked();

    void on_add_user_to_team_btn_clicked();

private:
    Ui::Dialog_add_member_to_team *ui;
};

#endif // DIALOG_ADD_MEMBER_TO_TEAM_H
