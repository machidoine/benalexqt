#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include "developper.h"
#include <iostream>
#include <list>

class Project
{
public:
    Project();

    std::list<Developper> getDevelopers() const;
    void setDevelopers(const std::list<Developper> &value);

    QString getNom() const;
    void setNom(const QString &value);

    void addDevelopper(Developper developper);

    QString toJson();

private:
    QString nom;
    std::list<Developper> developers;
};

#endif // PROJECT_H
