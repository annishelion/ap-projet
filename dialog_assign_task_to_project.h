#ifndef DIALOG_ASSIGN_TASK_TO_PROJECT_H
#define DIALOG_ASSIGN_TASK_TO_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_assign_task_to_project;
}

class Dialog_assign_task_to_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_assign_task_to_project(QWidget *parent = nullptr);
    ~Dialog_assign_task_to_project();

private slots:
    void on_show_tasks_clicked();

    void on_assign_tasks_to_project_clicked();

private:
    Ui::Dialog_assign_task_to_project *ui;
};

#endif // DIALOG_ASSIGN_TASK_TO_PROJECT_H
