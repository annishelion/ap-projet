#ifndef DIALOG_ADD_COMMENT_H
#define DIALOG_ADD_COMMENT_H

#include <QDialog>

namespace Ui {
class Dialog_add_comment;
}

class Dialog_add_comment : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_comment(QWidget *parent = nullptr);
    ~Dialog_add_comment();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog_add_comment *ui;
};

#endif // DIALOG_ADD_COMMENT_H
