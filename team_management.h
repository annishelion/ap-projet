#ifndef TEAM_MANAGEMENT_H
#define TEAM_MANAGEMENT_H

#include <QMainWindow>

namespace Ui {
class team_management;
}

class team_management : public QMainWindow
{
    Q_OBJECT

public:
    explicit team_management(QWidget *parent = nullptr);
    ~team_management();

private slots:
    void on_create_team_btn_clicked();

    void on_show_my_teams_btn_clicked();

    void on_delete_team_btn_clicked();

    void on_add_user_to_team_btn_clicked();

    void on_edit_team_btn_clicked();

    void on_remove_user_from_organ_btn_clicked();

    void on_teams_oforgan_btn_clicked();

    void on_add_user_to_organ_btn_clicked();

private:
    Ui::team_management *ui;
};

#endif // TEAM_MANAGEMENT_H
