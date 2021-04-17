#include "Simulateur.h"

    using namespace std;

    //constructeur
    Simulateur::Simulateur(){
    }

    //methode
    void Simulateur::jouer()
    {

        //"clear de console"
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<endl;

        system("python ../Python/login.py ");

        Partie partie;

        PlateauJoueur joueur1;
        PlateauJoueur joueur2;

        PlateauCentral marche;

        partie.MajPlateauJoueur("J1");
        partie.MajPlateauJoueur("J2");

        marche=partie.getMarche();

        int quijoue=marche.recupJoueur(1);

        if(quijoue==1){
            joueur1=partie.getJoueur(1);
            joueur2=partie.getJoueur(2);
        }
        else{
            joueur1=partie.getJoueur(2);
            joueur2=partie.getJoueur(1);
        }

        //----------------------------------------------------------------------------------------------------------------------

        //on commence le simulateur


        PlateauJoueur joueurcourant;

        for(int J=1;J<=2;J++){
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<endl;
            if(J==1){
                joueurcourant=joueur1;
            }
            else{
                joueurcourant=joueur2;
            }


            //les des de bases du joueur
            int de1=joueurcourant.getde(1) ;
            int de2=joueurcourant.getde(2);

            testVenteMarch(joueurcourant,de1,de2);





            //test sur les ouvriers
            int ouvrier = joueurcourant.getOuvrier();

            //si on a des ouvriers
            if(ouvrier>0){
                cout<<"vous avez "<<ouvrier<<"ouvriers"<<endl;
                cout<<endl;
                for(int i=1;i<=ouvrier;i++){
                        cout<<"en utilisant "<<i<<" ouvriers :"<<endl;


                        //le de 1 modifie
                        de1=joueurcourant.getde(1);
                        cout<<"votre de 1="<<de1<<endl;
                        int de11=de1;
                        int de12=de1;
                        if((de1-i)%6==0){
                            de11=6;
                        }
                        else{
                            de11=(de11-i)%6;
                        }
                        if((de1+i)%6==0){
                            de12=6;
                        }
                        else{
                            de12=(de12+i)%6;
                        }
                        cout<<" peut devenir un :"<<de11<<" ou "<<de12<<endl;
                        testVenteMarch(joueurcourant,de11,de12);

                        cout<<endl;

                        //le de 2 modifie
                        de2=joueurcourant.getde(2);
                        cout<<"votre de 2="<<de2<<endl;
                        int de21=de2;
                        int de22=de2;

                        if((de21-i)%6==0){
                            de21=6;
                        }
                        else{
                            de21=(de21-i)%6;
                        }
                        if((de22+i)%6==0){
                            de22=6;
                        }
                        else{
                            de22=(de22+i)%6;
                        }
                        cout<<" peut devenir un :"<<de21<<" ou "<<de22<<endl;
                        testVenteMarch(joueurcourant,de21,de22);

                        cout<<endl;
                }
            }


        }








    }


    void Simulateur::testVenteMarch(PlateauJoueur joueur, int de1, int de2){
        int tabMarch[3][2];
        for(int i=0;i<3;i++){
            tabMarch[i][0]=joueur.getMarch(i);
            tabMarch[i][1]=joueur.getNbMarch(i);

            if(tabMarch[i][0]==de1){
                cout<<"vous pouvez vendre les marchandise d'id:"<<tabMarch[i][0]<<" avec le de de valeur "<<de1<<endl;
            }
            else if(tabMarch[i][0]==de2){
                cout<<"vous pouvez vendre les marchandise d'id:"<<tabMarch[i][0]<<" avec le de de valeur "<<de2<<endl;
            }

        }
        cout<<endl;


    }

