#include "dialog_add_member_to_project.h"
#include "ui_dialog_add_member_to_project.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_member_to_project::Dialog_add_member_to_project(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_add_member_to_project)
{
    ui->setupUi(this);
}

Dialog_add_member_to_project::~Dialog_add_member_to_project()
{
    delete ui;
}

void Dialog_add_member_to_project::on_show_clicked()
{
    ui->listWidget->clear();
    for (int i = 0; i < Data::get_projects().size(); i++) {

        if(Data::get_projects()[i].get_head_of_project() == Data::get_onlineId())
            ui->listWidget->addItem(Data::get_projects()[i].get_name_of_project());


    }
}


void Dialog_add_member_to_project::on_add_clicked()
{
    if(ui->enter_project->text().isEmpty() || ui->enter_username->text().isEmpty())
    {
        QMessageBox::warning(this, "تذکر", " فیلد باید پر شود!");
        return;
    }
    int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->enter_username->text())
            flag = 1;
    }
    if(flag == 0 ){
        QMessageBox::warning(this, "تذکر", " شخصی بااین نام یافت نشد!");
        return;

    }

    int flag2 =0 ;
    for (int a =0 ; Data::get_projects().size() > a ;a++){
        if(Data::get_projects()[a].get_name_of_project() == ui->enter_project->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
        QMessageBox::warning(this, "تذکر", " پروژه ای با این نام یافت نشد!");
        return;

    }





    for (int i = 0; i < Data::get_projects().size(); i++) {

        if(Data::get_projects()[i].get_head_of_project() == Data::get_onlineId() && Data::get_projects()[i] == ui->enter_project->text()){
            for(int a =0 ; Data::get_projects()[i].get_users_of_project().size() > a ; a++){
                if(Data::get_projects()[i].get_users_of_project()[a] == ui->enter_username->text()){
                    QMessageBox::warning(this, "تذکر", " این شخص در این پروژه عضو است!");
                    return;
                }
            }

            Data::get_projects()[i].add_member(ui->enter_username->text());

            return;
        }



    }
      this->close();
}

