#include "dialog_create_team.h"
#include "ui_dialog_create_team.h"
#include "data.h"
#include "QMessageBox"
#include "team.h"
Dialog_create_team::Dialog_create_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_create_team)
{
    ui->setupUi(this);
}

Dialog_create_team::~Dialog_create_team()
{
    delete ui;
}

void Dialog_create_team::on_buttonBox_accepted()
{
    for(int i = 0 ; Data::get_teams().size() > i ; i++){
        if(Data::get_teams()[i].get_name_of_team() == ui->name_of_team_input->text())
        {
             QMessageBox::warning(this, "تذکر", "اسم تیم تکراری است!");
             return;
        }

    }
    team te(" ");
    te.set_name_of_team(ui->name_of_team_input->text());
    te.set_head_of_team(Data::get_onlineId());
    te.add_member(Data::get_onlineId());
    Data::get_teams().append(te);
}

