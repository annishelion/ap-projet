#include "dialog_add_comment.h"
#include "ui_dialog_add_comment.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_comment::Dialog_add_comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_comment)
{
    ui->setupUi(this);
}

Dialog_add_comment::~Dialog_add_comment()
{
    delete ui;
}

void Dialog_add_comment::on_pushButton_clicked()
{
    ui->list->clear();
    for (int i = 0; i < Data::get_tasks().size(); i++) {

            ui->list->addItem(Data::get_tasks()[i].get_name_of_task());

}
}


void Dialog_add_comment::on_buttonBox_accepted()
{
    bool flag = 0;

    for(int s =0 ; Data::get_tasks().size() > s ; s++){
        if(ui->input_name_of_task->text() == Data::get_tasks()[s].get_name_of_task() ){
    QString ss;
            ss = Data::get_onlineId() + " : "+ ui->input_comment->text() ;

           Data::get_tasks()[s].add_comment(ss);
           flag = 1;

        }

        if(flag == 0){
            QMessageBox::warning(this, "error!", " No task with this name was found!");
            return;

        }

    }
}

