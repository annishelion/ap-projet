#include "add_new_password.h"
#include "ui_add_new_password.h"
#include "data.h"
add_new_password::add_new_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_new_password)
{
    ui->setupUi(this);
}

add_new_password::~add_new_password()
{
    delete ui;
}

void add_new_password::on_buttonBox_accepted()
{
    for(int i =0 ; i < Data::get_players().size() ; i++){
        if(Data::get_players()[i].get_username() == Data::get_onlineId()){
            Data::get_players()[i].set_password(ui->input_new_password->text());
            Data::set_onlineId(" ");
        }
    }
}

