#include "mainwindow.h"
#include "test.h"
#include "ui_mainwindow.h"
#include "projectjsonmapper.h"

#include <QFileDialog>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringListModel>
#include <QDebug>
#include <sstream>
#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    developpersModel = new QStringListModel(this);
}

MainWindow::~MainWindow()
{
    delete developpersModel;
    delete ui;
}




void MainWindow::on_actionOpen_triggered()
{
    QFile file(QFileDialog::getOpenFileName());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

   QByteArray filecontent = file.readAll();

   QJsonParseError json_error;
     QJsonDocument jsonDoc(QJsonDocument::fromJson(filecontent, &json_error));

     if(json_error.error != QJsonParseError::NoError)
     {
         qDebug() << "json error!";
         qDebug() << json_error.errorString();
         return;
     }

    file.close();

    Project project = ProjectJsonMapper::map(jsonDoc);

    cout << project.getNom().toStdString() << endl;

    populateProjectFields(project);
}

void MainWindow::populateProjectFields(Project project)
{
    ui->projectNameLabel->setText(project.getNom());
    populateDevelopperStringModel(project);
    ui->developperListView->setModel(developpersModel);
}

void MainWindow::populateDevelopperStringModel(Project project)
{
    QStringList developpersStringList;

    for(Developper developper : project.getDevelopers()) {
        stringstream valueToDisplay;
        valueToDisplay << developper.getNom().toStdString() <<  " -> " << developper.getAge();
        developpersStringList.append(valueToDisplay.str().c_str());
    }

    developpersModel->setStringList(developpersStringList);
}

void MainWindow::on_toJsonButton_clicked()
{
    QStringListModel *developpersListViewModel = (QStringListModel*) ui->developperListView->model();

    Project project;
    project.setNom(ui->projectNameLabel->text());

    for(QString developperString : developpersListViewModel->stringList()) {
        Developper developper;

        developper.setNom(developperString.split(" -> ")[0]);
        developper.setAge(developperString.split(" -> ")[1].toInt());

        project.addDevelopper(developper);
    }

    ui->jsonInputView->setText(project.toJson());
}
