#ifndef DIALOG_EDIT_PROJECT_H
#define DIALOG_EDIT_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_edit_project;
}

class Dialog_edit_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_edit_project(QWidget *parent = nullptr);
    ~Dialog_edit_project();

private slots:
    void on_btn_show_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_edit_project *ui;
};

#endif // DIALOG_EDIT_PROJECT_H
