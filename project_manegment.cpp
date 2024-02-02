#include "project_manegment.h"
#include "ui_project_manegment.h"
#include "dialog_add_project_to_organ.h"
#include "dialog_add_project.h"
#include "dialog_add_member_to_project.h"
#include "dialog_remove_user_from_project.h"
#include "dialog_edit_project.h"
#include "data.h"
#include "dialog_delete_project.h"
#include "dialog_show_oroject_of_organ.h"
#include "dialog_sort_project.h"
project_manegment::project_manegment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::project_manegment)
{
    ui->setupUi(this);
}

project_manegment::~project_manegment()
{
    delete ui;
}

void project_manegment::on_pushButton_clicked()
{
    Dialog_add_project_to_organ *mahdi = new Dialog_add_project_to_organ(this);
    mahdi->show();
}


void project_manegment::on_pushButton_10_clicked()
{
    Dialog_add_project* ali = new Dialog_add_project(this);
    ali->show();
}


void project_manegment::on_pushButton_2_clicked()
{
    Dialog_add_member_to_project* add = new Dialog_add_member_to_project(this);
    add->show();
}


void project_manegment::on_pushButton_6_clicked()
{
    Dialog_remove_user_from_project* remove = new Dialog_remove_user_from_project(this);
    remove->show();
}


void project_manegment::on_pushButton_5_clicked()
{
    Dialog_edit_project *aaa = new Dialog_edit_project(this);
    aaa->show();
}


void project_manegment::on_pushButton_9_clicked()
{

        ui->listWidget->clear();
        for (int i = 0; i < Data::get_projects().size(); i++) {
            if (Data::get_onlineId() == Data::get_projects()[i].get_head_of_project()) {
                ui->listWidget->addItem(Data::get_projects()[i].get_name_of_project());
            }
        }


}


void project_manegment::on_pushButton_3_clicked()
{
    Dialog_delete_project *zz = new Dialog_delete_project(this);
    zz->show();
}


void project_manegment::on_pushButton_7_clicked()
{
    Dialog_show_oroject_of_organ *g = new Dialog_show_oroject_of_organ(this);
    g->show();
}


void project_manegment::on_pushButton_8_clicked()
{
    Dialog_sort_project *s = new Dialog_sort_project(this);
    s->show();
}

