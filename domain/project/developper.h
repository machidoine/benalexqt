#ifndef DEVELOPPER_H
#define DEVELOPPER_H

#include <QString>



class Developper
{
public:
    Developper();

    QString getNom() const;
    void setNom(const QString &value);

    int getAge() const;
    void setAge(int value);

private:
    QString nom;
    int age;
};

#endif // DEVELOPPER_H
