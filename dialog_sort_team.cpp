#include "dialog_sort_team.h"
#include "ui_dialog_sort_team.h"
#include "data.h"
#include "QMessageBox"
Dialog_sort_team::Dialog_sort_team(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_sort_team)
{
    ui->setupUi(this);
}

Dialog_sort_team::~Dialog_sort_team()
{
    delete ui;
}

void Dialog_sort_team::on_pushButton_clicked()
{
    ui->listWidget->clear();

    std::vector<int> teamIndices;

    for (int i = 0; i < Data::get_teams().size(); i++) {
        if (Data::get_teams()[i].get_head_of_team() == Data::get_onlineId()) {
            teamIndices.push_back(i);
        }
    }
    std::sort(teamIndices.begin(), teamIndices.end(), [](int a, int b) {
        const QString& teamNameA = Data::get_teams()[a].get_name_of_team();
        const QString& teamNameB = Data::get_teams()[b].get_name_of_team();
        return teamNameA < teamNameB;
    });

    for (const auto& index :teamIndices) {
        ui->listWidget->addItem(Data::get_teams()[index].get_name_of_team());
    }
}

