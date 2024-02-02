#include "dialog_signup.h"
#include "ui_dialog_signup.h"
#include <QMessageBox>
#include "user.h"
#include "data.h"
Dialog_signUp::Dialog_signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_signUp)
{
    ui->setupUi(this);
    setMinimumSize(300,300);
       setMaximumSize(300,300);

}

Dialog_signUp::~Dialog_signUp()
{
    delete ui;
}

void Dialog_signUp::on_buttonBox_accepted()
{
    if (ui->name_input->text().isEmpty() || ui->username_input->text().isEmpty() || ui->password_input->text().isEmpty() || ui->email_input->text().isEmpty()
            ) {
        QMessageBox::warning(this, "error", "Please fill in the Confirms your information!");
        return;
    }
    if(ui->password_input->text().size() < 9)
    {
        QMessageBox::warning(this, "error", "Password must be more than 8 charecter!");
        return;

    }
    for (int i = 0; i < Data::get_players().size(); i++) {
        if (ui->username_input->text() == Data::get_players()[i].get_username()) {
            QMessageBox::warning(this, "error", "Repetitious username!");
            return;
        }
    }
    user p(ui->name_input->text(),ui->username_input->text(),ui->password_input->text(),ui->email_input->text());

    Data::get_players().append(p);
    Data::set_onlineId(ui->username_input->text());

    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    QJsonDocument d = QJsonDocument::fromJson(f.readAll());
    f.close();
    QJsonObject o = d.object();
    QJsonObject temp;
    temp["Name"] = p.get_Name();
    temp["username"] = p.get_username();
    temp["email"] = p.get_email();
    temp["password"] = p.get_password();
    o[p.get_username()] = temp;
    d.setObject(o);
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
















    QMessageBox::information(this, "Complete registration", "Your registration was successful");


}

