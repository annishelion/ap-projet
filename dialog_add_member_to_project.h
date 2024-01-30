#ifndef DIALOG_ADD_MEMBER_TO_PROJECT_H
#define DIALOG_ADD_MEMBER_TO_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_add_member_to_project;
}

class Dialog_add_member_to_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_member_to_project(QWidget *parent = nullptr);
    ~Dialog_add_member_to_project();

private slots:
    void on_show_clicked();

    void on_add_clicked();

private:
    Ui::Dialog_add_member_to_project *ui;
};

#endif // DIALOG_ADD_MEMBER_TO_PROJECT_H
