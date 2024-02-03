#include "task_manegment.h"
#include "ui_task_manegment.h"
#include "dialog_add_task.h"
#include "data.h"
#include "QMessageBox"
#include "dialog_edit_task.h"
#include "dialog_asign_task_to_user.h"
#include "dialog_assign_task_to_project.h"
#include "dialog_assign_task_to_team.h"
#include "dialog_add_comment.h"
task_manegment::task_manegment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task_manegment)
{
    ui->setupUi(this);
    setMinimumSize(800,600);
    setMaximumSize(800,600);
}

task_manegment::~task_manegment()
{
    delete ui;
}

void task_manegment::on_ceat_task_btn_clicked()
{
Dialog_add_task *di = new Dialog_add_task(this);
di->show();
}


void task_manegment::on_show_task_btn_clicked()
{
    ui->show_task_listwidget->clear();
    for (int i = 0; i < Data::get_tasks().size(); i++) {
        if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {

            ui->show_task_listwidget->addItem(Data::get_tasks()[i].get_name_of_task() + Data::get_tasks()[i].get_priority_for_task());
        }
}
}

void task_manegment::on_create_task_btn_clicked()
{
    Dialog_add_task *di = new Dialog_add_task(this);
    di->show();
}


void task_manegment::on_edit_task_btn_clicked()
{
    //if(ui->edit_task_input->text().isEmpty())
     //     QMessageBox::warning(this, "تذکر", " فیلد باید پر شود!");
    //for (int i = 0; i < Data::get_tasks().size(); i++) {
     //   if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
       //     if(Data::get_tasks()[i].get_name_of_task() == ui->edit_task_input->text())
        //    {

                //a
          //  }

   //     }
dialog_edit_task *dia = new dialog_edit_task();
dia->show();
}


void task_manegment::on_assing_task_to_user_btn_clicked()
{
    Dialog_asign_task_to_user *tas = new Dialog_asign_task_to_user(this);
    tas->show();

}

void task_manegment::on_assign_task_to_project_btn_clicked()
{
    Dialog_assign_task_to_project *assign_to_project = new Dialog_assign_task_to_project(this);
    assign_to_project ->show();
}


void task_manegment::on_assign_task_to_team_btn_clicked()
{
    Dialog_assign_task_to_team *assign_to_team = new Dialog_assign_task_to_team(this);
    assign_to_team ->show();
}


void task_manegment::on_assign_task_to_team_btn_2_clicked()
{
    Dialog_add_comment * s = new Dialog_add_comment(this);
    s->show();
}


void task_manegment::on_assign_task_to_team_btn_3_clicked()
{

}

