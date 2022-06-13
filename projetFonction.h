#ifndef _FONC_PRO_
#define _FONC_PRO_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

// Model Etudiant
typedef struct Etudiant
{
    string code;
    string nomComplet;
    string faculte;
} Etudiant;

// Element de la Liste
typedef struct ListeEl
{
    Etudiant donne;
    ListeEl *suivant;
    ListeEl *precedent;
} ListeEl;

// Definition de la List
typedef struct Liste
{
    ListeEl *premier;
    ListeEl *dernier;
    int taille;
} Liste;

// FONCTION INTERFACE
void menu();
void presentation();
Etudiant newStudent();

// FONCTION LISTE
void initListe(Liste *liste);
bool estVide(Liste *liste);
int getTaille(Liste *liste);

void afficherListe(Liste *liste);

int inserePremier(Liste *liste, const Etudiant &etudiant);
int insereDebut(Liste *liste, const Etudiant &etudiant);
int insereFin(Liste *liste, const Etudiant &etudiant);

int insereApres(Liste *liste, const Etudiant &etudiant, int pos);
int insereAvant(Liste *liste, const Etudiant &etudiant, int pos);

int suppDebut(Liste *liste);
int suppFin(Liste *liste);
int suppElement(Liste *liste, int pos);

void detruire(Liste *liste);

#endif
