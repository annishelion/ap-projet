#include "dialog_show_teams_of_organ.h"
#include "ui_dialog_show_teams_of_organ.h"
#include "data.h"
Dialog_show_teams_of_organ::Dialog_show_teams_of_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_show_teams_of_organ)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_show_teams_of_organ::~Dialog_show_teams_of_organ()
{
    delete ui;
}

void Dialog_show_teams_of_organ::on_show_btn_clicked()
{
    ui->list_organs->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId())
            ui->list_organs->addItem(Data::get_organs()[i].get_name_of_organ());


    }
}


void Dialog_show_teams_of_organ::on_pushButton_clicked()
{
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_name_of_organ() == ui->name_of_organ_input->text())
            for(int a =0 ; Data::get_organs()[i].get_teams_of_organ().size() > a ; a++){
                ui->list_name_of_teams->addItem(Data::get_organs()[i].get_teams_of_organ()[a]);
            }


    }
}

