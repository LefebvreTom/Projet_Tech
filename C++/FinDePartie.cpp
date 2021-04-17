#include "FinDePartie.h"

using namespace std;


    FinDePartie::FinDePartie(){}

    void FinDePartie::Fin(){
        char quit;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"Voulez vous quitter ? O/N : "<<endl;
        cin>>quit;

        if(quit=='O'||quit=='o'){
            Initialisation init = Initialisation(0);

            //on clear le vector du mache noir en desalouant les pointeurs.
            init.ClearMarcheNoir();
            exit(0);
        }
        else{
            Fin();
        }

    }
