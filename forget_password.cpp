#include "forget_password.h"
#include "ui_forget_password.h"
#include "data.h"
#include "add_new_password.h"
#include "QMessageBox"
forget_password::forget_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forget_password)
{
    ui->setupUi(this);
}

forget_password::~forget_password()
{
    delete ui;
}

void forget_password::on_buttonBox_accepted()
{
    if (ui->input_email->text().isEmpty() || ui->input_name->text().isEmpty() || ui->input_username->text().isEmpty())
    {
        QMessageBox::warning(this, "error", "Please fill  your information!");
        return;

    }



bool flag = 0;
    for(int i =0 ; Data::get_players().size() > i ; i++){
        if(Data::get_players()[i].get_username() == ui->input_username->text()){
            if(Data::get_players()[i].get_email() == ui->input_email->text() && Data::get_players()[i].get_Name() == ui->input_name->text())
            {
                Data::set_onlineId(ui->input_username->text());
                add_new_password *w = new add_new_password(this);
                flag = 1;
                this->close();
                w->show();
            }

        }

    }
if(flag == 0){

     QMessageBox::warning(this, "error", "username or name or email is incorect!");
     return;
}}

