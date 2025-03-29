#include <iostream>
using namespace std;

class Ensemble
{
    int taille;
    int* tab;
    int poslibre;
public:
    Ensemble(int p)
    {
        tab=new int [p];
        taille=p;
        poslibre=0;

    }
    bool isEmpty()
    {
        return  poslibre == 0;
    }
    void add(int element)
    {
        if ( poslibre<taille)
        {
            tab[poslibre] = element;
            poslibre++;
        }
        else
        {
            cout << "Ensemble plein !" << endl;
        }
    }
    void Remove(int element)
    {
        for (int i = 0; i < poslibre; i++)
        {
            if (tab[i] == element)
            {
                for (int j = i; j < poslibre - 1; j++)
                {
                    tab[j] = tab[j + 1];
                }
                poslibre--;
                return;
            }
        }
    }
    Ensemble Copy()
    {
        Ensemble newEnsemble(taille);
        for (int i = 0; i < poslibre; i++)
        {
            newEnsemble.add(tab[i]);
        }
        return newEnsemble;
    }

    bool isMember(int element)
    {
        for (int i = 0; i < poslibre; i++)
        {
            if (tab[i] == element)
                return true;
        }
        return false;
    }

    bool isEqual(Ensemble &e)
    {
        if (poslibre != e.poslibre)
            return false;
        for (int i = 0; i < poslibre; i++)
        {
            if (!e.isMember(tab[i]))
                return false;
        }
        return true;
    }

    void print()
    {
        cout << "Ensemble : { ";
        for (int i = 0; i < poslibre; i++)
        {
            cout << tab[i] << " ";
        }
        cout << "}" << endl;
    }
};

int main()
{
    Ensemble e1(5);

    if (e1.isEmpty())
    {
        cout << "L'ensemble est vide." << endl;
    }
    else
    {
        cout << "L'ensemble n'est pas vide." << endl;
    }

    e1.add(1);
    e1.add(2);
    e1.add(3);
    e1.add(4);
    e1.print();

    e1.Remove(2);
    e1.print();

    Ensemble e2 = e1.Copy();
    e2.print();

    if (e1.isMember(3))
    {
        cout << "L'element 3 est dans l'ensemble.\n";
    }

    else
    {
        cout <<"L'element 3 n'est pas dans l'ensemble.\n";
    }

    if (e1.isEqual(e2))
    {
        cout <<  "Les ensembles e1 et e2 sont egaux.\n";
    }
    else
    {
        cout << "Les ensembles e1 et e2 sont differents.\n";
    }
    return 0;
}
