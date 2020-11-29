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
};

#endif // PROJECTJSONMAPPER_H
