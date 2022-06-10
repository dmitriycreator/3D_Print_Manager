#ifndef PARAMSFORM_H
#define PARAMSFORM_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QMessageBox>

namespace Ui {
class ParamsForm;
}

class ParamsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ParamsForm(QWidget *parent = nullptr);
    ~ParamsForm();
    void createParamsTableModel(const QSqlDatabase &db); // метод создания модели таблицы Пластиков
    QString getName(); // метод получения имени пластика
    QString getCost(); // метод получения стоимости пластика
    QString getDel(); // метод получения имени пластика на удаление

signals:
    void deletePlastic(); // сигнал удалить пластик
    void addPlastic(); // сигнал добавить пластик
    void closeParamsForm(); // сигнал закрыть окно параметров печати

private slots:
    void on_pushButton_AddPlastic_clicked();

    void on_pushButton_delPlastic_clicked();

    void on_lineEdit_Name_textEdited(const QString &arg1);

    void on_lineEdit_Cost_textEdited(const QString &arg1);

    void on_lineEdit_Del_textEdited(const QString &arg1);

    void on_toolButton_close_clicked();

private:
    Ui::ParamsForm *ui;
    QSqlTableModel *model; // модель таблицы БД
    QString plastic_name; // имя пластика
    QString plastic_cost; // стоимость пластика
    QString del_plastic; // пластик на удаление
};

#endif // PARAMSFORM_H
