#ifndef DIALOG_TEAM_TO_ORGAN_H
#define DIALOG_TEAM_TO_ORGAN_H

#include <QDialog>

namespace Ui {
class Dialog_team_to_organ;
}

class Dialog_team_to_organ : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_team_to_organ(QWidget *parent = nullptr);
    ~Dialog_team_to_organ();

private slots:
    void on_show_organs_btn_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_team_to_organ *ui;
};

#endif // DIALOG_TEAM_TO_ORGAN_H
