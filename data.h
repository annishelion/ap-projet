#ifndef DATA_H
#define DATA_H

#include <QVector>

#include <fstream>
#include <iostream>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "user.h"
#include "team.h"
#include "organization.h"
#include "task.h"
using namespace std;
//bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
class Data
{

private:
    static QString onlineId;
    static QString::iterator itonlineId;
    static QVector<user>::iterator ituser;
    static QVector<team>::iterator itteam;
    static QVector<project>::iterator itpro;
    static QVector<organization>::iterator itorgan;
    static QVector<task>::iterator ittask;


    static QVector<user> members;
    static QVector<team> teams;
    static QVector<task> tasks;
    static QVector<organization> organs;
    static QVector<project> projects;
public:
    static void set_iterator(QVector<user>::iterator _it){ ituser=_it; }
static void set_iterator(QVector<team>::iterator _it){ itteam=_it; }
    static void set_iterator(QVector<project>::iterator _it){ itpro=_it; }
    static void set_iterator(QVector<organization>::iterator _it){ itorgan=_it; }
    static void set_iterator(QVector<task>::iterator _it){ ittask=_it; }



    static QVector<user>::iterator& get_iterator_user(){ return ituser; }
static QVector<team>::iterator& get_iterator_team(){ return itteam; }
    static QVector<project>::iterator& get_iterator_pro(){ return itpro; }
    static QVector<organization>::iterator& get_iterator_organ(){ return itorgan; }
    static QVector<task>::iterator& get_iterator_task(){ return ittask; }


    static void set_players(QVector<user>& _players){ members=_players; }
static void set_project(QVector<project>& _players){ projects =_players; }
static void set_team(QVector<team>& _players){ teams=_players; }
static void set_organ(QVector<organization>& _players){ organs =_players; }
static void set_task(QVector<task>& _players){ tasks=_players; }


