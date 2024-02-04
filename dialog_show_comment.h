#ifndef DIALOG_SHOW_COMMENT_H
#define DIALOG_SHOW_COMMENT_H

#include <QDialog>

namespace Ui {
class Dialog_show_comment;
}

class Dialog_show_comment : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_show_comment(QWidget *parent = nullptr);
    ~Dialog_show_comment();

private slots:
    void on_btn_show_clicked();

private:
    Ui::Dialog_show_comment *ui;
};

#endif // DIALOG_SHOW_COMMENT_H
