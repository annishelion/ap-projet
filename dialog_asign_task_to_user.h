#ifndef DIALOG_ASIGN_TASK_TO_USER_H
#define DIALOG_ASIGN_TASK_TO_USER_H

#include <QDialog>

namespace Ui {
class Dialog_asign_task_to_user;
}

class Dialog_asign_task_to_user : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_asign_task_to_user(QWidget *parent = nullptr);
    ~Dialog_asign_task_to_user();

private slots:
    void on_show_tasks_clicked();

    void on_assign_btn_clicked();

private:
    Ui::Dialog_asign_task_to_user *ui;
};

#endif // DIALOG_ASIGN_TASK_TO_USER_H
