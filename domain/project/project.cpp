#include "project.h"
#include "projectjsonmapper.h"

Project::Project()
{
    this->developers = {};
}

std::list<Developper> Project::getDevelopers() const
{
    return developers;
}

void Project::setDevelopers(const std::list<Developper> &value)
{
    developers = value;
}

QString Project::getNom() const
{
    return nom;
}

void Project::setNom(const QString &value)
{
    nom = value;
}

void Project::addDevelopper(Developper developper)
{
    this->developers.push_back(developper);
}

QString Project::toJson()
{
    return ProjectJsonMapper::toJson(this);
}
