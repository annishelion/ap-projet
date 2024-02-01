#include "dialog_remove_user_from_project.h"
#include "ui_dialog_remove_user_from_project.h"
#include "data.h"
#include "QMessageBox"
Dialog_remove_user_from_project::Dialog_remove_user_from_project(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_remove_user_from_project)
{
    ui->setupUi(this);
}

Dialog_remove_user_from_project::~Dialog_remove_user_from_project()
{
    delete ui;
}

void Dialog_remove_user_from_project::on_show_clicked()
{
    ui->listWidget->clear();
    for (int i = 0; i < Data::get_projects().size(); i++) {
        if (Data::get_onlineId() == Data::get_projects()[i].get_head_of_project()) {
            ui->listWidget->addItem(Data::get_projects()[i].get_name_of_project());
        }
    }
}


void Dialog_remove_user_from_project::on_remove_clicked()
{
    if(ui->enter_project->text().isEmpty() || ui->enter_username->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
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
    for (int a =0 ; Data::get_projects().size() > a ;a++){
        if(Data::get_projects()[a].get_name_of_project() == ui->enter_project->text())
            for(int i =0 ; Data::get_projects()[a].get_users_of_project().size(); i++){
                if(Data::get_projects()[a].get_users_of_project()[i] == ui->enter_username->text()){

                    //Data::get_organs()[a].get_member_of_organ().erase(std::remove(Data::get_teams()[a].get_members_of_team().begin(), Data::get_teams()[a].get_members_of_team().end(), i), Data::get_teams()[a].get_members_of_team().end());
                    Data::get_projects()[a].get_users_of_project().erase(Data::get_projects()[a].get_users_of_project().cbegin()+i);
                    //Data::get_organs()[a].get_member_of_organ().erase(Data::get_organs()[a].get_member_of_organ().begin() + i );
                    //  Data::get_teams()[a].get_members_of_team().erase(Data::get_teams()[a].get_members_of_team().begin() + i);
                    return;
                }

            }
    }
    QMessageBox::warning(this, "تذکر", " این شخص در این پروژه عضو نیست!");
    this->close();
}

