#ifndef DE_H
#define DE_H


class De
{
    public:
        De();
        virtual ~De();

        int Getcouleur() { return couleur; }
        void Setcouleur(int val) { couleur = val; }
        int Getresultat() { return resultat; }
        void Setresultat(int val) { resultat = val; }
        int Getid() { return id; }
        void Setid(int val) { id = val; }

    protected:

    private:
        int couleur;
        int resultat;
        int id;
};

#endif // DE_H
