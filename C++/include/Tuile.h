#ifndef TUILE_H
#define TUILE_H


class Tuile
{
    public:
        Tuile();
        virtual ~Tuile();

        String Getnom() { return nom; }
        void Setnom(String val) { nom = val; }
        int Getcouleur() { return couleur; }
        void Setcouleur(int val) { couleur = val; }
        int Getforme() { return forme; }
        void Setforme(int val) { forme = val; }

    protected:

    private:
        String nom;
        int couleur;
        int forme;
};

#endif // TUILE_H
