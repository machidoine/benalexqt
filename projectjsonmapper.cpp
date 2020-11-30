#include "projectjsonmapper.h"

#include <domain/project/project.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>
using namespace std;

ProjectJsonMapper::ProjectJsonMapper()
{

}

Project ProjectJsonMapper::map(QJsonDocument projectJson)
{
    Project p;
    cout << "salut" << endl;

    cout << projectJson.object().value("nom").toString().toStdString() << endl;

    if (projectJson.object().contains("nom")) {
        p.setNom(projectJson.object().value("nom").toString());
    }

    if (projectJson.object().contains("developpers")) {
        QJsonArray developpers = projectJson.object().value("developpers").toArray();
        for (int i = 0; i < developpers.size(); i++) {
            p.addDevelopper(map(developpers[i].toObject()));
        }
    }

    return p;
}

Developper ProjectJsonMapper::map(QJsonObject developperJson)
{
    Developper developper;

    if(developperJson.contains("age")) {
        developper.setAge(developperJson.value("age").toDouble());
    }

    if(developperJson.contains("nom")) {
        developper.setNom(developperJson.value("nom").toString());
    }

    return developper;
}

QString ProjectJsonMapper::toJson(Project* project)
{
    QJsonArray developpersArrays;

    for(Developper developper : project->getDevelopers()) {
        QJsonObject  developperObject;
        developperObject.insert("nom", QJsonValue::fromVariant(developper.getNom()));
        developperObject.insert("age", QJsonValue::fromVariant(developper.getAge()));
        developpersArrays.push_back(developperObject);
    }

    QJsonObject projectObject;
    projectObject.insert("nom", QJsonValue::fromVariant(project->getNom()));
    projectObject.insert("developpers", developpersArrays);

    QJsonDocument json;

    json.setObject(projectObject);

    return json.toJson();
}
