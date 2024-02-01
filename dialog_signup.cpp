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
   // if(ui->password_input->text().size() < 9)
   // {
      //  QMessageBox::warning(this, "error", "Password must be more than 8 digits!");
      //  return;

    //}
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
    /*
     *
    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    QJsonDocument d = QJsonDocument::fromJson(f.readAll());
    f.close();
    QJsonObject o = d.object();
    QJsonObject temp;
    temp["Name"] = p.get_name();
    temp["Username"] = p.get_username();
    temp["Password"] = p.get_password();
    temp["Email"] = p.get_email();
    temp["Coin"] = p.get_coin();
    temp["Level"] = p.get_level();
    temp["Experience"] = p.get_experience();
    temp["Experience required for levelUp"] = p.get_experience_required_for_levelUp();
    temp["SignUp time"] = p.get_farm().Get_MyThread().Get_time_login();
    temp["last_time_set"] = p.get_farm().Get_MyThread().Get_last_time_set();
    temp["upgrade_Storage time"] = 0;
    temp["upgrade_Siloo time"] = 0;
    temp["buy_Milk time"] = 0;
    temp["ChickenHome is build"] = false;
    temp["CowHome is build"] = false;
    temp["SheepHome is build"] = false;
    temp["YonjehFarm is build"] = false;
    temp["YonjehFarm is plantable"] = false;
    temp["upgrade_ChickenHome time"] = 0;
    temp["build_ChickenHome time"] = 0;
    temp["feed_time_chicken"] = 0;
    temp["upgrade_CowHome time"] = 0;
    temp["build_CowHome time"] = 0;
    temp["feed_time_cow"] = 0;
    temp["upgrade_SheepHome time"] = 0;
    temp["build_SheepHome time"] = 0;
    temp["feed_time_sheep"] = 0;
    temp["upgrade_Gandomfarm time"] = 0;
    temp["Collect_from_GandomFarm time"] = 0;
    temp["Planting_from_GandomFarm time"] = 0;
    temp["Planting_from_YonjeFarm time"] = 0;
    temp["upgrade_Yonjehfarm time"] = 0;
    temp["Collect_from_YonjehFarm time"] = 0;
    temp["Build_YonjehFarm time"] = 0;
    temp["Plow_YonjehFarm time"] = 0;
    temp["Mikh number"] = 1;
    temp["Bill number"] = 0;
    temp["Yonjeh number"] = 1;
    temp["Egg number"] = 0;
    temp["Milk number"] = 0;
    temp["Pashm number"] = 0;
    temp["Storage capacity"] = 5;
    temp["Storage level"] = 1;
    temp["Storage occupied capacity"] = 2;
    temp["Gandom number"] = 1;
    temp["Siloo capacity"] = 10;
    temp["Siloo level"] = 1;
    temp["Siloo occupied capacity"] = 1;
    temp["ChickenHome capacity"] = 0;
    temp["ChickenHome level"] = 1;
    temp["ChickenHome stock"] = 0;
    temp["CowHome capacity"] = 0;
    temp["CowHome level"] = 1;
    temp["CowHome stock"] = 0;
    temp["SheepHome capacity"] = 0;
    temp["SheepHome level"] = 1;
    temp["SheepHome stock"] = 0;
    temp["GandomFarm area"] = 5;
    temp["GandomFarm level"] = 1;
    temp["YonjehFarm area"] = 4;
    temp["YonjehFarm level"] = 1;
    o[p.get_username()] = temp;
    d.setObject(o);
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
    QMessageBox::information(this, "تکمیل ثبت نام", "ثبت نام شما با موفقیت انجام شد");
     */



}

