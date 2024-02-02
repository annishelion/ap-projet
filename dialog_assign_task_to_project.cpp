#include "dialog_assign_task_to_project.h"
#include "ui_dialog_assign_task_to_project.h"
#include "data.h"
#include"QMessageBox"

Dialog_assign_task_to_project::Dialog_assign_task_to_project(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_assign_task_to_project)
{
    ui->setupUi(this);
}

Dialog_assign_task_to_project::~Dialog_assign_task_to_project()
{
    delete ui;
}

void Dialog_assign_task_to_project::on_show_tasks_clicked()
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


void Dialog_assign_task_to_project::on_assign_tasks_to_project_clicked()
{
    if(ui->project_input->text().isEmpty() || ui->task_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }


    int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_projects()[a].get_name_of_project() == ui->project_input->text())
            flag = 1;
    }
    if(flag == 0 ){
        QMessageBox::warning(this, "error!", " No project with this name was found!");
        return;

    }


    int flag4 =0 ;
    for (int a =0 ; Data::get_tasks().size() > a ;a++){
        if(Data::get_tasks()[a].get_name_of_task() == ui->task_input->text())
            flag4 = 1;
    }
    if(flag4 == 0 ){
        QMessageBox::warning(this, "error", " There was no task with this name!");
        return;



    }

    for (int a =0 ; Data::get_tasks().size() > a ;a++){
        if(Data::get_tasks()[a].get_name_of_task() == ui->task_input->text()){
            Data::get_tasks()[a].set_project_Respons_the_task(ui->project_input->text());

        }
        this->close();
    }
}

