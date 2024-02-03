#include "dialog_add_project.h"
#include "ui_dialog_add_project.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_project::Dialog_add_project(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_project)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_add_project::~Dialog_add_project()
{
    delete ui;
}

void Dialog_add_project::on_buttonBox_accepted()
{
    if( ui->input_name_of_project->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " Please fill the items!");
    return;
    }

    for(int i =0 ; Data::get_organs().size() > i ; i++){
        if(Data::get_organs()[i].get_name_of_organ() == ui->input_name_of_project->text())
        {
            QMessageBox::warning(this, "error!", "The name of the project is repeated!");
            return;
        }

    }

    project pr(" ");
    pr.set_head_of_project(Data::get_onlineId());
    pr.set_name_of_project(ui->input_name_of_project->text());
    Data::get_projects().append(pr);


/*
    QFile fffff("projects.json");
    fffff.open(QIODevice::ReadOnly);
    QJsonDocument ddddd = QJsonDocument::fromJson(fffff.readAll());
    fffff.close();
    QJsonObject ooooo = ddddd.object();
    QJsonObject temp5;
    temp5["head of project"] = pr.get_head_of_project();
    temp5["name of project"] =pr.get_name_of_project();
    temp5["situation"] = pr.get_situation();
    //temp["archive"] = ;
    QJsonArray arr;

    temp5["users of project"] = arr;
    //temp["archive"] = get_iterator_pro()->add_task_to_project();
    QJsonArray arr2;

    temp5["tasks of project"] = arr2;
    //temp["archive"] = get_iterator_pro()->get_team_of_project();
    QJsonArray arr3;

    temp5["teams of project"] = arr3;
    ooooo[pr.get_name_of_project()] = temp5;
    ddddd.setObject(ooooo);
    fffff.open(QIODevice::WriteOnly);
    fffff.write(ddddd.toJson());
    fffff.close();
*/
    //organization orr(" " , " ");
    //orr.set_name_of_organ(ui->add_organ_input->text());
    //orr.set_head_of_organ(Data::get_onlineId());

   // Data::get_organs().append(orr);
//return ;

    //return;
  this->close();
}

