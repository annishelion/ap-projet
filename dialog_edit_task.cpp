#include "dialog_edit_task.h"
#include "ui_dialog_edit_task.h"
#include "data.h"
#include "QMessageBox"
dialog_edit_task::dialog_edit_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_edit_task)
{
    ui->setupUi(this);
}

dialog_edit_task::~dialog_edit_task()
{
    delete ui;
}

void dialog_edit_task::on_buttonBox_accepted()
{
    if(ui->old_name_of_task_input->text().isEmpty() || ui->new_name_of_task_input->text().isEmpty() || ui->new_priority_input->text().isEmpty())
    {
      QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }


        for (int i = 0; i < Data::get_tasks().size(); i++) {
        if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
            if(Data::get_tasks()[i].get_name_of_task() == ui->old_name_of_task_input->text())
            {
             Data::get_tasks()[i].set_name_of_task(ui->new_name_of_task_input->text());
             Data::get_tasks()[i].set_priority_for_task(ui->new_priority_input->text());
            }

        }
}
}

void dialog_edit_task::on_show_tasks_clicked()
{
    ui->listWidget->clear();
    for (int i = 0; i < Data::get_tasks().size(); i++) {
        if (Data::get_onlineId() == Data::get_tasks()[i].get_username_of_cteator()) {
            ui->listWidget->addItem(Data::get_tasks()[i].get_name_of_task());
        }
}
}

