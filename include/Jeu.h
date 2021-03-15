#ifndef JEU_H
#define JEU_H


class Jeu
{
    public:
        Jeu();
        virtual ~Jeu();

        Joueur Getj1() { return j1; }
        void Setj1(Joueur val) { j1 = val; }
        Joueur Getj2() { return j2; }
        void Setj2(Joueur val) { j2 = val; }
        Joueur Getj3() { return j3; }
        void Setj3(Joueur val) { j3 = val; }
        Joueur Getj4() { return j4; }
        void Setj4(Joueur val) { j4 = val; }
        Plateau Getmarche() { return marche; }
        void Setmarche(Plateau val) { marche = val; }

    protected:

    private:
        Joueur j1;
        Joueur j2;
        Joueur j3;
        Joueur j4;
        Plateau marche;
};

#endif // JEU_H
