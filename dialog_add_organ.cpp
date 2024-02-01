#include "dialog_add_organ.h"
#include "ui_dialog_add_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_organ::Dialog_add_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_organ)
{
    ui->setupUi(this);
}

Dialog_add_organ::~Dialog_add_organ()
{
    delete ui;
}

void Dialog_add_organ::on_add_organ_btn_clicked()
{
    if( ui->add_organ_input->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " Please fill the items!");
    return;
    }

    for(int i =0 ; Data::get_organs().size() > i ; i++){
        if(Data::get_organs()[i].get_name_of_organ() == ui->add_organ_input->text())
        {
            QMessageBox::warning(this, "error!", "The name of the organization is repeated!");
            return;
        }

    }

    organization orr(" " , " ");
    orr.set_name_of_organ(ui->add_organ_input->text());
    orr.set_head_of_organ(Data::get_onlineId());

    Data::get_organs().append(orr);
//return ;

    //return;
  this->close();
}

