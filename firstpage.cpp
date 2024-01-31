#include "firstpage.h"
#include "ui_firstpage.h"
#include "team_management.h"
#include "task_manegment.h"
#include "organ_manegment.h"
#include "data.h"
#include "project_manegment.h"
firstpage::firstpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstpage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
}

firstpage::~firstpage()
{
    delete ui;
}

void firstpage::on_pushButton_2_clicked()
{
    team_management *t = new team_management(this);
    t->show();
}


void firstpage::on_task_group_clicked()
{
task_manegment *ta = new task_manegment();
ta->show();
}


void firstpage::on_teams_btn_clicked()
{
    team_management *t = new team_management();
    t->show();
}


void firstpage::on_organ_group_clicked()
{
    organ_manegment *orrr = new organ_manegment(this);
    orrr->show();
}


void firstpage::on_show_my_tasks_btn_clicked()
{
    {
        ui->mytask_view->clear();
        for (int i = 0; i < Data::get_tasks().size(); i++) {
            if (Data::get_onlineId() == Data::get_tasks()[i].get_user_Respons_the_task() && Data::get_tasks()[i].get_is_archive() == 0) {
                ui->mytask_view->addItem(Data::get_tasks()[i].get_name_of_task());
            }
        }

}
}


void firstpage::on_show_my_archive_btn_clicked()
{
    {
        ui->archive_list->clear();
        for (int i = 0; i < Data::get_tasks().size(); i++) {
            if (Data::get_onlineId() == Data::get_tasks()[i].get_user_Respons_the_task() && Data::get_tasks()[i].get_is_archive() == 1) {
                ui->archive_list->addItem(Data::get_tasks()[i].get_name_of_task());
            }
        }

}
}


void firstpage::on_add_task_to_archive_btn_clicked()
{
    {

        for (int i = 0; i < Data::get_tasks().size(); i++) {
            if (Data::get_onlineId() == Data::get_tasks()[i].get_user_Respons_the_task() && Data::get_tasks()[i].get_is_archive() == 0) {
                Data::get_tasks()[i].set_is_archive(1);
            }
        }

}
}


void firstpage::on_turn_over_to_my_tasks_btn_clicked()
{

    {

        for (int i = 0; i < Data::get_tasks().size(); i++) {
            if (Data::get_onlineId() == Data::get_tasks()[i].get_user_Respons_the_task() && Data::get_tasks()[i].get_is_archive() == 1) {
                Data::get_tasks()[i].set_is_archive(0);
            }
        }

}
}


void firstpage::on_project_group_clicked()
{
    project_manegment *mo = new project_manegment();
    mo->show();
}


void firstpage::on_actionexit_triggered()
{
    //Data::write_on_file();
    this->close();
}

