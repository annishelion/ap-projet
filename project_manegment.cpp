#include "project_manegment.h"
#include "ui_project_manegment.h"
#include "dialog_add_project_to_organ.h"
#include "dialog_add_project.h"
#include "dialog_add_member_to_project.h"
#include "dialog_remove_user_from_project.h"

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
    Dialog_add_project_to_organ *mahdi = new Dialog_add_project_to_organ();
    mahdi->show();
}


void project_manegment::on_pushButton_10_clicked()
{
    Dialog_add_project* ali = new Dialog_add_project();
    ali->show();
}


void project_manegment::on_pushButton_2_clicked()
{
    Dialog_add_member_to_project* add = new Dialog_add_member_to_project();
    add->show();
}


void project_manegment::on_pushButton_6_clicked()
{
    Dialog_remove_user_from_project* remove = new Dialog_remove_user_from_project();
    remove->show();
}
