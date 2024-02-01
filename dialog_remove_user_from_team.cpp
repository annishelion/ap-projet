#include "dialog_remove_user_from_team.h"
#include "ui_dialog_remove_user_from_team.h"
#include "data.h"
#include "QMessageBox"
#include "algorithm"
#include "QtAlgorithms"
#include "iostream"

Dialog_remove_user_from_team::Dialog_remove_user_from_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_remove_user_from_team)
{
    ui->setupUi(this);
}

Dialog_remove_user_from_team::~Dialog_remove_user_from_team()
{
    delete ui;
}

void Dialog_remove_user_from_team::on_pushButton_clicked()
{
    ui->list_my_teams_veiw->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {

            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId())
 ui->list_my_teams_veiw->addItem(Data::get_teams()[i].get_name_of_team());


         }
}


void Dialog_remove_user_from_team::on_remove_btn_clicked()
{
    if(ui->team_input->text().isEmpty() || ui->user_removed_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }
 int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->user_removed_input->text())
                flag = 1;
}
    if(flag == 0 ){
        QMessageBox::warning(this, "تذکر", " شخصی بااین نام یافت نشد!");
        return;

    }

    int flag2 =0 ;
       for (int a =0 ; Data::get_teams().size() > a ;a++){
           if(Data::get_teams()[a].get_name_of_team() == ui->team_input->text())
                   flag2 = 1;
   }
       if(flag2 == 0 ){
           QMessageBox::warning(this, "تذکر", " تیمی با این نام یافت نشد!");
           return;

       }
       for (int a =0 ; Data::get_teams().size() > a ;a++){
           if(Data::get_teams()[a].get_name_of_team() == ui->team_input->text())
                   for(int i =0 ; Data::get_teams()[a].get_members_of_team().size(); i++){
                        if(Data::get_teams()[a].get_members_of_team()[i] == ui->user_removed_input->text()){
// Data::get_teams()[a].get_members_of_team().erase(std::remove(Data::get_teams()[a].get_members_of_team().cbegin(), Data::get_teams()[a].get_members_of_team().end(), i), Data::get_teams()[a].get_members_of_team().end());

                            //Data::get_teams()[a].get_members_of_team().erase(Data::get_teams()[a].get_members_of_team().begin() + i );
                        Data::get_teams()[a].get_members_of_team().erase(Data::get_teams()[a].get_members_of_team().cbegin() + i);
                        this->close();
                        }

                   }
   }
              QMessageBox::warning(this, "تذکر", " این شخص در این گروه عضو نیست!");
              return;

}

