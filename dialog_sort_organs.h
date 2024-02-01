#ifndef DIALOG_SORT_ORGANS_H
#define DIALOG_SORT_ORGANS_H

#include <QDialog>

namespace Ui {
class Dialog_sort_organs;
}

class Dialog_sort_organs : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_sort_organs(QWidget *parent = nullptr);
    ~Dialog_sort_organs();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_sort_organs *ui;
};

#endif // DIALOG_SORT_ORGANS_H
