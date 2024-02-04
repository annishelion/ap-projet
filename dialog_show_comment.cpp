#include "dialog_show_comment.h"
#include "ui_dialog_show_comment.h"
#include "data.h"
#include "qmessagebox.h"
Dialog_show_comment::Dialog_show_comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_show_comment)
{
    ui->setupUi(this);
}

Dialog_show_comment::~Dialog_show_comment()
{
    delete ui;
}

void Dialog_show_comment::on_btn_show_clicked()
{
    if(ui->input_name_of_task->text().isEmpty() )
    {
      QMessageBox::warning(this, "error!", " please fill the items!");
    return;
    }

    ui->list->clear();
    for (int i = 0; i < Data::get_tasks().size(); i++) {

        if(Data::get_tasks()[i].get_name_of_task() == ui->input_name_of_task->text())
        {
            for(int g =0 ; Data::get_tasks()[i].get_comments().size() > g ; g++)
                ui->list->addItem(Data::get_tasks()[i].get_comments()[g]);

        }


}
}

