#include "dialog_assign_task_to_team.h"
#include "ui_dialog_assign_task_to_team.h"
#include "data.h"
#include"QMessageBox"
Dialog_assign_task_to_team::Dialog_assign_task_to_team(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_assign_task_to_team)
{
    ui->setupUi(this);
}

Dialog_assign_task_to_team::~Dialog_assign_task_to_team()
{
    delete ui;
}

void Dialog_assign_task_to_team::on_show_tasks_clicked()
{
    {
        ui->list->clear();
        for (int i = 0; i < Data::get_tasks().size(); i++) {
            if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
                ui->list->addItem(Data::get_tasks()[i].get_name_of_task());
            }
        }

    }
}


void Dialog_assign_task_to_team::on_assign_tasks_to_team_clicked()
{
    if(ui->team_input->text().isEmpty() || ui->tasks_input->text().isEmpty())
    {
       QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }


    int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_teams()[a].get_name_of_team() == ui->team_input->text())
            flag = 1;
    }
    if(flag == 0 ){
        QMessageBox::warning(this, "تذکر", " تیمی بااین نام یافت نشد!");
        return;

    }


    int flag4 =0 ;
    for (int a =0 ; Data::get_tasks().size() > a ;a++){
        if(Data::get_tasks()[a].get_name_of_task() == ui->tasks_input->text())
            flag4 = 1;
    }
    if(flag4 == 0 ){
        QMessageBox::warning(this, "تذکر", " وظیفه ای با این نام یاقت نشد!");
        return;



    }

    for (int a =0 ; Data::get_tasks().size() > a ;a++){
        if(Data::get_tasks()[a].get_name_of_task() == ui->tasks_input->text()){
            Data::get_tasks()[a].set_team_Respons_the_task(ui->team_input->text());

        }
        this->close();
    }
}

