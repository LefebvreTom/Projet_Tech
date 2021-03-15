#ifndef PLATEAU_H
#define PLATEAU_H


class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();

        String Getnom() { return nom; }
        void Setnom(String val) { nom = val; }
        int Gettype() { return type; }
        void Settype(int val) { type = val; }
        int GetnumJoueur() { return numJoueur; }
        void SetnumJoueur(int val) { numJoueur = val; }

    protected:

    private:
        String nom;
        int type;
        int numJoueur;
};

#endif // PLATEAU_H
