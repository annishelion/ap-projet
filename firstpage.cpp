#include "firstpage.h"
#include "ui_firstpage.h"
#include "team_management.h"
#include "task_manegment.h"
#include "organ_manegment.h"
firstpage::firstpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstpage)
{
    ui->setupUi(this);
}

firstpage::~firstpage()
{
    delete ui;
}

void firstpage::on_pushButton_2_clicked()
{
    team_management *t = new team_management(this);
    t->show();
}


void firstpage::on_task_group_clicked()
{
task_manegment *ta = new task_manegment();
ta->show();
}


void firstpage::on_teams_btn_clicked()
{
    team_management *t = new team_management();
    t->show();
}


void firstpage::on_organ_group_clicked()
{
    organ_manegment *orrr = new organ_manegment(this);
    orrr->show();
}

