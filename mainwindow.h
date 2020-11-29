#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstringlistmodel.h>

#include <domain/project/project.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void populateDevelopperStringModel();

    void populateProjectFields();

private slots:
    void on_actionOpen_triggered();

    void on_toJsonButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel * developpersModel;
    void populateDevelopperStringModel(Project project);
    void populateProjectFields(Project project);
};
#endif // MAINWINDOW_H
