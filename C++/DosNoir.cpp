#include "DosNoir.h"

using namespace std;

    //constructeur
    DosNoir::DosNoir()
    {
    }

    //destructeur
    DosNoir::~DosNoir(){}

    //accesseur

    //Methodes
    // f°creation des piles
    vector <Tuiles*> DosNoir::initStackDosNoir()
    {

        //on passe par un vector car les tuiles sont polymorphes car la classe mere Tuiles est abstraite
        vector<Tuiles*> StackDosNoir;

        //on test le nombre de tuiles du type qu'il reste a cree
        int testcas[26]={0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,6}; //8*1+10*2+6*1+6
        cout<<"La pile du Marche Noir"<<endl;

        while(StackDosNoir.size()<40){

            //on randomise l'apparition dans la pile
            int resultat=(rand()%25)+1;

            switch(resultat){

                //pour chaque cas on appelle le constructeur speciale marche noir de chaque tuiles
                case 1:
                    if(testcas[1]>0){

                        Animal* animal =new Animal(1,3,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[1]=testcas[1]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 2:
                    if(testcas[2]>0){

                        Animal* animal =new Animal(1,4,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[2]=testcas[2]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 3:
                    if(testcas[3]>0){

                        Animal* animal =new Animal(2,3,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[3]=testcas[3]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 4:
                    if(testcas[4]>0){

                        Animal* animal =new Animal(2,4,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[4]=testcas[4]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 5:
                    if(testcas[5]>0){

                        Animal* animal =new Animal(3,3,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[5]=testcas[5]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 6:
                    if(testcas[6]>0){

                        Animal* animal =new Animal(3,4,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[6]=testcas[6]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 7:
                    if(testcas[7]>0){

                        Animal* animal =new Animal(4,3,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[7]=testcas[7]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;
                case 8:
                    if(testcas[8]>0){

                        Animal* animal =new Animal(4,4,"noir");
                        StackDosNoir.push_back(animal);
                        testcas[8]=testcas[8]-1;
                        cout<<"on push un animal :"<<animal->getType()<<" de nombre :"<<animal->getNombre()<<" d'id_site:"<<animal->getIdSite()<<endl;
                    }
                    break;

                case 9:
                    if(testcas[9]>0){

                        Batiment* bat =new Batiment(3,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[9]=testcas[9]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 10:
                    if(testcas[10]>0){

                        Batiment* bat =new Batiment(6,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[10]=testcas[10]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 11:
                    if(testcas[11]>0){

                        Batiment* bat =new Batiment(7,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[11]=testcas[11]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 12:
                    if(testcas[12]>0){

                        Batiment* bat =new Batiment(2,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[12]=testcas[12]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 13:
                    if(testcas[13]>0){

                        Batiment* bat =new Batiment(4,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[13]=testcas[13]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 14:
                    if(testcas[14]>0){

                        Batiment* bat =new Batiment(8,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[14]=testcas[14]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 15:
                    if(testcas[15]>0){

                        Batiment* bat =new Batiment(5,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[15]=testcas[15]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 16:
                    if(testcas[16]>0){

                        Batiment* bat =new Batiment(1,"noir");
                        StackDosNoir.push_back(bat);
                        testcas[16]=testcas[16]-1;
                        cout<< "On push un Batiment de type : " << bat->getType()<<" et d'id_site :"<<bat->getIdSite()<<endl;
                    }
                    break;
                case 17:
                    if(testcas[17]>0){

                        Mine* mine =new Mine("noir");
                        StackDosNoir.push_back(mine);
                        testcas[17]=testcas[17]-1;
                        cout <<"On push une mine de couleur : " << mine->getCouleur()<<" d'id_site:"<<mine->getIdSite()<<endl;
                    }
                    break;
                case 18:
                    if(testcas[18]>0){

                        Chateau* castle =new Chateau("noir");
                        StackDosNoir.push_back(castle);
                        testcas[18]=testcas[18]-1;
                        cout <<"On push un chateau de couleur : " << castle->getCouleur()<<" d'id_site:"<<castle->getIdSite()<<endl;
                    }
                    break;
                case 19:
                    if(testcas[19]>0){

                        Connaissance* connaissance =new Connaissance(7);
                        StackDosNoir.push_back(connaissance);
                        testcas[19]=testcas[19]-1;
                        cout<<"on push :"<<connaissance->getType()<<endl;
                    }
                    break;
                case 20:
                    if(testcas[20]>0){

                        Connaissance* connaissance =new Connaissance(12);
                        StackDosNoir.push_back(connaissance);
                        testcas[20]=testcas[20]-1;
                        cout<<"on push :"<<connaissance->getType()<<endl;
                    }
                    break;
                case 21:
                    if(testcas[21]>0){

                        Connaissance* connaissance =new Connaissance(14);
                        StackDosNoir.push_back(connaissance);
                        testcas[21]=testcas[21]-1;
                        cout<<"on push :"<<connaissance->getType()<<endl;
                    }
                    break;
                case 22:
                    if(testcas[22]>0){

                        Connaissance* connaissance =new Connaissance(15);
                        StackDosNoir.push_back(connaissance);
                        testcas[22]=testcas[22]-1;
                        cout<<"on push :"<<connaissance->getType()<<endl;
                    }
                    break;
                case 23:
                    if(testcas[23]>0){

                        Connaissance* connaissance =new Connaissance(24);
                        StackDosNoir.push_back(connaissance);
                        testcas[23]=testcas[23]-1;
                        cout<<"on push :"<<connaissance->getType()<<endl;
                    }
                    break;
                case 24:
                    if(testcas[24]>0){

                        Connaissance* connaissance =new Connaissance(25);
                        StackDosNoir.push_back(connaissance);
                        testcas[24]=testcas[24]-1;
                        cout<<"on push :"<<connaissance->getType()<<endl;
                    }
                    break;
                case 25:
                    if(testcas[25]>0){

                        Bateau* boat =new Bateau("noir");
                        StackDosNoir.push_back(boat);
                        testcas[25]=testcas[25]-1;
                        cout <<"On push un bateau de couleur : " << boat->getCouleur()<<" d'id_site:"<<boat->getIdSite()<<endl;
                    }
                    break;
                default:
                    break;
            }

        }

        //on test la taille de la pile a la fin de sa creation
        cout<<"taille pile :"<<StackDosNoir.size()<<endl;

        return StackDosNoir;

    }


