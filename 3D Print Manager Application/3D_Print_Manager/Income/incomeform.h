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
    void createTableModel(const QSqlDatabase &db);

signals:
    void findAllIncome();
    void closeIncomeForm();

private slots:
    void on_pushButton_refresh_clicked();

    void on_pushButton_AllIncome_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::IncomeForm *ui;
    QSqlTableModel *model;
};

#endif // INCOMEFORM_H
