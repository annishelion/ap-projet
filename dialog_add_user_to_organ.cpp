#include "dialog_add_user_to_organ.h"
#include "ui_dialog_add_user_to_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_user_to_organ::Dialog_add_user_to_organ(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_add_user_to_organ)
{
    ui->setupUi(this);
}

Dialog_add_user_to_organ::~Dialog_add_user_to_organ()
{
    delete ui;
}

void Dialog_add_user_to_organ::on_show_clicked()
{

}


void Dialog_add_user_to_organ::on_add_clicked()
{

    if(ui->enter_organ->text().isEmpty() || ui->enter_username->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " Please fill the items!");
        return;
    }
    int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->enter_username->text())
            flag = 1;
    }
    if(flag == 0 ){
        QMessageBox::warning(this, "error!", " No person found with this username!");
        return;

    }

    int flag2 =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->enter_organ->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
        QMessageBox::warning(this, "error!", " No team found with this name!");
        return;

    }





    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId() && Data::get_organs()[i].get_name_of_organ() == ui->enter_organ->text()){
            for(int a =0 ; Data::get_organs()[i].get_member_of_organ().size() > a ; a++){
                if(Data::get_organs()[i].get_member_of_organ()[a] == ui->enter_username->text()){
                    QMessageBox::warning(this, "error!", " This person is a member of this team!");
                    return;
                }
            }

            Data::get_organs()[i].add_member_to_organ(ui->enter_username->text());

            return;
        }



    }

}

