#include "Chateaux.h"

using namespace std;

    //constructeur
    Chateau::Chateau()
    {
        Type="chateau";
        Couleur="vert fonce";
        Id_Site="tc";
    }

    Chateau::Chateau(string noir)
    {
        //tuiles du marche noir
        //id different
        Type="chateau";
        Couleur="vert fonce";
        Id_Site="tcb";
    }

    Chateau::~Chateau(){}

    //Methodes
    // f°creation des piles
    stack <Chateau> Chateau::initStackChateau()
    {
        Chateau castle =Chateau();
        stack<Chateau> StackCastle;
        //on cree une pile de 14 tuiles chateaux
        for(int i=0;i<14;i++){
            StackCastle.push(castle);
            }
        return StackCastle;
    }
