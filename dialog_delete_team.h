#ifndef DIALOG_DELETE_TEAM_H
#define DIALOG_DELETE_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_delete_team;
}

class Dialog_delete_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_delete_team(QWidget *parent = nullptr);
    ~Dialog_delete_team();

private slots:
    void on_show_my_teams_btn_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_delete_team *ui;
};

#endif // DIALOG_DELETE_TEAM_H
