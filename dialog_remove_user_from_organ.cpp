#include "dialog_remove_user_from_organ.h"
#include "ui_dialog_remove_user_from_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_remove_user_from_organ::Dialog_remove_user_from_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_remove_user_from_organ)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_remove_user_from_organ::~Dialog_remove_user_from_organ()
{
    delete ui;
}

void Dialog_remove_user_from_organ::on_show_organ_btn_clicked()
{
    ui->list_organ->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {
        if (Data::get_onlineId() == Data::get_organs()[i].get_head_of_organ()) {
            ui->list_organ->addItem(Data::get_organs()[i].get_name_of_organ());
        }
    }

}



void Dialog_remove_user_from_organ::on_buttonBox_accepted()
{
    if(ui->organ_input->text().isEmpty() || ui->user_input->text().isEmpty())
    {
  QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }
 int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->user_input->text())
                flag = 1;
}
    if(flag == 0 ){
        QMessageBox::warning(this, "error", " This person is not a member of this project!");
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
       for (int a =0 ; Data::get_organs().size() > a ;a++){
           if(Data::get_organs()[a].get_name_of_organ() == ui->organ_input->text())
                   for(int i =0 ; Data::get_organs()[a].get_member_of_organ().size(); i++){
                        if(Data::get_organs()[a].get_member_of_organ()[i] == ui->user_input->text()){

                            //Data::get_organs()[a].get_member_of_organ().erase(std::remove(Data::get_teams()[a].get_members_of_team().begin(), Data::get_teams()[a].get_members_of_team().end(), i), Data::get_teams()[a].get_members_of_team().end());
Data::get_organs()[a].get_member_of_organ().erase(Data::get_organs()[a].get_member_of_organ().cbegin()+i);
//Data::get_organs()[a].get_member_of_organ().erase(Data::get_organs()[a].get_member_of_organ().begin() + i );
                       //  Data::get_teams()[a].get_members_of_team().erase(Data::get_teams()[a].get_members_of_team().begin() + i);
                        return;
                        }

                   }
   }
              QMessageBox::warning(this, "error", " This person is not a member of this group!");
              return;

}

