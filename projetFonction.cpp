#include "projetFonction.h"

// FONCTION iNTERFACE
void menu()
{
    cout << "1- Inserer premier Etudiant" << endl;
    cout << "2- Inserer au debut" << endl;
    cout << "3- Inserer a la fin" << endl;
    cout << "4- Inserer avant un autre" << endl;
    cout << "5- Inserer apres un autre" << endl;
    cout << "6- Supprimer" << endl;
    cout << "7- Afficher" << endl;
    cout << "8- Detruire & Quitter\n"
         << endl;
}

void presentation()
{
    cout << "Devoir Presenter par : \n"
         << endl;
    cout << "\tRolbert Aphaon" << endl;
    cout << "\tMakendy Alexis" << endl;
    cout << "\tBerthin Pierristal\n"
         << endl;

    cout << "Appuiyer pour continuer et Initialiser Une liste ...\t";
    cin.ignore();
}

Etudiant newStudent()
{
    Etudiant e;

    cout << "Entrer Code : ";
    getline(cin, e.code);

    cout << "Entrer Nom Complet : ";
    getline(cin, e.nomComplet);

    cout << "Entrer Faculte : ";
    getline(cin, e.faculte);

    return e;
}

void initListe(Liste *liste)
{
    liste->premier = NULL;
    liste->dernier = NULL;
    liste->taille = 0;

    cout << "Une Nouvelle Liste est Initialiser ... \n"
         << endl;
}

int getTaille(Liste *liste)
{
    return liste->taille;
}

bool estVide(Liste *liste)
{
    if (liste->taille == 0)
        return true;
    return false;
}

void afficherListe(Liste *liste)
{
    if (estVide(liste))
        cout << "La Liste est Vide" << endl;
    else
    {
        ListeEl *courant;
        courant = liste->premier;
        int nb = 1;

        cout << "\n++++++++++++++++++++++++++++++++++++++++++++\n"
             << endl;

        while (courant != NULL)
        {
            cout << nb << ". " << courant->donne.code << "\t" << courant->donne.faculte << "\t" << courant->donne.nomComplet << endl;
            courant = courant->suivant;
            nb++;
        }

        cout << "\nTaille : " << getTaille(liste) << endl;
        cout << "\n++++++++++++++++++++++++++++++++++++++++++++\n"
             << endl;
    }
}

int inserePremier(Liste *liste, const Etudiant &etudiant)
{
    ListeEl *el = new ListeEl();

    if (el == NULL)
        return -1;

    el->donne = etudiant;
    el->suivant = NULL;
    el->precedent = NULL;

    liste->premier = el;
    liste->dernier = el;
    liste->taille++;

    return 0;
}

int insereDebut(Liste *liste, const Etudiant &etudiant)
{
    ListeEl *el = new ListeEl();

    if (el == NULL)
        return -1;

    el->donne = etudiant;
    el->precedent = NULL;
    el->suivant = liste->premier;

    liste->premier->precedent = el;

    liste->premier = el;
    liste->taille++;

    return 0;
}

int insereFin(Liste *liste, const Etudiant &etudiant)
{
    ListeEl *el = new ListeEl();

    if (el == NULL)
        return -1;

    el->donne = etudiant;
    el->precedent = liste->dernier;
    el->suivant = NULL;

    liste->dernier->suivant = el;

    liste->dernier = el;
    liste->taille++;

    return 0;
}

int insereApres(Liste *liste, const Etudiant &etudiant, int pos)
{
    ListeEl *el = new ListeEl();
    ListeEl *courant = new ListeEl();

    if (el == NULL || courant == NULL)
        return -1;

    if (pos < 1)
        insereDebut(liste, etudiant);
    else if (pos >= getTaille(liste))
        insereFin(liste, etudiant);
    else
    {
        el->donne = etudiant;
        courant = liste->premier;

        for (int i = 1; i < pos; i++)
            courant = courant->suivant;

        el->precedent = courant;
        el->suivant = courant->suivant;

        courant->suivant->precedent = el;
        courant->suivant = el;

        liste->taille++;
    }

    return 0;
}

int insereAvant(Liste *liste, const Etudiant &etudiant, int pos)
{
    ListeEl *el = new ListeEl();
    ListeEl *courant = new ListeEl();

    if (el == NULL || courant == NULL)
        return -1;

    if (pos <= 1)
        insereDebut(liste, etudiant);
    else if (pos > getTaille(liste))
        insereFin(liste, etudiant);
    else
    {
        el->donne = etudiant;
        courant = liste->premier;

        for (int i = 1; i < pos; i++)
            courant = courant->suivant;

        el->precedent = courant->precedent;
        el->suivant = courant;

        courant->precedent->suivant = el;
        courant->precedent = el;

        liste->taille++;
    }

    return 0;
}

int suppDebut(Liste *liste)
{

    if (estVide(liste))
    {
        cout << "Cette liste est Vide ..." << endl;
        return 0;
    }

    if (liste->premier == liste->dernier)
    {
        delete (liste);
        return 0;
    }

    ListeEl *el = new ListeEl();
    if (el == NULL)
        return -1;

    el = liste->premier;

    liste->premier = el->suivant;
    liste->premier->precedent = NULL;
    el->precedent = NULL;
    el->suivant = NULL;

    delete (el);

    liste->taille--;

    return 0;
}

int suppFin(Liste *liste)
{

    if (estVide(liste))
    {
        cout << "Cette liste est Vide ..." << endl;
        return 0;
    }

    if (liste->premier == liste->dernier)
    {
        delete (liste);
        return 0;
    }

    ListeEl *el = new ListeEl();
    if (el == NULL)
        return -1;

    el = liste->dernier;

    liste->dernier = el->precedent;
    liste->dernier->suivant = NULL;
    el->precedent = NULL;
    el->suivant = NULL;

    delete (el);

    liste->taille--;

    return 0;
}

int suppElement(Liste *liste, int pos)
{

    if (pos < 1 || pos > getTaille(liste))
        cout << "Cette Element N'existe pas !!!" << endl;
    else
    {
        if (pos == 1)
        {
            suppDebut(liste);
        }
        else if (pos == getTaille(liste))
        {
            suppFin(liste);
        }
        else
        {
            ListeEl *el = new ListeEl();
            if (el == NULL)
                return -1;

            el = liste->premier;
            for (int i = 1; i < pos; i++)
                el = el->suivant;

            el->precedent->suivant = el->suivant;
            el->suivant->precedent = el->precedent;

            delete (el);

            liste->taille--;
        }
    }

    return 0;
}

void detruire(Liste *liste)
{
    while (getTaille(liste) > 1)
    {

        suppDebut(liste);
    }
    delete (liste);
    cout << "Liste detruite !!!" << endl;
}
