#ifndef TASK_MANEGMENT_H
#define TASK_MANEGMENT_H

#include <QMainWindow>

namespace Ui {
class task_manegment;
}

class task_manegment : public QMainWindow
{
    Q_OBJECT

public:
    explicit task_manegment(QWidget *parent = nullptr);
    ~task_manegment();

private slots:
    void on_ceat_task_btn_clicked();

    void on_show_task_btn_clicked();

    void on_create_task_btn_clicked();

    void on_edit_task_btn_clicked();

    void on_assing_task_to_user_btn_clicked();

private:
    Ui::task_manegment *ui;
};

#endif // TASK_MANEGMENT_H
