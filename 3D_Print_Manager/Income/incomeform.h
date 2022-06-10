#ifndef INCOMEFORM_H
#define INCOMEFORM_H

#include <QWidget>
#include <QtSql/QtSql>

namespace Ui {
class IncomeForm;
}

class IncomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit IncomeForm(QWidget *parent = nullptr);
    ~IncomeForm();
    void createTableModel(const QSqlDatabase &db); // метод создания модели таблицы из БД

signals:
    void findAllIncome(); // сигнал к нахождению общего дохода
    void closeIncomeForm(); // сигнал к закрытию окна доходов

private slots:
    void on_pushButton_refresh_clicked();

    void on_pushButton_AllIncome_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::IncomeForm *ui;
    QSqlTableModel *model; // объект модели
};

#endif // INCOMEFORM_H
