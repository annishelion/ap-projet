#ifndef DIALOG_VIEW_ADDED_ORGAN_TO_ORGAN_H
#define DIALOG_VIEW_ADDED_ORGAN_TO_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_view_added_organ_to_organ;
}

class Dialog_view_added_organ_to_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_view_added_organ_to_organ(QWidget *parent = nullptr);
    ~Dialog_view_added_organ_to_organ();

private slots:
    void on_pushButton_2_clicked();

    void on_show_organ_of_organ_btn_clicked();

private:
    Ui::Dialog_view_added_organ_to_organ *ui;
};

#endif // DIALOG_VIEW_ADDED_ORGAN_TO_ORGAN_H
