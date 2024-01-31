#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_signup.h"
#include <QMessageBox>
#include "data.h"
#include "firstpage.h"
#include "ui_firstpage.h"
#include "user.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(300,300);
       setMaximumSize(300,300);




       QFile f("Players.json");
       f.open(QIODevice::ReadOnly);
       if (f.isOpen() && Data::get_players().isEmpty()) {
           QJsonDocument d = QJsonDocument::fromJson(f.readAll());
           QJsonObject o = d.object();
           QJsonObject temp;
       user p(" "," "," "," ");
       team t(" ");
       project pro(" ");
       organization org(" " , " ");
       task tas(" " , " ");
       QStringList sl = o.keys();
       for (int i = 0; i < sl.size(); i++) {
           temp = o[sl[i]].toObject();
           //user header
           p.set_name(temp["Name"].toString());
      p.set_username(temp["username"].toString());
      p.set_email(temp["email"].toString());
      p.set_password(temp["password"].toString());
      //task header
      tas.set_name_of_task(temp["Name of task"].toString());
      tas.set_priority_for_task(temp["priority"].toString());
      tas.set_project_Respons_the_task(temp["project respons"].toString());
      tas.set_team_Respons_the_task(temp["team respons"].toString());
      tas.set_user_Respons_the_task(temp["user respons"].toString());
      tas.set_uesr_name_of_creator(temp["username creator"].toString());
      tas.set_is_archive(temp["archive"].toInt());
      //team header
      t.set_head_of_team(temp["head of team"].toString());
      t.set_name_of_team(temp["name of team"].toString());
      QJsonArray arr = temp["users of team"].toArray();
      for (int i = 0; i < arr.size(); i++)
          t.add_member(arr[i].toString());
      //organ header
      org.set_head_of_organ(temp["head of organ"].toString());
      org.set_name_of_organ(temp["name of organ"].toString());
      QJsonArray arr2 = temp["users of organ"].toArray();
      for (int i = 0; i < arr2.size(); i++)
          org.add_member_to_organ(arr2[i].toString());

      QJsonArray arr3 = temp["organ of organ"].toArray();
      for (int i = 0; i < arr3.size(); i++)
          org.set_organ_of_organ(arr3[i].toString());

      QJsonArray arr4 = temp["projects of organ"].toArray();
      for (int i = 0; i < arr4.size(); i++)
          org.add_project_to_organ(arr4[i].toString());

      QJsonArray arr5 = temp["teams of organ"].toArray();
      for (int i = 0; i < arr5.size(); i++)
          org.add_team_organ(arr5[i].toString());

      //project header
      pro.set_head_of_project(temp["head of project"].toString());
      pro.set_name_of_project(temp["name of project"].toString());
      pro.set_situation(temp["situation"].toInt());

      QJsonArray arr6 = temp["users of project"].toArray();
      for (int i = 0; i < arr6.size(); i++)
          pro.add_member(arr6[i].toString());

      QJsonArray arr7 = temp["tasks of project"].toArray();
      for (int i = 0; i < arr7.size(); i++)
          pro.add_task_to_project(arr7[i].toString());

      QJsonArray arr8 = temp["teams of project"].toArray();
      for (int i = 0; i < arr8.size(); i++)
          pro.add_team_to_project(arr8[i].toString());

       Data::get_players().append(p);
       Data::get_organs().append(org);
       Data::get_tasks().append(tas);
       Data::get_projects().append(pro);
       Data::get_teams().append(t);
       }
       /*
        *
        *
        *
       QFile f("Players.json");
       f.open(QIODevice::ReadOnly);
       if (f.isOpen() && Data::get_players().isEmpty()) {
           QJsonDocument d = QJsonDocument::fromJson(f.readAll());
           QJsonObject o = d.object();
           QJsonObject temp;
           Player p;
           QStringList sl = o.keys();
           for (int i = 0; i < sl.size(); i++) {
               temp = o[sl[i]].toObject();
               p.set_name(temp["Name"].toString());
               p.set_username(temp["Username"].toString());
               p.set_password(temp["Password"].toString());
               p.set_email(temp["Email"].toString());
               p.set_coin(temp["Coin"].toInt());
               p.set_level(temp["Level"].toInt());
               p.set_experience(temp["Experience"].toInt());
               p.set_experience_required_for_levelUp(temp["Experience required for levelUp"].toInt());
               p.get_farm().Get_MyThread().Set_time_login(temp["SignUp time"].toInt());
               p.get_farm().Get_MyThread().Set_last_time_set(temp["last_time_set"].toInt());
               p.get_farm().Get_MyThread().Set_upgrade_Storage(temp["upgrade_Storage time"].toInt());
               p.get_farm().Get_MyThread().Set_upgrade_Siloo(temp["upgrade_Siloo time"].toInt());
               QJsonArray arr = temp["buy_Milk time"].toArray();
               for (int i = 0; i < arr.size(); i++)
                   p.get_farm().Get_MyThread().Push_Back_on_buy_Milk(arr[i].toInt());
               p.get_farm().get_chickenHome().set_is_build(temp["ChickenHome is build"].toBool());
               p.get_farm().get_cowHome().set_is_build(temp["CowHome is build"].toBool());
               p.get_farm().get_sheepHome().set_is_build(temp["SheepHome is build"].toBool());
               p.get_farm().get_yonjeFarm().set_is_build(temp["YonjehFarm is build"].toBool());
               p.get_farm().get_yonjeFarm().set_is_plantable(temp["YonjehFarm is plantable"].toBool());
               p.get_farm().Get_MyThread().Set_upgrade_ChickenHome(temp["upgrade_ChickenHome time"].toInt());
               p.get_farm().Get_MyThread().Set_build_ChickenHome(temp["build_ChickenHome time"].toInt());
               p.get_farm().Get_MyThread().Set_feed_time_chicken(temp["feed_time_chicken"].toInt());
               p.get_farm().Get_MyThread().Set_upgrade_CowHome(temp["upgrade_CowHome time"].toInt());
               p.get_farm().Get_MyThread().Set_build_CowHome(temp["build_CowHome time"].toInt());
               p.get_farm().Get_MyThread().Set_feed_time_cow(temp["feed_time_cow"].toInt());
               p.get_farm().Get_MyThread().Set_upgrade_SheepHome(temp["upgrade_SheepHome time"].toInt());
               p.get_farm().Get_MyThread().Set_build_SheepHome(temp["build_SheepHome time"].toInt());
               p.get_farm().Get_MyThread().Set_feed_time_sheep(temp["feed_time_sheep"].toInt());
               p.get_farm().Get_MyThread().Set_upgrade_Gandomfarm(temp["upgrade_Gandomfarm time"].toInt());
               p.get_farm().Get_MyThread().Set_Collect_from_GandomFarm(temp["Collect_from_GandomFarm time"].toInt());
               p.get_farm().Get_MyThread().Set_planting_Gandomfarm(temp["Planting_from_GandomFarm time"].toInt());
               p.get_farm().Get_MyThread().Set_planting_YonjeFarm(temp["Planting_from_YonjeFarm time"].toInt());
               p.get_farm().Get_MyThread().Set_upgrade_Yonjehfarm(temp["upgrade_Yonjehfarm time"].toInt());
               p.get_farm().Get_MyThread().Set_Collect_from_YonjehFarm(temp["Collect_from_YonjehFarm time"].toInt());
               p.get_farm().Get_MyThread().Set_Build_YonjehFarm(temp["Build_YonjehFarm time"].toInt());
               p.get_farm().Get_MyThread().Set_Plow_YonjehFarm(temp["Plow_YonjehFarm time"].toInt());
               p.get_farm().get_storage().Get_mikh().Set_Number(temp["Mikh number"].toInt());
               p.get_farm().get_storage().Get_bill().Set_Number(temp["Bill number"].toInt());
               p.get_farm().get_storage().Get_yonjeh().Set_Number(temp["Yonjeh number"].toInt());
               p.get_farm().get_storage().Get_egg().Set_Number(temp["Egg number"].toInt());
               p.get_farm().get_storage().Get_milk().Set_Number(temp["Milk number"].toInt());
               p.get_farm().get_storage().Get_pashm().Set_Number(temp["Pashm number"].toInt());
               p.get_farm().get_storage().Set_Capacity(temp["Storage capacity"].toInt());
               p.get_farm().get_storage().Set_Bulding_Level(temp["Storage level"].toInt());
               p.get_farm().get_storage().Set_Occupied_Capacity(temp["Storage occupied capacity"].toInt());
               p.get_farm().get_siloo().Get_gandom().Set_Number(temp["Gandom number"].toInt());
               p.get_farm().get_siloo().Set_Capacity(temp["Siloo capacity"].toInt());
               p.get_farm().get_siloo().Set_Bulding_Level(temp["Siloo level"].toInt());
               p.get_farm().get_siloo().Set_Occupied_Capacity(temp["Siloo occupied capacity"].toInt());
               p.get_farm().get_chickenHome().set_capacity(temp["ChickenHome capacity"].toInt());
               p.get_farm().get_chickenHome().set_level_habitat(temp["ChickenHome level"].toInt());
               p.get_farm().get_chickenHome().set_stock_animal(temp["ChickenHome stock"].toInt());
               p.get_farm().get_cowHome().set_capacity(temp["CowHome capacity"].toInt());
               p.get_farm().get_cowHome().set_level_habitat(temp["CowHome level"].toInt());
               p.get_farm().get_cowHome().set_stock_animal(temp["CowHome stock"].toInt());
               p.get_farm().get_sheepHome().set_capacity(temp["SheepHome capacity"].toInt());
               p.get_farm().get_sheepHome().set_level_habitat(temp["SheepHome level"].toInt());
               p.get_farm().get_sheepHome().set_stock_animal(temp["SheepHome stock"].toInt());
               //p.get_farm().get_gandomFarm().set_area(temp["GandomFarm area"].toInt());
               //p.get_farm().get_gandomFarm().set_level(temp["GandomFarm level"].toInt());
               //p.get_farm().get_yonjeFarm().set_area(temp["YonjehFarm area"].toInt());
               //p.get_farm().get_yonjeFarm().set_level(temp["YonjehFarm level"].toInt());
               //Data::get_players().append(p);

*/
}
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SignUpBtn_clicked()
{
    Dialog_signUp *s = new Dialog_signUp();
    s->show();
}


void MainWindow::on_SignInBtn_clicked()
{
    user d("mahdi" , "1" , "1" , "1");
    Data::get_players().append(d);
    if (ui->usernameInput->text().isEmpty() || ui->passwordInput->text().isEmpty()) {
        QMessageBox::warning(this, "تذکر", "نام کاربری و رمز عبور نمی تواند خالی باشد!");
        return;
    }
    for (int i = 0; i < (Data::get_players()).size(); i++)
        if (ui->usernameInput->text() == Data::get_players()[i].get_username()) {
            if (ui->passwordInput->text() == Data::get_players()[i].get_password()) {
                Data::set_iterator(Data::get_players().begin() + i);
                this->close();

                Data::get_onlineId() = ui->usernameInput->text();
                firstpage *f = new firstpage();
                f->show();



                return;
            }
            else {
                QMessageBox::warning(this, "تذکر", "رمز عبور اشتباه است!");
                return;
            }
        }
    QMessageBox::warning(this, "تذکر", "نام کاربری یافت نشد!");
}

