#include "Connaissance.h"

    using namespace std;

    //constructeur
    Connaissance::Connaissance(){
    }

    Connaissance::Connaissance(int idType)
    {
        id_Type = idType;
        switch(idType)
        {
        case 1:
            Type = "pas de restriction de batiment";
            break;
        case 2:
            Type = "+1 ouvrier par mines a la fin de phase";
            break;
        case 3:
            Type = "1 pepite de plus a la vente de machandises";
            break;
        case 4:
            Type = "+1 ouvrier par vente de marchandises";
            break;
        case 5:
            Type = "prendre d autres marchandises en posant un bateau";
            break;
        case 6:
            Type = "achat au depot noir ou aux autres depots";
            break;
        case 7:
            Type = "+1pts pour chaque tuile animal qui donne des pts";
            break;
        case 8:
            Type = "jusqu'a +/-2 a un de avec un ouvrier quand pose";
            break;
        case 9:
            Type = "+/-1 pour placer des batiments";
            break;
        case 10:
            Type = "+/-1 pour placer des bateaux ou animaux";
            break;
        case 11:
            Type = "+/-1 pour placer des chateaux, mines ou connaissances";
            break;
        case 12:
            Type = "+-1 pour prendre des tuiles hexagonales";
            //dos noir
            break;
        case 13:
            Type = "+1 a chaque fois pepites en vendant un de";
            break;
        case 14:
            Type = "+4 a chaque fois (au lieu de 2) ouvriers en vendant un de";
            //dos noir
            break;
        case 15:
            Type = "+3pts a la fin pour chaque types de marchandises vendus";
            //dos noir
            break;
        case 16:
            Type = "+4pts a la fin pour chaque entreprot ";
            break;
        case 17:
            Type = "+4pts a la fin pour chaque tour";
            break;
        case 18:
            Type = "+4pts a la fin pour chaque menuiserie";
            break;
        case 19:
            Type = "+4pts a la fin pour chaque eglise";
            break;
        case 20:
            Type = "+4pts a la fin pour chaque marche";
            break;
        case 21:
            Type = "+4pts a la fin pour chaque pension";
            break;

        case 22:
            Type = "+4pts a la fin pour chaque banque";
            break;

        case 23:
            Type = "+4pts a la fin pour chaque mairie";
            break;
        case 24:
            Type = "+4pts a la fin pour chaque type d animal";
            //dos noir
            break;

        case 25:
            Type = "+1pts a la fin pour chaque marchandises vendues";
            //dos noir
            break;

        case 26:
            Type = "+2pts a la fin pour chaque tuiles bonus";
            break;



        default :
            break;


        }
    }

    //accesseurs

    string Connaissance::getType()
    {
        return Type;
    }

    int Connaissance::getIdType()
    {
        return id_Type;
    }


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
                    if(testcas[7]>0){
                        Connaissance connaissance = Connaissance(7);
                        StackConnaissance.push(connaissance);
                        testcas[7]=0;
                        cout<<"on push :"<<connaissance.getType()<<endl;
                    }
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








