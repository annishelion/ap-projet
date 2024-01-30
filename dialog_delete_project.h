#ifndef DIALOG_DELETE_PROJECT_H
#define DIALOG_DELETE_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_delete_project;
}

class Dialog_delete_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_delete_project(QWidget *parent = nullptr);
    ~Dialog_delete_project();

private slots:
    void on_btn_show_my_projects_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_delete_project *ui;
};

#endif // DIALOG_DELETE_PROJECT_H
