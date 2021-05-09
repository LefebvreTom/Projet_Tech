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

        //lancement du programme python qui met à jour depuis le site
        system("python ../Python/login.py ");

        //initialisation des plateaux etc
        Partie partie;


        PlateauJoueur joueur1;
        PlateauJoueur joueur2;
        //PlateauJoueur test = copieJoueur(joueur1);
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
        //----------------------------------------------------------------------------------------------------------------------

        cout<<"Bonjour"<<endl;
        //on commence le simulateur
        PlateauJoueur joueurcourant;
        joueurcourant =joueur2;


    //test achat ---------------------------------------------------------------------------------------------------------------
        /*cout<<"pepite :"<<joueurcourant.getPepite()<<endl;
        if(testReserveVide(joueurcourant)){
            cout<<"test reserve"<<endl;
        }
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getReserve(i)<<endl;
        }

        cout<<"marche noir :"<<endl;
        for(int i=0;i<4;i++){
            cout<<marche.getTuileMarche(6,i)<<endl;
        }

        achatPepite(joueurcourant,marche,1);

        cout<<"apres achat de la tuile d'id 1"<<endl;
        cout<<"pepite :"<<joueurcourant.getPepite()<<endl;
        cout<<"test reserve :"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getReserve(i)<<endl;
        }

        cout<<"marche noir :"<<endl;
        for(int i=0;i<4;i++){
            cout<<marche.getTuileMarche(6,i)<<endl;
        }*/

    //test ouvrier -------------------------------------------------------------------------------------------------------------
        cout<<"***********************************"<<endl;
        cout<<"ouvrier :"<<joueurcourant.getOuvrier()<<endl;
        cout<<"de 1:"<<joueurcourant.getde(1)<<endl;
        cout<<"chgt du de 1 :2 avec 2 ouvrier en plus pour faire un 4"<<endl;
        cout<<utilisationOuvrier(joueurcourant,1,2,true)<<endl;
        cout<<"ouvrier :"<<joueurcourant.getOuvrier()<<endl;
        cout<<"de 1 modif:"<<joueurcourant.getde(1)<<endl;

    //test venteDe -------------------------------------------------------------------------------------------------------------
       /* cout<<"***********************************"<<endl;
        cout<<"ouvrier :"<<joueurcourant.getOuvrier()<<endl;
        cout<<"en vendant le de 1 "<<endl;
        cout<<venteDe(joueurcourant,1)<<endl;
        cout<<"ouvrier modif:"<<joueurcourant.getOuvrier()<<endl;
        cout<<"de1 :"<<joueurcourant.getde(1)<<" /de 2 :"<<joueurcourant.getde(2)<<endl;*/

    //test venteMarchandise ----------------------------------------------------------------------------------------------------
       /* cout<<"***********************************"<<endl;
        cout<<"pepite :"<<joueurcourant.getPepite()<<endl;
        cout<<"tab march:"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<" / "<<joueurcourant.getNbMarch(i)<<endl;
        }
        cout<<"tab vendu:"<<endl;
        for(int i=0;i<6;i++){
            cout<<"march "<<i<<":"<<joueurcourant.getNbMarchVendu(i)<<endl;
        }

        cout<<venteMarchandise(joueurcourant,4)<<endl;

        cout<<"pepite modif:"<<joueurcourant.getPepite()<<endl;
        cout<<"tab march modif:"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<" / "<<joueurcourant.getNbMarch(i)<<endl;
        }
        cout<<"tab vendu modif:"<<endl;
        for(int i=0;i<6;i++){
            cout<<"march "<<i<<":"<<joueurcourant.getNbMarchVendu(i)<<endl;
        }
        cout<<"de1 :"<<joueurcourant.getde(1)<<" /de 2 :"<<joueurcourant.getde(2)<<endl;*/



        //test achatTuile ----------------------------------------------------------------------------------------------
        cout<<"affichage du marche"<<endl;
        for(int i=0;i<7;i++){
            for(int j=0;j<8;j++){
                cout<<marche.getTuileMarche(i,j)<<"/";
            }
            cout<<endl;
        }

        cout<<"test achat"<<endl;

        cout<<"reserve"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getReserve(i)<<endl;
        }

        cout<<"march"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<"/"<<joueurcourant.getNbMarch(i)<<endl;
        }

        cout<<achatTuile(joueurcourant,marche,2,6);

        cout<<"test modif"<<endl;

        cout<<"reserve"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getReserve(i)<<endl;
        }

        cout<<"march"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<"/"<<joueurcourant.getNbMarch(i)<<endl;
        }

        //affichage des dés
        cout<<"de 1:"<<joueurcourant.getde(1)<<"/de 2:"<<joueurcourant.getde(2)<<endl;

        //test posage de tuile
        cout<<"test posage tuile bateau avec le de 2 sur la case 31"<<endl;
        cout<<posageTuile(joueurcourant,1,2,31)<<endl; //si ca affiche 1 ca marche

        //affichage des dés
        cout<<"de 1:"<<joueurcourant.getde(1)<<"/de 2:"<<joueurcourant.getde(2)<<endl;

        //test action bateau
        cout<<endl;
        cout<<"posage du bateau"<<endl;
        actionBateau(joueurcourant,marche,2); //recup des marchandises de la zone 3 (2 car on commence a 0)

        cout<<"march joueur"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<"/"<<joueurcourant.getNbMarch(i)<<endl;
        }

        cout<<"affichage du marche"<<endl;
        for(int i=0;i<7;i++){
            for(int j=0;j<8;j++){
                cout<<marche.getTuileMarche(i,j)<<"/";
            }
            cout<<endl;
        }

        //action de la pension et de la banque
        cout<<endl;
        cout<<"posage pension et banque"<<endl;
        cout<<"ouvrier avant :"<<joueurcourant.getOuvrier()<<endl;
        cout<<"pepite avant :"<<joueurcourant.getPepite()<<endl;
        actionPension(joueurcourant);
        actionBanque(joueurcourant);
        cout<<"ouvrier apres :"<<joueurcourant.getOuvrier()<<endl;
        cout<<"pepite apres :"<<joueurcourant.getPepite()<<endl;

        //action entrepot
        cout<<endl;
        cout<<"posage entrepot"<<endl;
        cout<<"pepite avant :"<<joueurcourant.getPepite()<<endl;
        cout<<"march avant:"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<"/"<<joueurcourant.getNbMarch(i)<<endl;
        }
        cout<<"marchVendu avant:"<<endl;
        for(int i=0;i<6;i++){
            cout<<"march "<<i<<":"<<joueurcourant.getNbMarchVendu(i)<<endl;
        }
        actionEntrepot(joueurcourant,0);//vente des marchandises stockés en premiere
        cout<<endl;
        cout<<"pepite apres :"<<joueurcourant.getPepite()<<endl;
        cout<<"march apres:"<<endl;
        for(int i=0;i<3;i++){
            cout<<joueurcourant.getMarch(i)<<"/"<<joueurcourant.getNbMarch(i)<<endl;
        }
        cout<<"marchVendu apres:"<<endl;
        for(int i=0;i<6;i++){
            cout<<"march "<<i<<":"<<joueurcourant.getNbMarchVendu(i)<<endl;
        }


        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;





    //----------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
       /* for(int J=1;J<=2;J++){
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

            //les pepites de bases
            int pepite=joueurcourant.getPepite();

            testVenteMarch(joueurcourant,de1,de2,marche);

            //test sur les pepites
            cout<<"*******************"<<endl;
            testPepite(joueurcourant,marche,pepite);

            //test sur la reserve avec les dés de bases
            cout<<"*******************"<<endl;
            testPosage(joueurcourant,de1,de2);

            //test sur l'achat avec les dés de bases
            cout<<"*******************"<<endl;
            testAchat(marche,de1,de2);


            //test sur les ouvriers
            cout<<"*******************"<<endl;
            testOuvrier(joueurcourant,de1,de2,false,false,marche);

            //test vente de de
            cout<<"*******************"<<endl;
            cout<<"en vendant le de1"<<endl;
            testOuvrier(joueurcourant,de1,de2,true,false,marche);

            cout<<"*******************"<<endl;
            cout<<"en vendant le de2"<<endl;
            testOuvrier(joueurcourant,de1,de2,false,true,marche);


            cout<<"*******************"<<endl;
            cout<<"en vendant les 2 des"<<endl;
            testOuvrier(joueurcourant,de1,de2,true,true,marche);


        }*/
        //cout<<joueur2.totalAnimauxDistrict(10)<<endl;
        /*finDeTour(marche,joueur1,joueur2);
        finDeTour(marche,joueur1,joueur2);
        finDeTour(marche,joueur1,joueur2);*/
    }
    void Simulateur::finDeTour(PlateauCentral &marche,PlateauJoueur &J1,PlateauJoueur &J2){
        if(marche.getTour() < 5){
            string marchandiseTour = marche.getMarchandiseTour();
            marche.addMarchandiseListeTuileCentrale(marchandiseTour,marche.getDeMarchandise()-1);
            /*for(int i =0; i < 7;i++){
                cout<<"ligne : "<<i<<endl;
                    for(int j =0; j < 8;j++){
                        cout<<marche.getTuileMarche(i,j)<<endl;
                    }
            }*/
            marche.setTour(marche.getTour()+1);
        }
        else{
                //ajouter un test sur les mines et lancer setPepite avec le nombre mine
                /*cout<<endl;
                cout<<"--------------------------------"<<endl;
                cout<<"pepite joueur 1:"<<J1.getPepite()<<endl;
                cout<<"pepite joueur 2:"<<J2.getPepite()<<endl;*/
                actionMine(J1);
                actionMine(J2);
                //cout<<"pepite joueur 1 modif:"<<J1.getPepite()<<endl;
                //cout<<"pepite joueur 2 modif:"<<J2.getPepite()<<endl;

                int id = 0;
                while(id < 12){
                    //cout<<"test while:"<<id<<endl;
                    int type = marche.getDeMarchandise();
                    if(type == 1){
                        //cout<<"Chateau"<<endl;
                        Chateau c = marche.getInit().getChateau();
                        marche.addTuileListeTuileCentrale(c.getIdSite(),id/2,(id%2)+6);
                        //cout<<c.getIdSite()<<endl;
                        id++;
                    }
                    if(type == 2){
                        //cout<<"Bateau"<<endl;
                        Bateau b = marche.getInit().getBateau();
                        marche.addTuileListeTuileCentrale(b.getIdSite(),id/2,(id%2)+6);
                        //cout<<b.getIdSite()<<endl;
                        id++;
                    }
                    if(type == 3){
                        //cout<<"Mine"<<endl;
                        Mine m = marche.getInit().getMine();
                        marche.addTuileListeTuileCentrale(m.getIdSite(),id/2,(id%2)+6);
                        //cout<<m.getIdSite()<<endl;
                        id++;
                    }
                    if(type == 4){
                        //cout<<"Connaissance"<<endl;
                        Connaissance c = marche.getInit().getConnaissance();
                        marche.addTuileListeTuileCentrale(c.getIdSite(),id/2,(id%2)+6);
                        //cout<<c.getIdSite()<<endl;
                        id++;
                    }
                    if(type == 5){
                        //cout<<"Animal"<<endl;
                        Animal a = marche.getInit().getAnimal();
                        marche.addTuileListeTuileCentrale(a.getIdSite(),id/2,(id%2)+6);
                        //cout<<a.getIdSite()<<endl;
                        id++;
                    }
                    if(type == 6){
                        //cout<<"Batiment"<<endl;
                        Batiment b = marche.getInit().getBatiment();
                        marche.addTuileListeTuileCentrale(b.getIdSite(),id/2,(id%2)+6);
                        //cout<<b.getIdSite()<<endl;
                        id++;
                    }
                }
                for(int i =0;i < 4;i++){
                    string s = marche.getInit().getDosNoir();
                    //cout<<s<<endl;
                    marche.addTuileListeTuileCentrale(s,6,i);
                }
                for(int i =0;i < 5;i++){
                    //cout<<"test for:"<<i<<endl;
                    Marchandise m = marche.getInit().getMarchandise();
                    //cout<<m.getIdSite()<<endl;
                    marche.setMarchandiseTour(m.getIdSite());
                }
                string marchandiseTour = marche.getMarchandiseTour();
                marche.addMarchandiseListeTuileCentrale(marchandiseTour,marche.getDeMarchandise()-1);
                marche.setTour(1);
                marche.setPhase(marche.getPhase()+1);
        }
        //cout<<"Phase : "<<marche.getPhase()<<"Tour : "<<marche.getTour() <<endl;
    }
    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------


    void Simulateur::testOuvrier(PlateauJoueur joueurcourant,int de1, int de2,bool de1vendu,bool de2vendu,PlateauCentral marche){
        int ouvrier = joueurcourant.getOuvrier();

        //si on a vendu les 2 des
        if(de1vendu && de2vendu){
            ouvrier=ouvrier+2;
            cout<<"vous avez plus de des"<<endl;
        }

        //si le de1 est vendu mais pas le de2
        if(de1vendu && !de2vendu){
            ouvrier=ouvrier+2;
            cout<<"vous avez "<<ouvrier<<"ouvriers"<<endl;
            cout<<endl;
            for(int i=1;i<=ouvrier;i++){
                cout<<"en utilisant "<<i<<" ouvriers :"<<endl;
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
                    de21=(6+de21)%6;
                }
                if((de22+i)%6==0){
                    de22=6;
                }
                else{
                    de22=(de22+i)%6;
                }
                cout<<" peut devenir un :"<<de21<<" ou "<<de22<<endl;
                testVenteMarch(joueurcourant,de21,de22,marche);
                testPosage(joueurcourant,de21,de22);
                testAchat(marche,de21,de22);

                cout<<endl;

            }


        }

        //si le de2 est vendu mais pas le de1
        if(de2vendu && !de1vendu){
            ouvrier=ouvrier+2;
            cout<<"vous avez "<<ouvrier<<"ouvriers"<<endl;
            cout<<endl;
            for(int i=1;i<=ouvrier;i++){
                cout<<"en utilisant "<<i<<" ouvriers :"<<endl;
                //le de 1 modifie
                de1=joueurcourant.getde(1);
                cout<<"votre de 1="<<de1<<endl;
                int de11=de1;
                int de12=de1;

                if((de11-i)%6==0){
                    de11=6;

                }
                else{
                    de11=(de11-i)%6;
                    de11=(6+de11)%6;

                }
                if((de12+i)%6==0){
                    de12=6;
                }
                else{
                    de12=(de12+i)%6;
                }
                cout<<" peut devenir un :"<<de11<<" ou "<<de12<<endl;
                testVenteMarch(joueurcourant,de11,de12,marche);
                testPosage(joueurcourant,de11,de12);
                testAchat(marche,de11,de12);

                cout<<endl;

            }


        }




        //si on a des ouvriers et qu'aucun des 2 de n'est vendu
        if(ouvrier>0){
            if(!de1vendu && !de2vendu){
                cout<<"pas de des vendus"<<endl;
                cout<<"vous avez "<<ouvrier<<"ouvriers"<<endl;
                cout<<endl;
                for(int i=1;i<=ouvrier;i++){
                    cout<<"en utilisant "<<i<<" ouvriers :"<<endl;

                    //si le de1 n'est pas vendu
                    if(!de1vendu){
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
                            de11=(6+de11)%6;
                        }
                        if((de1+i)%6==0){
                            de12=6;
                        }
                        else{
                            de12=(de12+i)%6;
                        }
                        cout<<" peut devenir un :"<<de11<<" ou "<<de12<<endl;
                        testVenteMarch(joueurcourant,de11,de12,marche);
                        testPosage(joueurcourant,de11,de12);
                        testAchat(marche,de11,de12);
                        cout<<endl;

                    }

                    //si le de2 n'est pas vendu
                    if(!de2vendu){
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
                            de21=(6+de21)%6;
                        }
                        if((de22+i)%6==0){
                            de22=6;
                        }
                        else{
                            de22=(de22+i)%6;
                        }
                        cout<<" peut devenir un :"<<de21<<" ou "<<de22<<endl;
                        testVenteMarch(joueurcourant,de21,de22,marche);
                        testPosage(joueurcourant,de21,de22);
                        testAchat(marche,de21,de22);

                        cout<<endl;


                    }



                }

            }

        }
    }


    void Simulateur::testVenteMarch(PlateauJoueur joueur, int de1, int de2,PlateauCentral marche){
        int pepite=joueur.getPepite();
        int tabMarch[3][2];
        for(int i=0;i<3;i++){
            tabMarch[i][0]=joueur.getMarch(i);
            tabMarch[i][1]=joueur.getNbMarch(i);
            cout<<endl;

            if(tabMarch[i][0]==de1){
                cout<<"vous pouvez vendre les marchandise d'id:"<<tabMarch[i][0]<<" avec le de de valeur "<<de1<<endl;
                cout<<"alors vous obtiendrez 1 pepite de plus"<<endl;
                pepite=pepite+1;
                cout<<" ---> "<<pepite<<endl;
                testPepite(joueur,marche,pepite);
            }
            else if(tabMarch[i][0]==de2){
                cout<<"vous pouvez vendre les marchandise d'id:"<<tabMarch[i][0]<<" avec le de de valeur "<<de2<<endl;
                cout<<"alors vous obtiendrez 1 pepite de plus"<<endl;
                pepite=pepite+1;
                cout<<" ---> "<<pepite<<endl;
                testPepite(joueur,marche,pepite);
            }

        }
        cout<<endl;


    }

    bool Simulateur::testVenteMarchandise(PlateauJoueur joueur, int de, PlateauCentral marche){
        int tabMarch[3][2];
        bool test=false;
        for(int i=0;i<3;i++){
            tabMarch[i][0]=joueur.getMarch(i);
            tabMarch[i][1]=joueur.getNbMarch(i);
            //cout<<endl;

            if(tabMarch[i][0]==de){
                test=true;
            }
        }
        return test;

    }


    bool Simulateur::testPepite(PlateauJoueur joueur,PlateauCentral marche,int pepite){
        //cout<<endl;

        if(pepite==0){
            //cout<<"vous n'avez pas de pepite"<<endl;
            return false;
        }

        if(pepite>0){
            //cout<<"vous avez "<<pepite<<" pepites"<<endl;
            if(pepite>=2){
                /*cout<<"vous pouvez acheter 1 tuile au marche noir parmis :"<<endl;
                for(int j=0;j<6;j++){
                    cout<<marche.getTuileMarche(6,j)<<" ";
                }
                cout<<endl;*/
                return true;

            }
            else{
                //cout<<"vous ne pouvez rien acheter"<<endl;
                return false;
            }


        }

        return false;

    }


    void Simulateur::testPosage(PlateauJoueur joueur,int de1,int de2){

        string Reserve[3];
        int test=0;
        for(int i=0;i<3;i++){
            Reserve[i]=joueur.getReserve(i);
            if(Reserve[i].compare("")!=0){
                test=test+1;
            }
        }

        if(Reserve[0].compare("")==0 && Reserve[1].compare("")==0 && Reserve[2].compare("")==0){
            cout<<"vous n'avez pas de tuiles en reserve"<<endl;
        }
        else{
                for(int i=0;i<test;i++){
                    cout<<"vous avez des tuiles en reserve"<<endl;
                    if(Reserve[i].at(1)=='a'){
                        cout<<"c'est une tuile animal"<<endl;
                        for(int j=0;j<37;j++){
                            if(joueur.getCase(j).getType().compare("vert")==0){
                                if(joueur.getCase(j).getnumDe()==de1){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de1<<endl;
                                }
                                if(joueur.getCase(j).getnumDe()==de2){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de2<<endl;
                                }
                            }
                        }
                    }
                    if(Reserve[i].at(1)=='s'){
                        cout<<"c'est une tuile bateau"<<endl;
                        for(int j=0;j<37;j++){
                            if(joueur.getCase(j).getType().compare("bleu")==0){
                                if(joueur.getCase(j).getnumDe()==de1){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de1<<endl;
                                }
                                if(joueur.getCase(j).getnumDe()==de2){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de2<<endl;
                                }
                            }
                        }
                    }

                    if(Reserve[i].at(1)=='k'){
                        cout<<"c'est une tuile connaissance"<<endl;
                        for(int j=0;j<37;j++){
                            if(joueur.getCase(j).getType().compare("jaune")==0){
                                if(joueur.getCase(j).getnumDe()==de1){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de1<<endl;
                                }
                                if(joueur.getCase(j).getnumDe()==de2){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de2<<endl;
                                }
                            }
                        }
                    }

                    if(Reserve[i].at(1)=='c'){
                        cout<<"c'est une tuile chateau"<<endl;
                        for(int j=0;j<37;j++){
                            if(joueur.getCase(j).getType().compare("vert fonce")==0){
                                if(joueur.getCase(j).getnumDe()==de1){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de1<<endl;
                                }
                                if(joueur.getCase(j).getnumDe()==de2){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de2<<endl;
                                }
                            }
                        }
                    }

                    if(Reserve[i].at(1)=='b'){
                        cout<<"c'est une tuile batiment"<<endl;
                        for(int j=0;j<37;j++){
                            if(joueur.getCase(j).getType().compare("marron")==0){
                                if(joueur.getCase(j).getnumDe()==de1){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de1<<endl;
                                }
                                if(joueur.getCase(j).getnumDe()==de2){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de2<<endl;
                                }
                            }
                        }
                    }

                    if(Reserve[i].at(1)=='m'){
                        cout<<"c'est une tuile mines"<<endl;
                        for(int j=0;j<37;j++){
                            if(joueur.getCase(j).getType().compare("gris")==0){
                                if(joueur.getCase(j).getnumDe()==de1){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de1<<endl;
                                }
                                if(joueur.getCase(j).getnumDe()==de2){
                                    cout<<"vous pouvez la poser sur la case numero:"<<j<<" avec votre de:"<<de2<<endl;
                                }
                            }
                        }
                    }

                    //cout<<endl;
                }

        }

    }

    void Simulateur::testAchat(PlateauCentral marche,int de1, int de2)
    {
        if(de1>0){
            cout<<"vous pouvez acheter une tuile de la zone "<<de1<<" parmis :"<<endl;
            for(int col=0;col<6;col++){
                cout<<marche.getTuileMarche(de1,col)<<" ";
            }
            //cout<<endl;
        }

        if(de2>0){
            cout<<"vous pouvez acheter une tuile de la zone "<<de2<<" parmis :"<<endl;
            for(int col=0;col<6;col++){
                cout<<marche.getTuileMarche(de2,col)<<" ";
            }
            //cout<<endl;
        }


    }

    bool Simulateur::testReserveVide(PlateauJoueur joueur){
        int test=0;
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                test=test+1;
            }
        }
        if(test<3){
            //cout<<"c'est bon"<<endl;
            return true;
        }
        else{
            //cout<<"c'est pas bon"<<endl;
            return false;
        }
    }

    bool Simulateur::testPosageTuile(PlateauJoueur joueur, int de, int choixTuile, int choixCase){

            if(joueur.getReserve(choixTuile).compare("")==0){//si cette emplacement de reserve est vide
                return false;
            }
            else{//s'il y a une tuile
                if(joueur.getReserve(choixTuile).at(1)=='a'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("vert")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='s'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("bleu")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='k'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("jaune")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='c'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("vert fonce")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='b'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("marron")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='m'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("gris")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else{
                    return false;
                }

            }



        }


    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------


    PlateauJoueur Simulateur::copieJoueur(PlateauJoueur joueur){
        PlateauJoueur Copie;

        Copie.setde(1,joueur.getde(1));
        Copie.setde(2,joueur.getde(2));
        Copie.setOuvrier(joueur.getOuvrier());
        Copie.setPepite(joueur.getPepite());
        Case tab[37];

        for (int i=0;i<37;i++){
            tab[i]=joueur.getCase(i);
            Copie.setCase(i,tab[i]);
        }
        string reserve[3];

        for(int i=0;i<3;i++){
            reserve[i]=joueur.getReserve(i);
            Copie.setReserve(i,reserve[i]);
        }

        int tabMarch[3][2];
        for(int i=0;i<3;i++){
            tabMarch[i][1]=joueur.getMarch(i);
            tabMarch[i][2]=joueur.getNbMarch(i);

            Copie.setMarch(i,1,tabMarch[i][1]);
            Copie.setMarch(i,2,tabMarch[i][2]);
        }

        int tabVendu[6];
        for(int i=0;i<6;i++){
            tabVendu[i]=joueur.getNbMarchVendu(i);
            Copie.setVendu(i,tabVendu[i]);
        }
        return Copie;

    }


    PlateauCentral Simulateur::copieMarche(PlateauCentral marche){
        PlateauCentral Copie;

        string tuiles[7][8];
        for(int i=0;i<7;i++){
            for(int j=0;j<8;j++){
                tuiles[i][j]=marche.getTuileMarche(i,j);
                Copie.setTuile(i,j,tuiles[i][j]);
            }
        }
        return Copie;

    }
    //--------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------

    bool Simulateur::achatPepite(PlateauJoueur &joueur,PlateauCentral &marche,int choix){
        int pepite =joueur.getPepite();
        int nbrTuile=0; // nbr de tuiles presente dans le marche noir


            if(testPepite(joueur,marche,pepite )&& testReserveVide(joueur)){
               string marcheNoir[4];
                for(int i=0;i<4;i++){
                    marcheNoir[i]=marche.getTuileMarche(6,i);
                    if(marcheNoir[i].compare("")!=0){
                        nbrTuile=nbrTuile+1; //indique le nbr de tuiles dans le marche noir
                    }
                }

                if(choix<nbrTuile){ //le choix doit etre inferieur au nbr car l'id commence à 0
                    //cout<<"test"<<endl;
                    int test=0; //test nous donnera l'endroit ou mettre la tuile en reserve
                    for(int i=2;i>=0;i--){
                        if(joueur.getReserve(i).compare("")==0){
                            test=i;
                        }
                    }
                    joueur.setReserve(test,marche.getTuileMarche(6,choix));
                    joueur.setPepite(pepite-2);

                    marche.setTuile(6,choix,"");
                    for(int j=choix+1;j<4;j++){
                        marche.setTuile(6,j-1,marche.getTuileMarche(6,j));
                        if(j==3){
                            marche.setTuile(6,j,"");
                        }
                    }
                    return true;

                }
                else{
                    return false;
                }


            }
            else{
                //cout<<"pas de place ou pas de pepite"<<endl;
                return false;
            }


    }

    bool Simulateur::testAchatPepite(PlateauJoueur joueur,PlateauCentral marche,int choix){
        int pepite =joueur.getPepite();
        int nbrTuile=0; // nbr de tuiles presente dans le marche noir

            if(testPepite(joueur,marche,pepite )&& testReserveVide(joueur)){
               string marcheNoir[4];
                for(int i=0;i<4;i++){
                    marcheNoir[i]=marche.getTuileMarche(6,i);
                    if(marcheNoir[i].compare("")!=0){
                        nbrTuile=nbrTuile+1; //indique le nbr de tuiles dans le marche noir
                    }
                }

                if(choix<nbrTuile){ //le choix doit etre inferieur au nbr car l'id commence à 0
                    //cout<<"test"<<endl;
                    /*int test=0; //test nous donnera l'endroit ou mettre la tuile en reserve
                    for(int i=2;i>=0;i--){
                        if(joueur.getReserve(i).compare("")==0){
                            test=i;
                        }
                    }
                    joueur.setReserve(test,marche.getTuileMarche(6,choix));
                    joueur.setPepite(pepite-2);*/

                    /*marche.setTuile(6,choix,"");
                    for(int j=choix+1;j<4;j++){
                        marche.setTuile(6,j-1,marche.getTuileMarche(6,j));
                        if(j==3){
                            marche.setTuile(6,j,"");
                        }
                    }*/
                    return true;

                }
                else{
                    return false;
                }


            }
            else{
                //cout<<"pas de place ou pas de pepite"<<endl;
                return false;
            }


    }


    bool Simulateur::utilisationOuvrier(PlateauJoueur &joueur,int numde,int nbr,bool chgt){

        int de;
        if (numde==1){
            de=joueur.getde(1);
        }
        else{
            de=joueur.getde(2);
        }
        if( (nbr<=joueur.getOuvrier()) && (joueur.getOuvrier()!=0) && (de!=-1)) {
            if(chgt){ //si chgt=true -> +
                if((de+nbr)%6==0){
                    de=6;
                    joueur.setde(numde,de);
                }
                else{
                    de=(de+nbr)%6;
                    joueur.setde(numde,de);
                }
                joueur.setOuvrier(joueur.getOuvrier()-nbr);
            }
            else{ //si chgt=false -> -
                if((de-nbr+6)%6==0){
                    de=6;
                    joueur.setde(numde,de);
                }
                else{
                    de=(de-nbr+6)%6;
                    joueur.setde(numde,de);
                }
                joueur.setOuvrier(joueur.getOuvrier()-nbr);
            }
            return true;
        }

        else{
            return false;
        }


    }

    bool Simulateur::venteDe(PlateauJoueur &joueur,int choix){
        int de;
        if(choix==1){
            de=joueur.getde(1);
        }
        else{
            de=joueur.getde(2);
            choix=2;//on le force à 2
        }

        if(de==-1){ //si le dé est deja vendu ou utilisé
            return false;
        }
        else{
            joueur.setOuvrier(joueur.getOuvrier()+2);
            joueur.setde(choix,-1);
            return true;
        }
    }

    bool Simulateur::venteMarchandise(PlateauJoueur &joueur, int choix){
        int de;
        bool test;
        if(choix==1){
            de=joueur.getde(1);
        }
        else{
            de=joueur.getde(2);
            choix=2;//on le force à 2
        }

        if(de==-1){ //si le dé n'est pas vendu ou utilisé
            return false;
        }
        else{
            for(int i=0;i<3;i++){
                if(joueur.getMarch(i)==de){

                    joueur.setVendu(de-1,joueur.getNbMarchVendu(de-1)+joueur.getNbMarch(i)); //on ajoute le nbr de march vendu dans le tableau du joueur
                    joueur.setMarch(i,0,0);//on enleve la marchandise du tableau
                    joueur.setMarch(i,1,0);//on met le nbr de marchandise à 0
                    joueur.setPepite(joueur.getPepite()+1);
                    joueur.setde(choix,-1);

                    //on réarrange le tableau
                    for(int j=i;j<3;j++){
                        if(j!=2){
                            joueur.setMarch(j,0,joueur.getMarch(j+1));
                            joueur.setMarch(j,1,joueur.getNbMarch(j+1));
                        }
                        else{
                            joueur.setMarch(j,0,0);
                            joueur.setMarch(j,1,0);
                        }

                    }

                    return true;
                }
                else{
                    test=false;
                }
            }
        }
        return test;
    }


 bool Simulateur::achatTuile(PlateauJoueur &joueur,PlateauCentral &marche,int choixDe,int choix){

        int de;
        if(choixDe==1){
            de=joueur.getde(1)-1;
        }
        else{
            de=joueur.getde(2)-1;
            choixDe=2;//on le force à 2
        }

        if(de==-1){ //si le dé est vendu
            return false;
        }
        else{ //si le dé n'est pas vendu ou utilisé


                if(choix<6){//on veut une marchandise , mais pas possible
                    return false;
                }
                else{ //on veut une tuile hexagonale
                    string Reserve[3];
                    int testPlace=0;
                    int PlaceVide;
                    for(int i=0;i<3;i++){
                        Reserve[i]=joueur.getReserve(i);
                        if(Reserve[i].compare("")!=0){ //si c'est pas vide
                            testPlace=testPlace+1;
                        }
                        else{ //si la place est vide
                            PlaceVide=i;
                        }
                    }

                    if(testPlace<3){// il y a de la place dans la reserve
                        joueur.setReserve(PlaceVide,marche.getTuileMarche(de,choix));
                        marche.setTuile(de,choix,"");
                        joueur.setde(choixDe,-1);
                        return true;
                    }
                    else{
                        return false;
                    }
                }


        }



    }
void Simulateur::gestionDistrict(PlateauJoueur &joueur,PlateauCentral &marche ,int choixCase){
    if(joueur.districtPlein(choixCase)!=0){
        switch(marche.getPhase()){
            case 1:
                joueur.setScore(joueur.getScore()+joueur.districtPlein(choixCase)+10);
            break;
            case 2:
                joueur.setScore(joueur.getScore()+joueur.districtPlein(choixCase)+8);
            break;
            case 3:
                joueur.setScore(joueur.getScore()+joueur.districtPlein(choixCase)+6);
            break;
            case 4:
                joueur.setScore(joueur.getScore()+joueur.districtPlein(choixCase)+4);
            break;
            case 5:
                joueur.setScore(joueur.getScore()+joueur.districtPlein(choixCase)+2);
            break;
            default:
            break;
        }
    }
    if(joueur.couleurPlein(choixCase)!=-1){
        if(marche.getInit().getBonus(joueur.couleurPlein(choixCase)).getType().compare("grand")==0)joueur.setScore(joueur.getScore()+5);
        if(marche.getInit().getBonus(joueur.couleurPlein(choixCase)).getType().compare("petit")==0)joueur.setScore(joueur.getScore()+2);
    }
}

bool Simulateur::posageTuile(PlateauJoueur &joueur ,int choixDe,int choixTuile,int choixCase){
        int de;
        if(choixDe==1){
            de=joueur.getde(1);
        }
        else{
            de=joueur.getde(2);
            choixDe=2;//on le force à 2
        }

        if(de==-1){ //si le dé est vendu ou utilisé
            return false;
        }
        else{
            if(joueur.getReserve(choixTuile).compare("")==0){//si cette emplacement de reserve est vide
                return false;
            }
            else{//s'il y a une tuile
                if(joueur.getReserve(choixTuile).at(1)=='a'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("vert")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                Case chgt=Case(choixCase,0,joueur.getReserve(choixTuile));
                                joueur.setCase(choixCase,chgt);
                                joueur.setReserve(choixTuile,"");
                                joueur.setde(choixDe,-1);
                                joueur.setScore(joueur.getScore()+joueur.totalAnimauxDistrict(choixTuile));
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='s'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("bleu")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                Case chgt=Case(choixCase,0,joueur.getReserve(choixTuile));
                                joueur.setCase(choixCase,chgt);
                                joueur.setReserve(choixTuile,"");
                                joueur.setde(choixDe,-1);
                                if(joueur.districtPlein(choixCase)!=0){
                                    joueur.setScore(joueur.getScore()+joueur.districtPlein(choixCase));
                                }
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='k'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("jaune")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                Case chgt=Case(choixCase,0,joueur.getReserve(choixTuile));
                                joueur.setCase(choixCase,chgt);
                                joueur.setReserve(choixTuile,"");
                                joueur.setde(choixDe,-1);
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='c'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("vert fonce")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                Case chgt=Case(choixCase,0,joueur.getReserve(choixTuile));
                                joueur.setCase(choixCase,chgt);
                                joueur.setReserve(choixTuile,"");
                                joueur.setde(choixDe,-1);
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='b'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("marron")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                if(joueur.getReserve(choixTuile).compare("tb8") == 0 || joueur.getReserve(choixTuile).compare("tb8")){
                                    joueur.setScore(joueur.getScore()+4);
                                }
                                Case chgt=Case(choixCase,0,joueur.getReserve(choixTuile));
                                joueur.setCase(choixCase,chgt);
                                joueur.setReserve(choixTuile,"");
                                joueur.setde(choixDe,-1);
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else if(joueur.getReserve(choixTuile).at(1)=='m'){//c'est une tuile animal
                    if(joueur.getCase(choixCase).getType().compare("gris")==0){//on regarde si la case choisi est verte
                        if(joueur.getCase(choixCase).getnumDe()==de){ //on regarde la valeur du dé et la valeur de la case
                            if(joueur.updateCaseDisponible(choixCase)){
                                Case chgt=Case(choixCase,0,joueur.getReserve(choixTuile));
                                joueur.setCase(choixCase,chgt);
                                joueur.setReserve(choixTuile,"");
                                joueur.setde(choixDe,-1);
                                return true;
                            }
                            else{ //la case n'est pas adjacente à une autre du domaine
                                return false;
                            }
                        }
                        else{ //pas le bon numero de dé
                            return false;
                        }
                    }
                    else{ //pas la bonne couleur
                        return false;
                    }
                }

                else{
                    return false;
                }

            }



        }
    }

    //--------------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------------
    //les actions de tuiles

    void Simulateur::actionBateau(PlateauJoueur &joueur,PlateauCentral &marche,int choixZone){
                for(int l=0;l<6;l++){
                    if(marche.getTuileMarche(choixZone,l)==""){ //s'il n'y a pas de marchandise à cette place

                    }
                    else{ //s'il y a une marchandise

                        string march=marche.getTuileMarche(choixZone,l); //on recupere cette marchandise

                        //on veut savoir c'est qu'elle marchandise
                        char numMarch= march.at(1);
                        int testPlaceMarch=0;
                        int idVide;
                        switch(numMarch){
                            case '1': //si c'est une marchandise de type 1
                                for(int i=0;i<3;i++){//on regarde si on a deja une marchandise de ce type en reserve
                                    if(joueur.getMarch(i)==1){
                                        joueur.setMarch(i,1,joueur.getNbMarch(i)+1);
                                        marche.setTuile(choixZone,l,"");
                                        //return true;
                                    }
                                    else if(joueur.getMarch(i)==0){
                                        idVide=i;
                                    }
                                    else{
                                        testPlaceMarch=testPlaceMarch+1;
                                    }
                                }
                                if(testPlaceMarch==3){ //on ne peut pas stocké la nouvelle marchandise
                                    //return false;
                                }
                                else{
                                    joueur.setMarch(idVide,0,1);
                                    joueur.setMarch(idVide,1,1);
                                    marche.setTuile(choixZone,l,"");
                                    //return true;
                                }
                                break;
                            case '2':
                                for(int i=0;i<3;i++){//on regarde si on a deja une marchandise de ce type en reserve
                                    if(joueur.getMarch(i)==2){
                                        joueur.setMarch(i,1,joueur.getNbMarch(i)+1);
                                        marche.setTuile(choixZone,l,"");
                                        //return true;
                                    }
                                    else if(joueur.getMarch(i)==0){
                                        idVide=i;
                                    }
                                    else{
                                        testPlaceMarch=testPlaceMarch+1;
                                    }
                                }
                                if(testPlaceMarch==3){ //on ne peut pas stocké la nouvelle marchandise
                                    //return false;
                                }
                                else{
                                    joueur.setMarch(idVide,0,2);
                                    joueur.setMarch(idVide,1,1);
                                    marche.setTuile(choixZone,l,"");
                                    //return true;
                                }
                                break;
                            case '3':
                                for(int i=0;i<3;i++){//on regarde si on a deja une marchandise de ce type en reserve
                                    if(joueur.getMarch(i)==3){
                                        joueur.setMarch(i,1,joueur.getNbMarch(i)+1);
                                        marche.setTuile(choixZone,l,"");
                                        //return true;
                                    }
                                    else if(joueur.getMarch(i)==0){
                                        idVide=i;
                                    }
                                    else{
                                        testPlaceMarch=testPlaceMarch+1;
                                    }
                                }
                                if(testPlaceMarch==3){ //on ne peut pas stocké la nouvelle marchandise
                                    //return false;
                                }
                                else{
                                    joueur.setMarch(idVide,0,3);
                                    joueur.setMarch(idVide,1,1);
                                    marche.setTuile(choixZone,l,"");
                                    //return true;
                                }
                                break;
                            case '4':
                                for(int i=0;i<3;i++){//on regarde si on a deja une marchandise de ce type en reserve
                                    if(joueur.getMarch(i)==4){
                                        joueur.setMarch(i,1,joueur.getNbMarch(i)+1);
                                        marche.setTuile(choixZone,l,"");
                                        //return true;
                                    }
                                    else if(joueur.getMarch(i)==0){
                                        idVide=i;
                                    }
                                    else{
                                        testPlaceMarch=testPlaceMarch+1;
                                    }
                                }
                                if(testPlaceMarch==3){ //on ne peut pas stocké la nouvelle marchandise
                                    //return false;
                                }
                                else{
                                    joueur.setMarch(idVide,0,4);
                                    joueur.setMarch(idVide,1,1);
                                    marche.setTuile(choixZone,l,"");
                                    //return true;
                                }
                                break;
                            case '5':
                                for(int i=0;i<3;i++){//on regarde si on a deja une marchandise de ce type en reserve
                                    if(joueur.getMarch(i)==5){
                                        joueur.setMarch(i,1,joueur.getNbMarch(i)+1);
                                        marche.setTuile(choixZone,l,"");
                                        //return true;
                                    }
                                    else if(joueur.getMarch(i)==0){
                                        idVide=i;
                                    }
                                    else{
                                        testPlaceMarch=testPlaceMarch+1;
                                    }
                                }
                                if(testPlaceMarch==3){ //on ne peut pas stocké la nouvelle marchandise
                                    //return false;
                                }
                                else{
                                    joueur.setMarch(idVide,0,5);
                                    joueur.setMarch(idVide,1,1);
                                    marche.setTuile(choixZone,l,"");
                                    //return true;
                                }
                                break;
                            case '6':
                                for(int i=0;i<3;i++){//on regarde si on a deja une marchandise de ce type en reserve
                                    if(joueur.getMarch(i)==6){
                                        joueur.setMarch(i,1,joueur.getNbMarch(i)+1);
                                        marche.setTuile(choixZone,l,"");
                                        //return true;
                                    }
                                    else if(joueur.getMarch(i)==0){
                                        idVide=i;
                                    }
                                    else{
                                        testPlaceMarch=testPlaceMarch+1;
                                    }
                                }
                                if(testPlaceMarch==3){ //on ne peut pas stocké la nouvelle marchandise
                                    //return false;
                                }
                                else{
                                    joueur.setMarch(idVide,0,6);
                                    joueur.setMarch(idVide,1,1);
                                    marche.setTuile(choixZone,l,"");
                                    //return true;
                                }
                                break;
                            default :
                                //return false;
                                break;
                            }
                        }
                    }
        //à rajouter plus tard, le pion du joueur pour le tour doit avancer

    }



    void Simulateur::actionPension(PlateauJoueur &joueur){
        joueur.setOuvrier(joueur.getOuvrier()+4);
    }

    void Simulateur::actionBanque(PlateauJoueur &joueur){
        joueur.setPepite(joueur.getPepite()+2);
    }

    void Simulateur::actionEntrepot(PlateauJoueur &joueur, int choixVente){
        if(choixVente<3){
            int numMarch =joueur.getMarch(choixVente);
            if(numMarch!=0){ //s'il y a une marchandise
                joueur.setVendu(numMarch-1,joueur.getNbMarchVendu(numMarch-1)+joueur.getNbMarch(choixVente)); //on ajoute le nbr de march vendu dans le tableau du joueur
                joueur.setMarch(choixVente,0,0);//on enleve la marchandise du tableau
                joueur.setMarch(choixVente,1,0);//on met le nbr de marchandise à 0
                joueur.setPepite(joueur.getPepite()+1);
                //on réarrange le tableau
                for(int j=choixVente;j<3;j++){
                    if(j!=2){
                        joueur.setMarch(j,0,joueur.getMarch(j+1));
                        joueur.setMarch(j,1,joueur.getNbMarch(j+1));
                    }
                    else{
                        joueur.setMarch(j,0,0);
                        joueur.setMarch(j,1,0);
                    }

                }
            }

        }
    }

    void Simulateur::actionMine(PlateauJoueur &joueur){
        int nbrMine=0;
        for(int i=0;i<37;i++){
            if( (joueur.getCase(i).getType().compare("tm")==0) || (joueur.getCase(i).getType().compare("tmb")==0)){
                nbrMine=nbrMine+1;
            }
        }
        joueur.setPepite(joueur.getPepite()+nbrMine);
    }

