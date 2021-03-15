#ifndef MARCHANDISE_H
#define MARCHANDISE_H


class Marchandise
{
    public:
        Marchandise();
        virtual ~Marchandise();

        int GetvaleurD() { return valeurD; }
        void SetvaleurD(int val) { valeurD = val; }

    protected:

    private:
        int valeurD;
};

#endif // MARCHANDISE_H
