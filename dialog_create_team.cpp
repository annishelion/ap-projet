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
    setMinimumSize(400,300);
    setMaximumSize(400,300);
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
             QMessageBox::warning(this, "error", "The name of the team is repeated!");
             return;
        }

    }
    team te(" ");
    te.set_name_of_team(ui->name_of_team_input->text());
    te.set_head_of_team(Data::get_onlineId());
    te.add_member(Data::get_onlineId());
    Data::get_teams().append(te);

/*
    QFile fff("Teams.json");
    fff.open(QIODevice::ReadOnly);
    QJsonDocument ddd = QJsonDocument::fromJson(fff.readAll());
    fff.close();
    QJsonObject ooo = ddd.object();
    QJsonObject temp3;
    temp3["head of team"] =te.get_head_of_team();
    temp3["name of team"] = te.get_name_of_team();
    //temp["archive"] = 0;
    QJsonArray arr8;
    arr8.append(Data::get_onlineId());
    temp3["users of team"] = arr8;
    ooo[te.get_name_of_team()] = temp3;
    ddd.setObject(ooo);
    fff.open(QIODevice::WriteOnly);
    fff.write(ddd.toJson());
    fff.close();
    */
}

