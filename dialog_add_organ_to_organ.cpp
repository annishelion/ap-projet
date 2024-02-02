#include "dialog_add_organ_to_organ.h"
#include "ui_dialog_add_organ_to_organ.h"

Dialog_add_organ_to_organ::Dialog_add_organ_to_organ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_organ_to_organ)
{
    ui->setupUi(this);
}

Dialog_add_organ_to_organ::~Dialog_add_organ_to_organ()
{
    delete ui;
}
