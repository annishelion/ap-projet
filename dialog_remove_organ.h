#ifndef DIALOG_REMOVE_ORGAN_H
#define DIALOG_REMOVE_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_remove_organ;
}

class Dialog_remove_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_remove_organ(QWidget *parent = nullptr);
    ~Dialog_remove_organ();

private slots:
    void on_show_clicked();

    void on_ok_clicked();

private:
    Ui::Dialog_remove_organ *ui;
};

#endif // DIALOG_REMOVE_ORGAN_H
