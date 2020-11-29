#include "developper.h"

Developper::Developper()
{

}

QString Developper::getNom() const
{
    return nom;
}

void Developper::setNom(const QString &value)
{
    nom = value;
}

int Developper::getAge() const
{
    return age;
}

void Developper::setAge(int value)
{
    age = value;
}
