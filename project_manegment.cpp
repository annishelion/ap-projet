#include "project_manegment.h"
#include "ui_project_manegment.h"

project_manegment::project_manegment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::project_manegment)
{
    ui->setupUi(this);
}

project_manegment::~project_manegment()
{
    delete ui;
}
