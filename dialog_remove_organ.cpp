#include "dialog_remove_organ.h"
#include "ui_dialog_remove_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_remove_organ::Dialog_remove_organ(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_remove_organ)
{
    ui->setupUi(this);
}

Dialog_remove_organ::~Dialog_remove_organ()
{
    delete ui;
}

void Dialog_remove_organ::on_show_clicked()
{
    ui->listWidget->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId())
            ui->listWidget->addItem(Data::get_organs()[i].get_name_of_organ());


    }
}


void Dialog_remove_organ::on_ok_clicked()
{
    ui->listWidget->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {
        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId()){
            Data::get_organs().erase(Data::get_organs().cbegin()+i);
           //return;
             this->close();

        }
    }
   QMessageBox::warning(this, "error!", " No organization with this name was found!");

}

