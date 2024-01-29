#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QMainWindow>

namespace Ui {
class firstpage;
}

class firstpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstpage(QWidget *parent = nullptr);
    ~firstpage();

private slots:
    void on_pushButton_2_clicked();

    void on_task_group_clicked();

    void on_teams_btn_clicked();

    void on_organ_group_clicked();

    void on_show_my_tasks_btn_clicked();

    void on_show_my_archive_btn_clicked();

    void on_add_task_to_archive_btn_clicked();

    void on_turn_over_to_my_tasks_btn_clicked();

private:
    Ui::firstpage *ui;
};

#endif // FIRSTPAGE_H
