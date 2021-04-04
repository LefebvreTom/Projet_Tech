#include "Animal.h"

    using namespace std;

    //constructeur
    Animal::Animal(){
    }

    Animal::Animal(int idRace,int Nb)
    {
        Id = idRace;
        stringstream sstm;
        string concac;

        //on cree une tuile animal selon son type et son nombre sur la tuile
        switch(idRace)
        {
        case 1:
            Type = "poulet";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tap"<<Nb;
            concac = sstm.str();
            Id_Site=concac;
            break;
        case 2:
            Type = "cochon";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tac"<<Nb;
            concac = sstm.str();
            Id_Site=concac;
            break;
        case 3:
            Type = "vache";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tav"<<Nb;
            concac = sstm.str();
            Id_Site=concac;
            break;
        case 4:
            Type = "mouton";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tam"<<Nb;
            concac = sstm.str();
            Id_Site=concac;
            break;

        default :
            break;


        }
    }

    Animal::Animal(int idRace,int Nb,string noir)
    {
        Id = idRace;
        stringstream sstm;
        string concac;

        //ici on cree les tuiles animaux pour le marche noir
        switch(idRace)
        {
        case 1:
            Type = "poulet";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tap"<<Nb<<"b";
            concac = sstm.str();
            Id_Site=concac;
            break;
        case 2:
            Type = "cochon";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tac"<<Nb<<"b";
            concac = sstm.str();
            Id_Site=concac;
            break;
        case 3:
            Type = "vache";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tav"<<Nb<<"b";
            concac = sstm.str();
            Id_Site=concac;
            break;
        case 4:
            Type = "mouton";
            Nombre=Nb;

            //on concatene son nom de reperage sur le site avec le nombre pour former le bon id present sur le site
            sstm<<"tam"<<Nb<<"b";
            concac = sstm.str();
            Id_Site=concac;
            break;

        default :
            break;


        }
    }
    //destructeur
        Animal::~Animal(){}

    //accesseurs

    int Animal::getNombre()
    {
        return Nombre;
    }


    //Methodes

    // f°creation random de la pile
    stack <Animal> Animal::initStackAnimal(int idRace){

        //int de test pour compter le nombre de tuiles animaux qui doivent etre present
        int testNb2=2;
        int testNb3=2;
        int testNb4=1;


        stack<Animal> StackAnimal;

        while(StackAnimal.size()<5){

            //on randomise l'apparation des tuiles dans la pile
            int resultat=(rand()%3)+2;

            switch(resultat)
            {
                case 2:
                    if(testNb2>0){
                        Animal animal = Animal(idRace,2);
                        StackAnimal.push(animal);
                        testNb2=testNb2-1;
                        cout<<"on push un animal :"<<animal.getType()<<" de nombre :"<<animal.getNombre()<<" d'id_site:"<<animal.getIdSite()<<endl;
                    }
                    break;
                case 3:
                    if(testNb3>0){
                        Animal animal = Animal(idRace,3);
                        StackAnimal.push(animal);
                        testNb3=testNb3-1;
                        cout<<"on push un animal :"<<animal.getType()<<" de nombre :"<<animal.getNombre()<<" d'id_site:"<<animal.getIdSite()<<endl;
                    }
                    break;
                case 4:
                    if(testNb4>0){
                        Animal animal = Animal(idRace,4);
                        StackAnimal.push(animal);
                        testNb4=testNb4-1;
                        cout<<"on push un animal :"<<animal.getType()<<" de nombre :"<<animal.getNombre()<<" d'id_site:"<<animal.getIdSite()<<endl;
                    }
                    break;
                default:
                    break;

            }
        }

        //cout<<"la pile fait :"<<StackAnimal.size()<<endl;
        return StackAnimal;
    }








