#include "dialog_add_organ_to_organ.h"
#include "ui_dialog_add_organ_to_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_organ_to_organ::Dialog_add_organ_to_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_organ_to_organ)
{
    ui->setupUi(this);
}

Dialog_add_organ_to_organ::~Dialog_add_organ_to_organ()
{
    delete ui;
}

void Dialog_add_organ_to_organ::on_btn_show_clicked()
{
    ui->list->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId())
            ui->list->addItem(Data::get_organs()[i].get_name_of_organ());


    }
}


void Dialog_add_organ_to_organ::on_buttonBox_accepted()
{
    if(ui->input_added_organ->text().isEmpty() || ui->input_base_organ->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " Please fill the items!");
        return;
    }



    int flag2 =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->input_added_organ->text() || Data::get_organs()[a].get_name_of_organ() == ui->input_base_organ->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
        QMessageBox::warning(this, "error!", " No organization with this name was found!");
        return;

    }





    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId() && Data::get_organs()[i].get_name_of_organ() == ui->input_base_organ->text()){
            for(int a =0 ; Data::get_organs()[i].get_organ_of_organ().size() > a ; a++){
                if(Data::get_organs()[i].get_organ_of_organ()[a] == ui->input_added_organ->text()){
                    QMessageBox::warning(this, "error", " This organization is a member of this organization!");
                    return;
                }
            }

            Data::get_organs()[i].set_organ_of_organ(ui->input_added_organ->text());

            return;
        }



    }
}

