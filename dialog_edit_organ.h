#ifndef DIALOG_EDIT_ORGAN_H
#define DIALOG_EDIT_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_edit_organ;
}

class Dialog_edit_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_edit_organ(QWidget *parent = nullptr);
    ~Dialog_edit_organ();

private slots:
    void on_show_clicked();

    void on_edit_organ_clicked();

private:
    Ui::Dialog_edit_organ *ui;
};

#endif // DIALOG_EDIT_ORGAN_H
