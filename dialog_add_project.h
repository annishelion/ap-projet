#ifndef DIALOG_ADD_PROJECT_H
#define DIALOG_ADD_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_add_project;
}

class Dialog_add_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_project(QWidget *parent = nullptr);
    ~Dialog_add_project();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_add_project *ui;
};

#endif // DIALOG_ADD_PROJECT_H
