#ifndef JOUEUR_H
#define JOUEUR_H


class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();

        Plateau Getplateau() { return plateau; }
        void Setplateau(Plateau val) { plateau = val; }
        De Getd1() { return d1; }
        void Setd1(De val) { d1 = val; }
        De Getd2() { return d2; }
        void Setd2(De val) { d2 = val; }
        int Getpepite() { return pepite; }
        void Setpepite(int val) { pepite = val; }
        int Getouvrier() { return ouvrier; }
        void Setouvrier(int val) { ouvrier = val; }
        int Getscore() { return score; }
        void Setscore(int val) { score = val; }

    protected:

    private:
        Plateau plateau;
        De d1;
        De d2;
        int pepite;
        int ouvrier;
        int score;
};

#endif // JOUEUR_H
