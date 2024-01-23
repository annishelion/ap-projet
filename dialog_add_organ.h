#ifndef DIALOG_ADD_ORGAN_H
#define DIALOG_ADD_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_add_organ;
}

class Dialog_add_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_organ(QWidget *parent = nullptr);
    ~Dialog_add_organ();

private slots:
    void on_add_organ_btn_clicked();

private:
    Ui::Dialog_add_organ *ui;
};

#endif // DIALOG_ADD_ORGAN_H
