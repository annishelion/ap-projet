#include "dialog_view_added_organ_to_organ.h"
#include "ui_dialog_view_added_organ_to_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_view_added_organ_to_organ::Dialog_view_added_organ_to_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_view_added_organ_to_organ)
{
    ui->setupUi(this);
}

Dialog_view_added_organ_to_organ::~Dialog_view_added_organ_to_organ()
{
    delete ui;
}

void Dialog_view_added_organ_to_organ::on_pushButton_2_clicked()
{
    ui->list_my_organs->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {
        if (Data::get_onlineId() == Data::get_organs()[i].get_head_of_organ()) {
            ui->list_my_organs->addItem(Data::get_organs()[i].get_name_of_organ());
        }
    }
}


void Dialog_view_added_organ_to_organ::on_show_organ_of_organ_btn_clicked()
{

    if(ui->organ_input->text().isEmpty())
    {
        QMessageBox::warning(this, "تذکر", " فیلد باید پر شود!");
    return;
    }


    int flag2 =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->organ_input->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
        QMessageBox::warning(this, "تذکر", " ارگانی با این نام یافت نشد!");
        return;

        for (int a =0 ; Data::get_organs().size() > a ;a++){
            if(Data::get_organs()[a].get_name_of_organ() == ui->organ_input->text())
                for(int f =0 ; f < Data::get_organs()[a].get_organ_of_organ().size() ; f++)
                ui->list_organ_of_organ->addItem(Data::get_organs()[a].get_organ_of_organ()[f]);
        }

}

}
