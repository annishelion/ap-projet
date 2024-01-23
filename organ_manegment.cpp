#include "organ_manegment.h"
#include "ui_organ_manegment.h"
#include "data.h"
#include "dialog_add_organ.h"
organ_manegment::organ_manegment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::organ_manegment)
{
    ui->setupUi(this);
}

organ_manegment::~organ_manegment()
{
    delete ui;
}

void organ_manegment::on_pushButton_clicked()
{
    Dialog_add_organ *a = new Dialog_add_organ();
    a->show();
}


void organ_manegment::on_show_my_organization_btn_clicked()
{
    ui->listWidget->clear();
     for (int i = 0; i < Data::get_organs().size(); i++) {
        for(int a = 0 ; Data::get_organs()[i].get_head_of_organ().size() > a ; a++){
            if(Data::get_organs()[i].get_head_of_organ()[a] == Data::get_onlineId())
 ui->listWidget->addItem(Data::get_organs()[i].get_name_of_organ());
        }

         }
}

