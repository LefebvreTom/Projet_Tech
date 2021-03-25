#include "Connaissance.h"

    using namespace std;

    //constructeur
    Connaissance::Connaissance(){
    }

    Connaissance::Connaissance(int idType)
    {
        Id = idType;
        switch(idType)
        {
        case 1:
            Type = "pas de restriction de batiment";
            Id_Site ="tk1";
            break;
        case 2:
            Type = "+1 ouvrier par mines a la fin de phase";
            Id_Site ="tk2";
            break;
        case 3:
            Type = "1 pepite de plus a la vente de machandises";
            Id_Site ="tk3";
            break;
        case 4:
            Type = "+1 ouvrier par vente de marchandises";
            Id_Site ="tk4";
            break;
        case 5:
            Type = "prendre d autres marchandises en posant un bateau";
            Id_Site ="tk5";
            break;
        case 6:
            Type = "achat au depot noir ou aux autres depots";
            Id_Site ="tk6";
            break;
        case 7:
            Type = "+1pts pour chaque tuile animal qui donne des pts";
            //dos noir
            Id_Site ="tk7b";
            break;
        case 8:
            Type = "jusqu'a +/-2 a un de avec un ouvrier quand pose";
            Id_Site ="tk8";
            break;
        case 9:
            Type = "+/-1 pour placer des batiments";
            Id_Site ="tk9";
            break;
        case 10:
            Type = "+/-1 pour placer des bateaux ou animaux";
            Id_Site ="tk10";
            break;
        case 11:
            Type = "+/-1 pour placer des chateaux, mines ou connaissances";
            Id_Site ="tk11";
            break;
        case 12:
            Type = "+-1 pour prendre des tuiles hexagonales";
            //dos noir
            Id_Site ="tk12b";
            break;
        case 13:
            Type = "+1 a chaque fois pepites en vendant un de";
            Id_Site ="tk13";
            break;
        case 14:
            Type = "+4 a chaque fois (au lieu de 2) ouvriers en vendant un de";
            //dos noir
            Id_Site ="tk14b";
            break;
        case 15:
            Type = "+3pts a la fin pour chaque types de marchandises vendus";
            //dos noir
            Id_Site ="tk15b";
            break;
        case 16:
            Type = "+4pts a la fin pour chaque entreprot ";
            Id_Site ="tk16";
            break;
        case 17:
            Type = "+4pts a la fin pour chaque tour";
            Id_Site ="tk17";
            break;
        case 18:
            Type = "+4pts a la fin pour chaque menuiserie";
            Id_Site ="tk18";
            break;
        case 19:
            Type = "+4pts a la fin pour chaque eglise";
            Id_Site ="tk19";
            break;
        case 20:
            Type = "+4pts a la fin pour chaque marche";
            Id_Site ="tk20";
            break;
        case 21:
            Type = "+4pts a la fin pour chaque pension";
            Id_Site ="tk21";
            break;

        case 22:
            Type = "+4pts a la fin pour chaque banque";
            Id_Site ="tk22";
            break;

        case 23:
            Type = "+4pts a la fin pour chaque mairie";
            Id_Site ="tk23";
            break;
        case 24:
            Type = "+4pts a la fin pour chaque type d animal";
            //dos noir
            Id_Site ="tk24b";
            break;

        case 25:
            Type = "+1pts a la fin pour chaque marchandises vendues";
            //dos noir
            Id_Site ="tk25b";
            break;

        case 26:
            Type = "+2pts a la fin pour chaque tuiles bonus";
            Id_Site ="tk26";
            break;



        default :
            break;


        }
    }

    //destructeur
        Connaissance::~Connaissance(){}

    //accesseurs


    //Methodes

    // f°creation random de la pile
    stack <Connaissance> Connaissance::initStackConnaissance(){
        stack<Connaissance> StackConnaissance;
        int testcas[27]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

        while(StackConnaissance.size()<20){
            int resultat=(rand()%26)+1;
            switch(resultat){

                case 1:
                    if(testcas[1]>0){
                        Connaissance connaissance = Connaissance(1);
                        StackConnaissance.push(connaissance);
                        testcas[1]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 2:
                    if(testcas[2]>0){
                        Connaissance connaissance = Connaissance(2);
                        StackConnaissance.push(connaissance);
                        testcas[2]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 3:
                    if(testcas[3]>0){
                        Connaissance connaissance = Connaissance(3);
                        StackConnaissance.push(connaissance);
                        testcas[3]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 4:
                    if(testcas[4]>0){
                        Connaissance connaissance = Connaissance(4);
                        StackConnaissance.push(connaissance);
                        testcas[4]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 5:
                    if(testcas[5]>0){
                        Connaissance connaissance = Connaissance(5);
                        StackConnaissance.push(connaissance);
                        testcas[5]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 6:
                    if(testcas[6]>0){
                        Connaissance connaissance = Connaissance(6);
                        StackConnaissance.push(connaissance);
                        testcas[6]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 7:
                    //dos noir
                    break;
                case 8:
                    if(testcas[8]>0){
                        Connaissance connaissance = Connaissance(8);
                        StackConnaissance.push(connaissance);
                        testcas[8]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 9:
                    if(testcas[9]>0){
                        Connaissance connaissance = Connaissance(9);
                        StackConnaissance.push(connaissance);
                        testcas[9]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 10:
                    if(testcas[10]>0){
                        Connaissance connaissance = Connaissance(10);
                        StackConnaissance.push(connaissance);
                        testcas[10]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 11:
                    if(testcas[11]>0){
                        Connaissance connaissance = Connaissance(11);
                        StackConnaissance.push(connaissance);
                        testcas[11]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 12:
                    //dos noir
                    break;
                case 13:
                    if(testcas[13]>0){
                        Connaissance connaissance = Connaissance(13);
                        StackConnaissance.push(connaissance);
                        testcas[13]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 14:
                    //dos noir
                    break;
                case 15:
                    //dos noir
                    break;
                case 16:
                    if(testcas[16]>0){
                        Connaissance connaissance = Connaissance(16);
                        StackConnaissance.push(connaissance);
                        testcas[16]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 17:
                    if(testcas[17]>0){
                        Connaissance connaissance = Connaissance(17);
                        StackConnaissance.push(connaissance);
                        testcas[17]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 18:
                    if(testcas[18]>0){
                        Connaissance connaissance = Connaissance(18);
                        StackConnaissance.push(connaissance);
                        testcas[18]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 19:
                    if(testcas[19]>0){
                        Connaissance connaissance = Connaissance(19);
                        StackConnaissance.push(connaissance);
                        testcas[19]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 20:
                    if(testcas[20]>0){
                        Connaissance connaissance = Connaissance(20);
                        StackConnaissance.push(connaissance);
                        testcas[20]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 21:
                    if(testcas[21]>0){
                        Connaissance connaissance = Connaissance(21);
                        StackConnaissance.push(connaissance);
                        testcas[21]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 22:
                    if(testcas[22]>0){
                        Connaissance connaissance = Connaissance(22);
                        StackConnaissance.push(connaissance);
                        testcas[22]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 23:
                    if(testcas[23]>0){
                        Connaissance connaissance = Connaissance(23);
                        StackConnaissance.push(connaissance);
                        testcas[23]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;
                case 24:
                    //dos noir
                    break;
                case 25:
                    //dos noir
                    break;
                case 26:
                    if(testcas[26]>0){
                        Connaissance connaissance = Connaissance(26);
                        StackConnaissance.push(connaissance);
                        testcas[26]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
                    break;

            }


        }
        cout<<"taille de la pile: "<<StackConnaissance.size()<<endl;
        return StackConnaissance;
    }









