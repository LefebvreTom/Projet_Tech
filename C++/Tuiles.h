#ifndef TUILES_H
#define TUILES_H

#include <iostream>
#include <stdlib.h>
#include <string>


class Tuiles{

public:
        virtual ~Tuiles()=0;
        std::string getCouleur();
        void setType(std::string type);
        void setCouleur(std::string couleur);
        std::string getType();
        int getId();

protected:
        std::string Type;
        std::string Couleur;
        int Id;
        std::string MarcheNoir;

};




#endif
