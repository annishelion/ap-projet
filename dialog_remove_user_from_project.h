#ifndef DIALOG_REMOVE_USER_FROM_PROJECT_H
#define DIALOG_REMOVE_USER_FROM_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_remove_user_from_project;
}

class Dialog_remove_user_from_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_remove_user_from_project(QWidget *parent = nullptr);
    ~Dialog_remove_user_from_project();

private slots:
    void on_show_clicked();

    void on_remove_clicked();

private:
    Ui::Dialog_remove_user_from_project *ui;
};

#endif // DIALOG_REMOVE_USER_FROM_PROJECT_H
