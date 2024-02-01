#include "dialog_delete_task.h"
#include "ui_dialog_delete_task.h"
#include "data.h"
#include "QMessageBox"
Dialog_delete_task::Dialog_delete_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_delete_task)
{
    ui->setupUi(this);
}

Dialog_delete_task::~Dialog_delete_task()
{
    delete ui;
}

void Dialog_delete_task::on_show_tasks_btn_clicked()
{
    ui->listwidget->clear();
    for (int i = 0; i < Data::get_tasks().size(); i++) {
        if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
            ui->listwidget->addItem(Data::get_tasks()[i].get_name_of_task());
        }
}
}


void Dialog_delete_task::on_buttonBox_accepted()
{
    if( ui->delete_task_btn->text().isEmpty())
    {
    QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }


        for (int i = 0; i < Data::get_tasks().size(); i++) {
        if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
            if(Data::get_tasks()[i].get_name_of_task() == ui->delete_task_btn->text())
            {
             Data::get_tasks().erase(Data::get_tasks().cbegin()+i);

            }

        }
}
}

