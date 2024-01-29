#ifndef DIALOG_SHOW_TEAMS_OF_ORGAN_H
#define DIALOG_SHOW_TEAMS_OF_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_show_teams_of_organ;
}

class Dialog_show_teams_of_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_show_teams_of_organ(QWidget *parent = nullptr);
    ~Dialog_show_teams_of_organ();

private slots:
    void on_show_btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_show_teams_of_organ *ui;
};

#endif // DIALOG_SHOW_TEAMS_OF_ORGAN_H
