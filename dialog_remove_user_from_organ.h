#ifndef DIALOG_REMOVE_USER_FROM_ORGAN_H
#define DIALOG_REMOVE_USER_FROM_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_remove_user_from_organ;
}

class Dialog_remove_user_from_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_remove_user_from_organ(QWidget *parent = nullptr);
    ~Dialog_remove_user_from_organ();

private slots:
    void on_show_organ_btn_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_remove_user_from_organ *ui;
};

#endif // DIALOG_REMOVE_USER_FROM_ORGAN_H
