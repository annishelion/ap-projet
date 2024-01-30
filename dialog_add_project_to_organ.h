#ifndef DIALOG_ADD_PROJECT_TO_ORGAN_H
#define DIALOG_ADD_PROJECT_TO_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_add_project_to_organ;
}

class Dialog_add_project_to_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_project_to_organ(QWidget *parent = nullptr);
    ~Dialog_add_project_to_organ();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_add_project_to_organ *ui;
};

#endif // DIALOG_ADD_PROJECT_TO_ORGAN_H
