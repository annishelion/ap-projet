#include "dialog_add_project_to_organ.h"
#include "ui_dialog_add_project_to_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_project_to_organ::Dialog_add_project_to_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_project_to_organ)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_add_project_to_organ::~Dialog_add_project_to_organ()
{
    delete ui;
}

void Dialog_add_project_to_organ::on_pushButton_clicked()
{
    ui->list_organs->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {
        if (Data::get_onlineId() == Data::get_organs()[i].get_head_of_organ()) {
            ui->list_organs->addItem(Data::get_organs()[i].get_name_of_organ());
        }
    }
}


void Dialog_add_project_to_organ::on_buttonBox_accepted()
{
    if(ui->input_organ->text().isEmpty() || ui->input_project->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " Please fill the items!");
        return;
    }
    int flag =0 ;
    for (int a =0 ; Data::get_projects().size() > a ;a++){
        if(Data::get_projects()[a].get_name_of_project() == ui->input_project->text())
            flag = 1;
    }
    if(flag == 0 ){
        QMessageBox::warning(this, "error!", " No project with this name was found!");
        return;

    }

    int flag2 =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->input_organ->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
        QMessageBox::warning(this, "error!", " No organization with this name was found!");
        return;

    }





    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId() && Data::get_organs()[i].get_name_of_organ() == ui->input_organ->text()){
            for(int a =0 ; Data::get_organs()[i].get_project_of_organ().size() > a ; a++){
                if(Data::get_organs()[i].get_project_of_organ()[a] == ui->input_project->text()){
                    QMessageBox::warning(this, "تذکر", " این پروزه در این سازمان عضو است!");
                    return;
                }
            }

            Data::get_organs()[i].add_project_to_organ(ui->input_project->text());

            return;
        }



    }
}

