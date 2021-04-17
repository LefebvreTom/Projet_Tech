
#include "Initialisation.h"
    using namespace std;

    //constructeur
    Initialisation::Initialisation()
    {

        //on appelle les methodes d'initialisations des piles et tableaux necessaires au demarrage du jeu
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
        cout<<endl;
        InitPileMarcheNoir();
        cout<<endl;
        InitTabBonus();
        cout<<endl;



    }

    Initialisation::Initialisation(int fin){
        cout<<"fin de partie"<<endl;
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

    void Initialisation::InitTabBonus(){

        for(int i=0;i<6;i++){
            Bonus Stack;
            cout<<"tabBonus ("<<i<<"):"<<endl;
            stack <Bonus> StackBonus = Stack.initStackBonus(i+1);
            TabBonus[i] = StackBonus;

        }

    }

    //init du tableau de bonus


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

    //pile de Connaissance
    void Initialisation::InitPileConnaissance(){

        stack <Connaissance> StackConnaissances = StackConnaissance.initStackConnaissance();
    }

    //pile du marché noir

    void Initialisation::InitPileMarcheNoir(){
        MarcheNoir = dosNoir.initStackDosNoir();
    }

    void Initialisation::ClearMarcheNoir(){
        while(MarcheNoir.size()>0){
            delete(MarcheNoir.back());
        }
        MarcheNoir.clear();
        cout<<"la taille de marche noir est de :"<<MarcheNoir.size()<<endl;
    }

    /*PlateauJoueur Initialisation::getJoueur(int id){
        PlateauJoueur resultat;
        if (id==1){
            resultat=J1;
        }
        if(id==2){
            resultat=J2;
        }
        return resultat;
    }*/
    /*void Initialisation::setJoueur(int id,PlateauJoueur joueur){
        if (id==1){
            J1=joueur;
        }
        if(id==2){
            J2=joueur;
        }
    }*/








