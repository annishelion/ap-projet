#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "team.h"
#include "user.h"
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "project.h"
class organization{
private:
    QString name_of_organ;
    QVector<QString> member_of_organ;
    QVector<QString> team_of_organ;
    QVector<QString> projects_of_organ;
    QVector<QString> organ_of_organ;
    QString head_of_organ;
public:
    organization();
    organization(QString creator_organ,QString _name_of_organ);
    void delete_project_from_organ(QString pro);
void add_project_to_organ(QString pro);
void add_member_to_organ(QString _user);
void add_team_organ(QString _team);
void set_head_of_organ(QString _user);
QString get_head_of_organ();
void delete_member_of_organ(QString _user);
void delete_team_of_organ(QString _team);
QString get_name_of_organ();
void set_name_of_organ(QString s);
QVector<QString> get_member_of_organ(){return member_of_organ;}
void set_member_of_organ(QString s);
bool operator==(organization o);
QVector<QString> get_organ_of_organ(){
    return organ_of_organ;
}
QVector<QString> get_teams_of_organ(){return team_of_organ;}
};

#endif // ORGANIZATION_H