    static QVector<user>& get_players() { return members ; }
static QVector<team>& get_teams() { return teams ; }
static QVector<organization>& get_organs() { return organs ; }
static QVector<project>& get_projects() { return projects ; }
static QVector<task>& get_tasks() { return tasks ; }


static QString& get_onlineId() { return onlineId ; }
static void set_onlineId(QString _onl){ onlineId=_onl; }

static void write_on_file() {
    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    QJsonDocument d = QJsonDocument::fromJson(f.readAll());
    f.close();
    QJsonObject o = d.object();
    QJsonObject temp = o[get_iterator_user()->get_username()].toObject();
//user header
    temp["Name"] = get_iterator_user()->get_Name();
temp["username"] = get_iterator_user()->get_username();
temp["email"] = get_iterator_user()->get_email();
temp["password"] = get_iterator_user()->get_password();
o[get_iterator_user()->get_username()] = temp;
d.setObject(o);
f.open(QIODevice::WriteOnly);
f.write(d.toJson());
f.close();


QFile ff("Tasks.json");
ff.open(QIODevice::ReadOnly);
QJsonDocument dd = QJsonDocument::fromJson(ff.readAll());
ff.close();
QJsonObject oo = dd.object();
QJsonObject temp2 = oo[get_iterator_task()->get_name_of_task()].toObject();
//user header
temp2["Name of task"] = get_iterator_task()->get_name_of_task();
temp2["priority"] = get_iterator_task()->get_priority_for_task();
temp2["project respons"] = get_iterator_task()->get_project_Respons_the_task();
temp2["team respons"] = get_iterator_task()->get_team_Respons_the_task();
temp2["user respons"] = get_iterator_task()->get_user_Respons_the_task();
temp2["username creator"] = get_iterator_task()->get_username_of_cteator();
temp2["archive"] = get_iterator_task()->get_is_archive();
oo[get_iterator_task()->get_name_of_task()] = temp2;
dd.setObject(oo);
ff.open(QIODevice::WriteOnly);
ff.write(dd.toJson());
ff.close();


QFile fff("Teams.json");
fff.open(QIODevice::ReadOnly);
QJsonDocument ddd = QJsonDocument::fromJson(fff.readAll());
fff.close();
QJsonObject ooo = ddd.object();
QJsonObject temp3 = ooo[get_iterator_team()->get_name_of_team()].toObject();
//user header
temp3["head of team"] = get_iterator_team()->get_head_of_team();
temp3["name of team"] = get_iterator_team()->get_name_of_team();
//temp["archive"] = get_iterator_team()->get_members_of_team();
QJsonArray arr8;
for (int i = 0; i < get_iterator_team()->get_members_of_team().size(); i++) {
    arr8.push_back(get_iterator_team()->get_members_of_team()[i]);}
temp3["users of team"] = arr8;
ooo[get_iterator_team()->get_name_of_team()] = temp3;
ddd.setObject(ooo);
fff.open(QIODevice::WriteOnly);
fff.write(ddd.toJson());
fff.close();



QFile ffff("Organizations.json");
ffff.open(QIODevice::ReadOnly);
QJsonDocument dddd = QJsonDocument::fromJson(ffff.readAll());
ffff.close();
QJsonObject oooo = dddd.object();
QJsonObject temp4 = oooo[get_iterator_organ()->get_name_of_organ()].toObject();
//user header
temp4["head of organ"] = get_iterator_organ()->get_head_of_organ();
temp4["name of organ"] = get_iterator_organ()->get_name_of_organ();
//temp["archive"] = get_iterator_organ()->get_member_of_organ();
QJsonArray arr4;
for (int i = 0; i < get_iterator_organ()->get_member_of_organ().size(); i++) {
    arr4.push_back(get_iterator_organ()->get_member_of_organ()[i]);}
temp4["users of organ"] = arr4;
//temp["archive"] = get_iterator_organ()->get_organ_of_organ();
QJsonArray arr5;
for (int i = 0; i < get_iterator_organ()->get_organ_of_organ().size(); i++) {
    arr5.push_back(get_iterator_organ()->get_organ_of_organ()[i]);}
temp4["organ of organ"] = arr5;
//temp["archive"] = get_iterator_organ()->get_project_of_organ();
QJsonArray arr6;
for (int i = 0; i < get_iterator_organ()->get_project_of_organ().size(); i++) {
    arr6.push_back(get_iterator_organ()->get_project_of_organ()[i]);}
temp4["projects of organ"] = arr6;
//temp["archive"] = get_iterator_organ()->get_teams_of_organ();
QJsonArray arr7;
for (int i = 0; i < get_iterator_organ()->get_teams_of_organ().size(); i++) {
    arr7.push_back(get_iterator_organ()->get_teams_of_organ()[i]);}
temp4["teams of organ"] = arr7;
oooo[get_iterator_organ()->get_name_of_organ()] = temp4;
dddd.setObject(oooo);
ffff.open(QIODevice::WriteOnly);
ffff.write(dddd.toJson());
ffff.close();





QFile fffff("Projects.json");
fffff.open(QIODevice::ReadOnly);
QJsonDocument ddddd = QJsonDocument::fromJson(fffff.readAll());
fffff.close();
QJsonObject ooooo = ddddd.object();
QJsonObject temp5 = ooooo[get_iterator_pro()->get_name_of_project()].toObject();

//project header
temp5["head of project"] = get_iterator_pro()->get_head_of_project();
temp5["name of project"] = get_iterator_pro()->get_name_of_project();
temp5["situation"] = get_iterator_pro()->get_situation();
//temp["archive"] = get_iterator_pro()->get_users_of_project();
QJsonArray arr;
for (int i = 0; i < get_iterator_pro()->get_users_of_project().size(); i++) {
    arr.push_back(get_iterator_pro()->get_users_of_project()[i]);}
temp5["users of project"] = arr;
//temp["archive"] = get_iterator_pro()->add_task_to_project();
QJsonArray arr2;
for (int i = 0; i < get_iterator_pro()->get_task_of_project().size(); i++) {
    arr2.push_back(get_iterator_pro()->get_task_of_project()[i]);}
temp5["tasks of project"] = arr2;
//temp["archive"] = get_iterator_pro()->get_team_of_project();
QJsonArray arr3;
for (int i = 0; i < get_iterator_pro()->get_team_of_project().size(); i++) {
    arr3.push_back(get_iterator_pro()->get_team_of_project()[i]);}
temp5["teams of project"] = arr3;
ooooo[get_iterator_pro()->get_name_of_project()] = temp5;
ddddd.setObject(ooooo);
fffff.open(QIODevice::WriteOnly);
fffff.write(ddddd.toJson());
fffff.close();













//task header
//temp["Name of task"] = get_iterator_task()->get_name_of_task();
//temp["priority"] = get_iterator_task()->get_priority_for_task();
//temp["project respons"] = get_iterator_task()->get_project_Respons_the_task();
//temp["team respons"] = get_iterator_task()->get_team_Respons_the_task();
//temp["user respons"] = get_iterator_task()->get_user_Respons_the_task();
//temp["username creator"] = get_iterator_task()->get_username_of_cteator();
//temp["archive"] = get_iterator_task()->get_is_archive();

//team header
//temp["head of team"] = get_iterator_team()->get_head_of_team();
//temp["name of team"] = get_iterator_team()->get_name_of_team();
//temp["archive"] = get_iterator_team()->get_members_of_team();
//QJsonArray arr8;
//for (int i = 0; i < get_iterator_team()->get_members_of_team().size(); i++) {
//    arr8.push_back(get_iterator_team()->get_members_of_team()[i]);}
//temp["users of team"] = arr8;

//organization header
//temp["head of organ"] = get_iterator_organ()->get_head_of_organ();
//temp["name of organ"] = get_iterator_organ()->get_name_of_organ();
//temp["archive"] = get_iterator_organ()->get_member_of_organ();
//QJsonArray arr4;
//for (int i = 0; i < get_iterator_organ()->get_member_of_organ().size(); i++) {
 //   arr4.push_back(get_iterator_organ()->get_member_of_organ()[i]);}
//temp["users of organ"] = arr4;
//temp["archive"] = get_iterator_organ()->get_organ_of_organ();
//QJsonArray arr5;
//for (int i = 0; i < get_iterator_organ()->get_organ_of_organ().size(); i++) {
 //   arr5.push_back(get_iterator_organ()->get_organ_of_organ()[i]);}
//temp["organ of organ"] = arr5;
//temp["archive"] = get_iterator_organ()->get_project_of_organ();
//QJsonArray arr6;
//for (int i = 0; i < get_iterator_organ()->get_project_of_organ().size(); i++) {
  //  arr6.push_back(get_iterator_organ()->get_project_of_organ()[i]);}
//temp["projects of organ"] = arr6;
//temp["archive"] = get_iterator_organ()->get_teams_of_organ();
//QJsonArray arr7;
//for (int i = 0; i < get_iterator_organ()->get_teams_of_organ().size(); i++) {
  //  arr7.push_back(get_iterator_organ()->get_teams_of_organ()[i]);}
//temp["teams of organ"] = arr7;

//project header
//temp["head of project"] = get_iterator_pro()->get_head_of_project();
//temp["name of project"] = get_iterator_pro()->get_name_of_project();
//temp["situation"] = get_iterator_pro()->get_situation();
//temp["archive"] = get_iterator_pro()->get_users_of_project();
//QJsonArray arr;
//for (int i = 0; i < get_iterator_pro()->get_users_of_project().size(); i++) {
  //  arr.push_back(get_iterator_pro()->get_users_of_project()[i]);}
//temp["users of project"] = arr;
//temp["archive"] = get_iterator_pro()->add_task_to_project();
//QJsonArray arr2;
//f/or (int i = 0; i < get_iterator_pro()->get_task_of_project().size(); i++) {
 //   arr2.push_back(get_iterator_pro()->get_task_of_project()[i]);}
//temp["tasks of project"] = arr2;
//temp["archive"] = get_iterator_pro()->get_team_of_project();
//QJsonArray arr3;
//for (int i = 0; i < get_iterator_pro()->get_team_of_project().size(); i++) {
  //  arr3.push_back(get_iterator_pro()->get_team_of_project()[i]);}
//temp["teams of project"] = arr3;
//o[get_iterator_user()->get_username()] = temp;
//d.setObject(o);
//f.open(QIODevice::WriteOnly);
//f.write(d.toJson());
//f.close();

}
};

#endif // DATA_H
