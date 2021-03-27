#include "Chateaux.h"

using namespace std;

    //constructeur
    Chateau::Chateau()
    {
        Type="chateau";
        Couleur="vert";
        Id_Site="tc";
    }

    Chateau::Chateau(string noir)
    {
        Type="chateau";
        Couleur="vert";
        Id_Site="tcb";
    }

    Chateau::~Chateau(){}

    //Methodes
    // f°creation des piles
    stack <Chateau> Chateau::initStackChateau()
    {
        Chateau castle =Chateau();
        stack<Chateau> StackCastle;

        for(int i=0;i<14;i++){
            StackCastle.push(castle);
            }
        return StackCastle;
    }
