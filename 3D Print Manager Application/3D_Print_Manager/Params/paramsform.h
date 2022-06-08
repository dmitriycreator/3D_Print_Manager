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
    void createParamsTableModel(const QSqlDatabase &db);
    QString getName();
    QString getCost();
    QString getDel();

signals:
    void deletePlastic();
    void addPlastic();
    void closeParamsForm();

private slots:
    void on_pushButton_AddPlastic_clicked();

    void on_pushButton_delPlastic_clicked();

    void on_lineEdit_Name_textEdited(const QString &arg1);

    void on_lineEdit_Cost_textEdited(const QString &arg1);

    void on_lineEdit_Del_textEdited(const QString &arg1);

    void on_toolButton_close_clicked();

private:
    Ui::ParamsForm *ui;
    QSqlTableModel *model;
    QString plastic_name;
    QString plastic_cost;
    QString del_plastic;
};

#endif // PARAMSFORM_H
