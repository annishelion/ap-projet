#ifndef DIALOG_DELETE_TASK_H
#define DIALOG_DELETE_TASK_H

#include <QDialog>

namespace Ui {
class Dialog_delete_task;
}

class Dialog_delete_task : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_delete_task(QWidget *parent = nullptr);
    ~Dialog_delete_task();

private slots:
    void on_show_tasks_btn_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_delete_task *ui;
};

#endif // DIALOG_DELETE_TASK_H
