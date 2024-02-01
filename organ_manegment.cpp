#include "organ_manegment.h"
#include "ui_organ_manegment.h"
#include "data.h"
#include "dialog_add_organ.h"
#include "dialog_edit_organ.h"
#include "dialog_remove_organ.h"
#include "dialog_remove_user_from_organ.h"
#include "dialog_add_user_to_organ.h"
#include "dialog_view_added_organ_to_organ.h"
#include "dialog_sort_organs.h"
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

        if(Data::get_organs()[i].get_head_of_organ() == Data::get_onlineId())
            ui->listWidget->addItem(Data::get_organs()[i].get_name_of_organ());


    }
}


void organ_manegment::on_pushButton_2_clicked()
{
    Dialog_edit_organ *edit = new Dialog_edit_organ();
    edit->show();
}


void organ_manegment::on_pushButton_3_clicked()
{
    Dialog_remove_organ *re = new Dialog_remove_organ(this);
    re->show();
}


void organ_manegment::on_pushButton_5_clicked()
{
    Dialog_remove_user_from_organ *ss = new Dialog_remove_user_from_organ();
    ss->show();
}


void organ_manegment::on_pushButton_4_clicked()
{
    Dialog_add_user_to_organ *tt = new Dialog_add_user_to_organ();
    tt->show();
}


void organ_manegment::on_pushButton_6_clicked()
{
    Dialog_view_added_organ_to_organ *aa = new Dialog_view_added_organ_to_organ();
    aa->show();
}


void organ_manegment::on_pushButton_7_clicked()
{
    Dialog_sort_organs *s = new Dialog_sort_organs();
    s->show();
}

