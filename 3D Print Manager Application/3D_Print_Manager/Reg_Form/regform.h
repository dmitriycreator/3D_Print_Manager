#ifndef REGFORM_H
#define REGFORM_H

#include <QWidget>

namespace Ui {
class RegForm;
}

class RegForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegForm(QWidget *parent = nullptr);
    ~RegForm();
    QString getLogin(); // метод получения логина
    QString getPass(); // метод получения пароля
    bool checkPass(); // метод проверки совпадения пароля и подтверждения

signals:
    void create_button_clicked(); // нажатие кнопки Создать
    void back_button_clicked(); // нажатие кнопки Отмена

private slots:
    void on_lineEdit_Name_textEdited(const QString &arg1);

    void on_lineEdit_Pass_textEdited(const QString &arg1);

    void on_lineEdit_Confirm_textEdited(const QString &arg1);

    void on_pushButton_Create_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::RegForm *ui;

    QString username; // логин
    QString userpass; // пароль
    QString confirmation; // подтверждение пароля
};

#endif // REGFORM_H
