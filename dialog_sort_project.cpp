#include "dialog_sort_project.h"
#include "ui_dialog_sort_project.h"
#include "data.h"
#include "QMessageBox"
Dialog_sort_project::Dialog_sort_project(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_sort_project)
{
    ui->setupUi(this);
    setMinimumSize(400,300);
    setMaximumSize(400,300);
}

Dialog_sort_project::~Dialog_sort_project()
{
    delete ui;
}

void Dialog_sort_project::on_pushButton_clicked()
{
    ui->listWidget->clear();

    std::vector<int> projectIndices;

    for (int i = 0; i < Data::get_projects().size(); i++) {
        if (Data::get_projects()[i].get_head_of_project() == Data::get_onlineId()) {
            projectIndices.push_back(i);
        }
    }
    std::sort(projectIndices.begin(), projectIndices.end(), [](int a, int b) {
        const QString& projectNameA = Data::get_projects()[a].get_name_of_project();
        const QString& projectNameB = Data::get_projects()[b].get_name_of_project();
        return projectNameA < projectNameB;
    });

    for (const auto& index : projectIndices) {
        ui->listWidget->addItem(Data::get_projects()[index].get_name_of_project());
    }
}

