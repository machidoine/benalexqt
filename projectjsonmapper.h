#ifndef PROJECTJSONMAPPER_H
#define PROJECTJSONMAPPER_H

#include <domain/project/project.h>
#include <QJsonDocument>

class ProjectJsonMapper
{
public:
    ProjectJsonMapper();

    static Project map(QJsonDocument projectJson);
    static Developper map(QJsonObject developperJson);
    static QString toJson(Project* project);
};

#endif // PROJECTJSONMAPPER_H
