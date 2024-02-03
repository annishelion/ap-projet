#include "dialog_delete_project.h"
#include "ui_dialog_delete_project.h"
#include "data.h"
#include "QMessageBox"
Dialog_delete_project::Dialog_delete_project(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_delete_project)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_delete_project::~Dialog_delete_project()
{
    delete ui;
}

void Dialog_delete_project::on_btn_show_my_projects_clicked()
{
    {
        ui->listWidget->clear();
        for (int i = 0; i < Data::get_projects().size(); i++) {
            if (Data::get_onlineId() == Data::get_projects()[i].get_head_of_project()) {
                ui->listWidget->addItem(Data::get_projects()[i].get_name_of_project());
            }
        }

    }
}


void Dialog_delete_project::on_buttonBox_accepted()
{
    if( ui->input_name_of_project->text().isEmpty())
    {
        QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }




        for (int i = 0; i < Data::get_projects().size(); i++) {
        if (Data::get_onlineId() == Data::get_projects()[i].get_head_of_project()) {
            if(Data::get_projects()[i].get_name_of_project() == ui->input_name_of_project->text())
            {
             Data::get_projects().erase(Data::get_projects().cbegin()+i);

            }

        }
}
}
