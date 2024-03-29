#ifndef PROJECT_H
#define PROJECT_H

#include "team.h"
#include "user.h"
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "task.h"
class project {
private:
    QString head_of_project = " ";
    QString name_of_project;
    QVector<QString> task_of_project;
    QVector<QString> users_of_project;
    QVector<QString> teams_of_project;
    bool is_done = 0;

public:
    void add_team_to_project(QString s){teams_of_project.append(s);}
    QVector<QString> get_team_of_project(){return teams_of_project;}
    QVector<QString> get_task_of_project(){return task_of_project;}
    bool get_situation(){return is_done;}
    void set_situation(bool i){is_done = i;}
    project();
    project(QString _name);
    void set_name_of_project(QString n);
    QString get_name_of_project();
    void add_task_to_project(QString t);
    bool operator==(project pro);
    void set_head_of_project(QString _user){
        head_of_project = _user;
    }
    QString get_head_of_project(){return head_of_project;}
    QVector<QString> get_users_of_project(){return users_of_project;}
    void add_member(QString new_member);
};

#endif // PROJECT_H
