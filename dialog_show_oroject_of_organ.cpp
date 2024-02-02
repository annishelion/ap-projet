#include "dialog_show_oroject_of_organ.h"
#include "ui_dialog_show_oroject_of_organ.h"
#include "dialog_show_oroject_of_organ.h"
#include "data.h"
#include "QMessageBox"
Dialog_show_oroject_of_organ::Dialog_show_oroject_of_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_show_oroject_of_organ)
{
    ui->setupUi(this);
}

Dialog_show_oroject_of_organ::~Dialog_show_oroject_of_organ()
{
    delete ui;
}

void Dialog_show_oroject_of_organ::on_pushButton_clicked()
{

    if( ui->input_name_of_organ->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }


    int flag =0 ;
    for (int a =0 ; Data::get_organs().size() > a ;a++){
        if(Data::get_organs()[a].get_name_of_organ() == ui->input_name_of_organ->text())
            flag = 1;
    }
    if(flag == 0 ){
    QMessageBox::warning(this, "error!", " No organization with this name was found!");
        return;



    ui->list->clear();
    for (int i = 0; i < Data::get_organs().size(); i++) {

        if(Data::get_organs()[i].get_name_of_organ() == ui->input_name_of_organ->text())
            for(int t = 0 ; t < Data::get_organs()[i].get_project_of_organ().size() ; t++)
            ui->list->addItem(Data::get_organs()[i].get_project_of_organ()[t]);


    }
}

}
