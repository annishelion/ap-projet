#ifndef DIALOG_EDIT_TASK_H
#define DIALOG_EDIT_TASK_H

#include <QDialog>

namespace Ui {
class dialog_edit_task;
}

class dialog_edit_task : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_edit_task(QWidget *parent = nullptr);
    ~dialog_edit_task();

private slots:
    void on_buttonBox_accepted();

    void on_show_tasks_clicked();

private:
    Ui::dialog_edit_task *ui;
};

#endif // DIALOG_EDIT_TASK_H
