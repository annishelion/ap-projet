#include "team_management.h"
#include "ui_team_management.h"
#include "dialog_create_team.h"
#include "data.h"
#include "QtAlgorithms"
#include "dialog_team_to_organ.h"
#include "algorithm"
#include "dialog_delete_team.h"
#include "dialog_add_member_to_team.h"
#include "dialog_edit_team.h"
#include "dialog_remove_user_from_team.h"
#include "dialog_show_teams_of_organ.h"
#include "dialog_sort_team.h"
team_management::team_management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::team_management)
{
    ui->setupUi(this);
}

team_management::~team_management()
{
    delete ui;
}

void team_management::on_create_team_btn_clicked()
{
    Dialog_create_team *tea = new Dialog_create_team(this);
    tea->show();
}


void team_management::on_show_my_teams_btn_clicked()
{
   ui->listWidget->clear();
    for (int i = 0; i < Data::get_teams().size(); i++) {
       for(int a = 0 ; Data::get_teams()[i].get_members_of_team().size() > a ; a++){
           if(Data::get_teams()[i].get_members_of_team()[a] == Data::get_onlineId())
ui->listWidget->addItem(Data::get_teams()[i].get_name_of_team());
       }

        }
        }





void team_management::on_delete_team_btn_clicked()
{
    Dialog_delete_team *de = new Dialog_delete_team(this);
de->show();
}


void team_management::on_add_user_to_team_btn_clicked()
{
    Dialog_add_member_to_team *mem = new Dialog_add_member_to_team();
    mem->show();

}


void team_management::on_edit_team_btn_clicked()
{
    Dialog_edit_team *edi = new Dialog_edit_team();
    edi->show();
}


void team_management::on_remove_user_from_organ_btn_clicked()
{
Dialog_remove_user_from_team *remo = new Dialog_remove_user_from_team();
remo->show();
}


void team_management::on_teams_oforgan_btn_clicked()
{
    Dialog_show_teams_of_organ *sd = new Dialog_show_teams_of_organ();
    sd->show();
}


void team_management::on_add_user_to_organ_btn_clicked()
{
    Dialog_team_to_organ *ee = new Dialog_team_to_organ();
    ee->show();
}


void team_management::on_filter_teams_btn_clicked()
{
    Dialog_sort_team *s = new Dialog_sort_team();
    s->show();
}

