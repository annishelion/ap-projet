#include "dialog_asign_task_to_user.h"
#include "ui_dialog_asign_task_to_user.h"
#include "data.h"
#include"QMessageBox"
Dialog_asign_task_to_user::Dialog_asign_task_to_user(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_asign_task_to_user)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_asign_task_to_user::~Dialog_asign_task_to_user()
{
    delete ui;
}

void Dialog_asign_task_to_user::on_show_tasks_clicked()
{
    {
        ui->show_tasks_list->clear();
        for (int i = 0; i < Data::get_tasks().size(); i++) {
            if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
                ui->show_tasks_list->addItem(Data::get_tasks()[i].get_name_of_task());
            }
        }

}
}

void Dialog_asign_task_to_user::on_assign_btn_clicked()
{
    if(ui->user_input_->text().isEmpty() || ui->task_to_assign_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }


    int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->user_input_->text())
            flag = 1;
    }
    if(flag == 0 ){
        QMessageBox::warning(this, "error!", " No person found with this name!");
        return;

    }


    int flag4 =0 ;
    for (int a =0 ; Data::get_tasks().size() > a ;a++){
        if(Data::get_tasks()[a].get_name_of_task() == ui->task_to_assign_input->text())
            flag4 = 1;
    }
    if(flag4 == 0 ){
        QMessageBox::warning(this, "error!", " There was no task with this name!");
        return;



    }

    for (int a =0 ; Data::get_tasks().size() > a ;a++){
        if(Data::get_tasks()[a].get_name_of_task() == ui->task_to_assign_input->text()){
            Data::get_tasks()[a].set_user_Respons_the_task(ui->user_input_->text());

        }
        this->close();
    }
    }




