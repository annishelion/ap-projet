#include "dialog_delete_team.h"
#include "ui_dialog_delete_team.h"
#include "data.h"
#include "QMessageBox"
Dialog_delete_team::Dialog_delete_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_delete_team)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_delete_team::~Dialog_delete_team()
{
    delete ui;
}

void Dialog_delete_team::on_show_my_teams_btn_clicked()
{
    ui->listWidget->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {

            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId())
 ui->listWidget->addItem(Data::get_teams()[i].get_name_of_team());


         }
}



void Dialog_delete_team::on_buttonBox_accepted()
{
    ui->listWidget->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {
            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId()){
                Data::get_teams().erase(Data::get_teams().cbegin()+i);
                return;
//mixing etrtators with const_iterators
}
}
 QMessageBox::warning(this, "error!", " No team found with this name!");
}

