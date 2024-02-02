#include "dialog_edit_team.h"
#include "ui_dialog_edit_team.h"
#include "QMessageBox"
#include "data.h"
Dialog_edit_team::Dialog_edit_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit_team)
{
    ui->setupUi(this);
}

Dialog_edit_team::~Dialog_edit_team()
{
    delete ui;
}

void Dialog_edit_team::on_show_my_teams_btn_clicked()
{
    ui->my_teams_view->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {

            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId())
 ui->my_teams_view->addItem(Data::get_teams()[i].get_name_of_team());


         }

}


void Dialog_edit_team::on_edit_btn_clicked()
{

    if(ui->new_head_of_team_input->text().isEmpty() || ui->new_name_of_team_input->text().isEmpty() || ui->old_team_name_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }


    int flag2 =0 ;
       for (int a =0 ; Data::get_teams().size() > a ;a++){
           if(Data::get_teams()[a].get_name_of_team() == ui->old_team_name_input->text())
                   flag2 = 1;
    }
       if(flag2 == 0 ){
           QMessageBox::warning(this, "error!", " No team found with this name!");
           return;

       }


       int flag3 =0 ;
          for (int a =0 ; Data::get_players().size() > a ;a++){
              if(Data::get_players()[a].get_username() == ui->new_head_of_team_input->text())
                      flag3 = 1;
       }
          if(flag3 == 0 ){
              QMessageBox::warning(this, "error", "There is no such person in the system!");
              return;

          }


          for (int a =0 ; Data::get_teams().size() > a ;a++){
              if(Data::get_teams()[a].get_name_of_team() == ui->old_team_name_input->text()){
                  Data::get_teams()[a].set_name_of_team(ui->new_name_of_team_input->text());
          Data::get_teams()[a].set_head_of_team(ui->new_head_of_team_input->text());

          return;
              }

       }

}
