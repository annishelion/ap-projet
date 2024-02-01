#ifndef DIALOG_SORT_TEAM_H
#define DIALOG_SORT_TEAM_H

#include <QDialog>

namespace Ui {
class Dialog_sort_team;
}

class Dialog_sort_team : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_sort_team(QWidget *parent = nullptr);
    ~Dialog_sort_team();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_sort_team *ui;
};

#endif // DIALOG_SORT_TEAM_H
