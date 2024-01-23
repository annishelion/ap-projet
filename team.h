#ifndef TEAM_H
#define TEAM_H

#include "user.h"
#include <QMainWindow>
#include <QString>
#include <QVector>
class team{
private:
    QVector<QString> members;
    QString name_of_team =  " ";
    QString head_of_team = " ";

public:

    QVector<QString> get_members_of_team(){return members;}
    team(QString s){
        name_of_team = s;
    }
team();
    void set_name_of_team(QString _new_team_name);
    void add_member(QString new_member);
    void delete_member(QString _member);
    QString get_name_of_team();
    void set_head_of_team(QString _head){
        head_of_team = _head;
    }
    QString get_head_of_team(){return head_of_team;}
bool operator==(team t);
};



#endif // TEAM_H
