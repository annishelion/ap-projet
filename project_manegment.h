#ifndef PROJECT_MANEGMENT_H
#define PROJECT_MANEGMENT_H

#include <QMainWindow>

namespace Ui {
class project_manegment;
}

class project_manegment : public QMainWindow
{
    Q_OBJECT

public:
    explicit project_manegment(QWidget *parent = nullptr);
    ~project_manegment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::project_manegment *ui;
};

#endif // PROJECT_MANEGMENT_H
