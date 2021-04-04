#include "AffichageTest.h"

    using namespace std;

    AffichageTest::AffichageTest()
    {
    }


    void AffichageTest::AffichageMarch(Marchandise march)
    {
        cout<<"Marchandise couleur:"<<march.getCouleur()<<" id:"<<march.getId()<<endl;

    }
    void AffichageTest::AffichageDe(De de)

    {
        int resultatDe = de.getResultat();
        cout<<"resultat:"<<resultatDe<<endl;
        cout<<endl;
    }

    void AffichageTest::AffichagePileMarch(stack<Marchandise> Stack)
    {

        Marchandise march = Stack.top();
        cout << "La pile contient " << Stack.size() << " marchandises de couleur : " << march.getCouleur()<<" et d'id_site :"<<march.getIdSite()<<endl;
        cout<<endl;
    }


    void AffichageTest::AffichagePileBatiment(stack<Batiment> Stack)
    {

        Batiment bat = Stack.top();
        cout << "La pile contient " << Stack.size() << " Batiment de type : " << bat.getType()<<" et d'id_site :"<<bat.getIdSite()<<endl;
        cout<<endl;
    }

    void AffichageTest::AffichagePileAnimal(stack<Animal> Stack)
    {

        Animal animal = Stack.top();
        cout << "La pile contient " << Stack.size() << " Animal de type : " << animal.getType()<<" et d'id :"<<animal.getId()<<endl;
        cout<<endl;
    }


    void AffichageTest::AffichagePileChateau(stack<Chateau> Stack)
    {

        Chateau castle = Stack.top();
        cout << "La pile contient " << Stack.size() << " chateaux de couleur : " << castle.getCouleur()<<" d'id_site:"<<castle.getIdSite()<<endl;
        cout<<endl;
    }

    void AffichageTest::AffichagePileBateau(stack<Bateau> Stack)
    {

        Bateau boat = Stack.top();
        cout << "La pile contient " << Stack.size() << " bateaux de couleur : " << boat.getCouleur()<<" d'id_site:"<<boat.getIdSite()<<endl;
        cout<<endl;
    }

    void AffichageTest::AffichagePileMine(stack<Mine> Stack)
    {

        Mine mine = Stack.top();
        cout << "La pile contient " << Stack.size() << " mines de couleur : " << mine.getCouleur()<<" d'id_site:"<<mine.getIdSite()<<endl;
        cout<<endl;
    }



//-------------------------------------------------------------------------------------------------------------------------




