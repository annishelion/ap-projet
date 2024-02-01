#ifndef DIALOG_SORT_PROJECT_H
#define DIALOG_SORT_PROJECT_H

#include <QDialog>

namespace Ui {
class Dialog_sort_project;
}

class Dialog_sort_project : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_sort_project(QWidget *parent = nullptr);
    ~Dialog_sort_project();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_sort_project *ui;
};

#endif // DIALOG_SORT_PROJECT_H
