
#include "Initialisation.h"
    using namespace std;

    //constructeur
    Initialisation::Initialisation()
    {
        InitTabMarchandise();
        cout<<endl;
        InitTabBatiment();
        cout<<endl;
        InitPileChateau();
        cout<<endl;
        InitPileBateau();
        cout<<endl;
        InitPileMines();
        cout<<endl;
        InitTabAnimal();
        cout<<endl;
        InitPileConnaissance();

        /*
        Animal animaltest;
        animaltest.initStackAnimal(1);
        */

    }

    //accesseur


    //methode

    //init du tableau de marchandise
    void Initialisation::InitTabMarchandise(){

        for(int i=0;i<6;i++){
            Marchandise Stack;
            stack <Marchandise> StackMarch = Stack.initStackMarchandise(i+1);
            TabMarchandise[i] = StackMarch;
            cout<<"tabMarchandise ("<<i<<"):"<<endl;
            affichetest.AffichagePileMarch(TabMarchandise[i]);

        }

    }

    //init du tableau de batiment
    void Initialisation::InitTabBatiment(){

        for(int i=0;i<8;i++){
            Batiment Stack;
            stack <Batiment> StackBat = Stack.initStackBatiment(i+1);
            TabBatiment[i] = StackBat;
            cout<<"tabBatiment ("<<i<<"):"<<endl;
            affichetest.AffichagePileBatiment(TabBatiment[i]);

        }

    }

    //init du tableau d'animaux
    void Initialisation::InitTabAnimal(){

        for(int i=0;i<4;i++){
            Animal Stack;
            stack <Animal> StackAnimal = Stack.initStackAnimal(i+1);
            TabAnimal[i] = StackAnimal;
            cout<<"tabAnimal ("<<i<<"):"<<endl;
            affichetest.AffichagePileAnimal(TabAnimal[i]);

        }

    }


    //initialisation des piles

    //pile de chateau
    void Initialisation::InitPileChateau(){
        stack <Chateau> StackCastle = StackChateau.initStackChateau();
        affichetest.AffichagePileChateau(StackCastle);
    }

    //pile de bateau
    void Initialisation::InitPileBateau(){

        stack <Bateau> StackBoat = StackBateau.initStackBateau();
        affichetest.AffichagePileBateau(StackBoat);
    }

    //pile de mines
    void Initialisation::InitPileMines(){

        stack <Mine> StackMines = StackMine.initStackMine();
        affichetest.AffichagePileMine(StackMines);
    }

    //pile de mines
    void Initialisation::InitPileConnaissance(){

        stack <Connaissance> StackConnaissances = StackConnaissance.initStackConnaissance();
        //affichetest.AffichagePileMine(StackMines);
    }







