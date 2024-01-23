#ifndef DIALOG_EDIT_TEAM_H
#define DIALOG_EDIT_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_edit_team;
}

class Dialog_edit_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_edit_team(QWidget *parent = nullptr);
    ~Dialog_edit_team();

private slots:
    void on_show_my_teams_btn_clicked();

    void on_edit_btn_clicked();

private:
    Ui::Dialog_edit_team *ui;
};

#endif // DIALOG_EDIT_TEAM_H
