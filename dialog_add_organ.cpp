#include "dialog_add_organ.h"
#include "ui_dialog_add_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_organ::Dialog_add_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_organ)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_add_organ::~Dialog_add_organ()
{
    delete ui;
}

void Dialog_add_organ::on_add_organ_btn_clicked()
{
    if( ui->add_organ_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " Please fill the items!");
    return;
    }

    for(int i =0 ; Data::get_organs().size() > i ; i++){
        if(Data::get_organs()[i].get_name_of_organ() == ui->add_organ_input->text())
        {
            QMessageBox::warning(this, "error!", "The name of the organization is repeated!");
            return;
        }

    }

    organization orr(" " , " ");
    orr.set_name_of_organ(ui->add_organ_input->text());
    orr.set_head_of_organ(Data::get_onlineId());

    Data::get_organs().append(orr);

/*
    QFile ffff("Organizations.json");
    ffff.open(QIODevice::ReadOnly);
    QJsonDocument dddd = QJsonDocument::fromJson(ffff.readAll());
    ffff.close();
    QJsonObject oooo = dddd.object();
    QJsonObject temp4;
    temp4["head of organ"] = orr.get_head_of_organ();
    temp4["name of organ"] =orr.get_name_of_organ();
    //temp["archive"] = get_iterator_organ()->get_member_of_organ();
    QJsonArray arr4;

    temp4["users of organ"] = arr4;
    //temp["archive"] = get_iterator_organ()->get_organ_of_organ();
    QJsonArray arr5;

    temp4["organ of organ"] = arr5;
    //temp["archive"] = get_iterator_organ()->get_project_of_organ();
    QJsonArray arr6;

    temp4["projects of organ"] = arr6;
    //temp["archive"] = get_iterator_organ()->get_teams_of_organ();
    QJsonArray arr7;

    temp4["teams of organ"] = arr7;
    oooo[orr.get_name_of_organ()] = temp4;
    dddd.setObject(oooo);
    ffff.open(QIODevice::WriteOnly);
    ffff.write(dddd.toJson());
    ffff.close();
*/

//return ;

    //return;
  this->close();
}

