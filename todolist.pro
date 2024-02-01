QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_add_member_to_project.cpp \
    dialog_add_member_to_team.cpp \
    dialog_add_organ.cpp \
    dialog_add_project.cpp \
    dialog_add_project_to_organ.cpp \
    dialog_add_task.cpp \
    dialog_add_user_to_organ.cpp \
    dialog_asign_task_to_user.cpp \
    dialog_assign_task_to_project.cpp \
    dialog_assign_task_to_team.cpp \
    dialog_create_team.cpp \
    dialog_delete_project.cpp \
    dialog_delete_task.cpp \
    dialog_delete_team.cpp \
    dialog_edit_organ.cpp \
    dialog_edit_project.cpp \
    dialog_edit_task.cpp \
    dialog_edit_team.cpp \
    dialog_remove_organ.cpp \
    dialog_remove_user_from_organ.cpp \
    dialog_remove_user_from_project.cpp \
    dialog_remove_user_from_team.cpp \
    dialog_show_oroject_of_organ.cpp \
    dialog_show_teams_of_organ.cpp \
    dialog_signup.cpp \
    dialog_team_to_organ.cpp \
    dialog_view_added_organ_to_organ.cpp \
    firstpage.cpp \
    main.cpp \
    mainwindow.cpp \
    organ_manegment.cpp \
    organization.cpp \
    project.cpp \
    project_manegment.cpp \
    task.cpp \
    task_manegment.cpp \
    team.cpp \
    team_management.cpp \
    user.cpp

HEADERS += \
    data.h \
    dialog_add_member_to_project.h \
    dialog_add_member_to_team.h \
    dialog_add_organ.h \
    dialog_add_project.h \
    dialog_add_project_to_organ.h \
    dialog_add_task.h \
    dialog_add_user_to_organ.h \
    dialog_asign_task_to_user.h \
    dialog_assign_task_to_project.h \
    dialog_assign_task_to_team.h \
    dialog_create_team.h \
    dialog_delete_project.h \
    dialog_delete_task.h \
    dialog_delete_team.h \
    dialog_edit_organ.h \
    dialog_edit_project.h \
    dialog_edit_task.h \
    dialog_edit_team.h \
    dialog_remove_organ.h \
    dialog_remove_user_from_organ.h \
    dialog_remove_user_from_project.h \
    dialog_remove_user_from_team.h \
    dialog_show_oroject_of_organ.h \
    dialog_show_teams_of_organ.h \
    dialog_signup.h \
    dialog_team_to_organ.h \
    dialog_view_added_organ_to_organ.h \
    firstpage.h \
    mainwindow.h \
    organ_manegment.h \
    organization.h \
    project.h \
    project_manegment.h \
    task.h \
    task_manegment.h \
    team.h \
    team_management.h \
    user.h

FORMS += \
    dialog_add_member_to_project.ui \
    dialog_add_member_to_team.ui \
    dialog_add_organ.ui \
    dialog_add_project.ui \
    dialog_add_project_to_organ.ui \
    dialog_add_task.ui \
    dialog_add_user_to_organ.ui \
    dialog_asign_task_to_user.ui \
    dialog_assign_task_to_project.ui \
    dialog_assign_task_to_team.ui \
    dialog_create_team.ui \
    dialog_delete_project.ui \
    dialog_delete_task.ui \
    dialog_delete_team.ui \
    dialog_edit_organ.ui \
    dialog_edit_project.ui \
    dialog_edit_task.ui \
    dialog_edit_team.ui \
    dialog_remove_organ.ui \
    dialog_remove_user_from_organ.ui \
    dialog_remove_user_from_project.ui \
    dialog_remove_user_from_team.ui \
    dialog_show_oroject_of_organ.ui \
    dialog_show_teams_of_organ.ui \
    dialog_signup.ui \
    dialog_team_to_organ.ui \
    dialog_view_added_organ_to_organ.ui \
    firstpage.ui \
    mainwindow.ui \
    organ_manegment.ui \
    project_manegment.ui \
    task_manegment.ui \
    team_management.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
