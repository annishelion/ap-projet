#ifndef DIALOG_ASSIGN_TASK_TO_TEAM_H
#define DIALOG_ASSIGN_TASK_TO_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_assign_task_to_team;
}

class Dialog_assign_task_to_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_assign_task_to_team(QWidget *parent = nullptr);
    ~Dialog_assign_task_to_team();

private slots:
    void on_show_tasks_clicked();

    void on_assign_tasks_to_team_clicked();

private:
    Ui::Dialog_assign_task_to_team *ui;
};

#endif // DIALOG_ASSIGN_TASK_TO_TEAM_H
