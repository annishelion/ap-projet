#include "dialog_edit_organ.h"
#include "ui_dialog_edit_organ.h"
#include "QMessageBox"
#include "data.h"
Dialog_edit_organ::Dialog_edit_organ(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_edit_organ)
{
    ui->setupUi(this);
}

Dialog_edit_organ::~Dialog_edit_organ()
{
    delete ui;
}

void Dialog_edit_organ::on_show_clicked()
{
    ui->list->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId())
            ui->list->addItem(Data::get_organs()[i].get_name_of_organ());


    }
}


void Dialog_edit_organ::on_edit_organ_clicked()
{
    if(ui->new_head->text().isEmpty() || ui->new_name->text().isEmpty() || ui->old_name->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }


    int flag2 =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->old_name->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
  QMessageBox::warning(this, "error!", " No organization with this name was found!");
        return;

    }


    int flag3 =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->new_head->text())
            flag3 = 1;
    }
    if(flag3 == 0 ){
        QMessageBox::warning(this, "error", "There is no such person in the system!");
        return;

    }


    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->old_name->text()){
            Data::get_organs()[a].set_name_of_organ(ui->new_name->text());
            Data::get_organs()[a].set_head_of_organ(ui->new_head->text());

            return;
        }

    }
    this->close();
}

