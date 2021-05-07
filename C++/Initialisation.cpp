
#include "Initialisation.h"
    using namespace std;

    //constructeur
    Initialisation::Initialisation()
    {

        //on appelle les methodes d'initialisations des piles et tableaux necessaires au demarrage du jeu
        InitTabMarchandise();
        //cout<<endl;
        InitTabBatiment();
        //cout<<endl;
        InitPileChateau();
        //cout<<endl;
        InitPileBateau();
        //cout<<endl;
        InitPileMines();
        //cout<<endl;
        InitTabAnimal();
        //cout<<endl;
        InitPileConnaissance();
        //cout<<endl;
        InitPileMarcheNoir();
        //cout<<endl;
        InitTabBonus();
        //cout<<endl;



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

            //cout<<"tabMarchandise ("<<i<<"):"<<endl;
            //affichetest.AffichagePileMarch(TabMarchandise[i]);

        }

    }

    //init du tableau de batiment
    void Initialisation::InitTabBatiment(){

        for(int i=0;i<8;i++){
            Batiment Stack;
            stack <Batiment> StackBat = Stack.initStackBatiment(i+1);
            TabBatiment[i] = StackBat;
            //cout<<"tabBatiment ("<<i<<"):"<<endl;
            //affichetest.AffichagePileBatiment(TabBatiment[i]);

        }

    }

    //init du tableau d'animaux
    void Initialisation::InitTabAnimal(){

        for(int i=0;i<4;i++){
            Animal Stack;
            stack <Animal> StackAnimal = Stack.initStackAnimal(i+1);
            TabAnimal[i] = StackAnimal;
            //cout<<"tabAnimal ("<<i<<"):"<<endl;
            //affichetest.AffichagePileAnimal(TabAnimal[i]);

        }

    }

    void Initialisation::InitTabBonus(){

        for(int i=0;i<6;i++){
            Bonus Stack;
           // cout<<"tabBonus ("<<i<<"):"<<endl;
            stack <Bonus> StackBonus = Stack.initStackBonus(i+1);
            TabBonus[i] = StackBonus;

        }

    }

    //init du tableau de bonus


    //initialisation des piles

    //pile de chateau
    void Initialisation::InitPileChateau(){
        Chateau c;
        TabChateau = c.initStackChateau();
        //affichetest.AffichagePileChateau(StackCastle);
    }

    //pile de bateau
    void Initialisation::InitPileBateau(){
        Bateau b;
        TabBateau = b.initStackBateau();
        //affichetest.AffichagePileBateau(StackBoat);
    }

    //pile de mines
    void Initialisation::InitPileMines(){
        Mine m;
        TabMine = m.initStackMine();
        //affichetest.AffichagePileMine(StackMines);
    }

    //pile de Connaissance
    void Initialisation::InitPileConnaissance(){
        Connaissance c;
        TabConnaissance = c.initStackConnaissance();
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
    Chateau Initialisation::getChateau(){
        Chateau c = TabChateau.top();
        TabChateau.pop();
        return c;
    }

    Bateau Initialisation::getBateau(){
        Bateau b = TabBateau.top();
        TabBateau.pop();
        return b;
    }

    Mine Initialisation::getMine(){
        Mine m = TabMine.top();
        TabMine.pop();
        return m;
    }

    Connaissance Initialisation::getConnaissance(){
        Connaissance c = TabConnaissance.top();
        TabConnaissance.pop();
        return c;
    }

    Animal Initialisation::getAnimal(){
        /*int i = 0;
        while(TabAnimal[i] == NULL && TabAnimal.){
            i++;
        }*/
        int r=(rand()%3)+1;
        Animal a = TabAnimal[r].top();
        TabAnimal[r].pop();
        return a;
    }

    Batiment Initialisation::getBatiment(){
        int r=(rand()%7)+1;
        Batiment b = TabBatiment[r].top();
        TabBatiment[r].pop();
        return b;
    }
    Marchandise Initialisation::getMarchandise(){

        int r=(rand()%5)+1;
        Marchandise m = Marchandise(r);
        return m;
    }
    string Initialisation::getDosNoir(){
        Tuiles * t;
        t=MarcheNoir.back();
        MarcheNoir.pop_back();
        string s = t->getIdSite();
        return s;
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








