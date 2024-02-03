#include "dialog_team_to_organ.h"
#include "ui_dialog_team_to_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_team_to_organ::Dialog_team_to_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_team_to_organ)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_team_to_organ::~Dialog_team_to_organ()
{
    delete ui;
}

void Dialog_team_to_organ::on_show_organs_btn_clicked()
{
    ui->list_organs->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId())
            ui->list_organs->addItem(Data::get_organs()[i].get_name_of_organ());


    }
}


void Dialog_team_to_organ::on_buttonBox_accepted()
{

    if(ui->organ_input->text().isEmpty() || ui->team_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }
    int flag =0 ;
    for (int a =0 ; Data::get_teams().size() > a ;a++){
        if(Data::get_teams()[a].get_name_of_team() == ui->team_input->text())
            flag = 1;
    }
    if(flag == 0 ){
      QMessageBox::warning(this, "error!", " No team found with this name!");
        return;

    }

    int flag2 =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->organ_input->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
    QMessageBox::warning(this, "error!", " No organization with this name was found!");
        return;

    }





    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId() && Data::get_organs()[i].get_name_of_organ() == ui->organ_input->text()){
            for(int a =0 ; Data::get_organs()[i].get_teams_of_organ().size() > a ; a++){
                if(Data::get_organs()[i].get_teams_of_organ()[a] == ui->team_input->text()){
                    QMessageBox::warning(this, "error", " This team is a member of this organization!");
                    return;
                }
            }

            Data::get_organs()[i].add_team_organ(ui->team_input->text());
this->close();

        }



    }

}

