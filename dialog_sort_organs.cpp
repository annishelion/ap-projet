#include "dialog_sort_organs.h"
#include "ui_dialog_sort_organs.h"
#include "data.h"
#include "QMessageBox"
Dialog_sort_organs::Dialog_sort_organs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_sort_organs)
{
    ui->setupUi(this);
}

Dialog_sort_organs::~Dialog_sort_organs()
{
    delete ui;
}

void Dialog_sort_organs::on_pushButton_clicked()
{
    ui->listWidget->clear();

    std::vector<int> organIndices;

    for (int i = 0; i < Data::get_organs().size(); i++) {
        if (Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId()) {
            organIndices.push_back(i);
        }
    }
    std::sort(organIndices.begin(), organIndices.end(), [](int a, int b) {
        const QString& organNameA = Data::get_organs()[a].get_name_of_organ();
        const QString& organNameB = Data::get_organs()[b].get_name_of_organ();
        return organNameA < organNameB;
    });

    for (const auto& index : organIndices) {
        ui->listWidget->addItem(Data::get_organs()[index].get_name_of_organ());
    }
}

