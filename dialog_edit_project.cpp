#include "dialog_edit_project.h"
#include "ui_dialog_edit_project.h"
#include "data.h"
#include "QMessageBox"
Dialog_edit_project::Dialog_edit_project(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit_project)
{
    ui->setupUi(this);
}

Dialog_edit_project::~Dialog_edit_project()
{
    delete ui;
}

void Dialog_edit_project::on_btn_show_clicked()
{
    {
        ui->list_my_project->clear();
        for (int i = 0; i < Data::get_projects().size(); i++) {
            if (Data::get_onlineId() == Data::get_projects()[i].get_head_of_project()) {
                ui->list_my_project->addItem(Data::get_projects()[i].get_name_of_project());
            }
        }

    }
}


void Dialog_edit_project::on_buttonBox_accepted()
{
    if(ui->input_head_of_project->text().isEmpty() || ui->input_new_name->text().isEmpty() || ui->input_old_name->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
        return;
    }


    int flag2 =0 ;
    for (int a =0 ; Data::get_projects().size() > a ;a++){
        if(Data::get_projects()[a].get_name_of_project() == ui->input_old_name->text())
            flag2 = 1;
    }
    if(flag2 == 0 ){
        QMessageBox::warning(this, "تذکر", " ارگانی با این نام یافت نشد!");
        return;

    }


    int flag3 =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->input_head_of_project->text())
            flag3 = 1;
    }
    if(flag3 == 0 ){
        QMessageBox::warning(this, "تذکر", "چنین شخصی در سامانه وجود ندارد!");
        return;

    }


    for (int a =0 ; Data::get_projects().size() > a ;a++){
        if(Data::get_projects()[a].get_name_of_project() == ui->input_old_name->text()){
            Data::get_projects()[a].set_name_of_project(ui->input_new_name->text());
            Data::get_projects()[a].set_head_of_project(ui->input_head_of_project->text());


        }

    }
    this->close();
}

