#include <iostream>
#include <cstdlib>

#include "projetFonction.h"

using namespace std;

int main()
{
    Liste *listeEtudiant = NULL;
    Etudiant el;
    char choix;
    int pos;

    presentation();
    cout << endl;

    do
    {
        menu();

        cout << "Votre choix >>> ";
        cin >> choix;
        cin.ignore();

        if (choix != '1' && listeEtudiant == NULL)
        {
            cout << "Vou avez aucune Liste Disponible, Initialiser une d'abord !!!\n"
                 << endl;
        }
        else
        {
            if (choix == '1' && listeEtudiant != NULL)
            {
                cout << "La liste contient des element, choisir Option 2, 3, 4 ou 5\n"
                     << endl;
            }
            else
            {

                switch (choix)
                {
                case '1':
                    listeEtudiant = new Liste();

                    if (listeEtudiant == NULL)
                        exit(1);
                    initListe(listeEtudiant);

                    if (inserePremier(listeEtudiant, newStudent()) != -1)
                        cout << "Succes ...\n"
                             << endl;
                    else
                        cout << "Echec Reesayer ...\n"
                             << endl;
                    break;

                case '2':

                    if (insereDebut(listeEtudiant, newStudent()) != -1)
                        cout << "Succes ...\n"
                             << endl;
                    else
                        cout << "Echec Reesayer ...\n"
                             << endl;
                    break;

                case '3':

                    if (insereFin(listeEtudiant, newStudent()) != -1)
                        cout << "Succes ...\n"
                             << endl;
                    else
                        cout << "Echec Reesayer ...\n"
                             << endl;
                    break;

                case '4':

                    cout << "Entrer la Position de l'Element : ";
                    cin >> pos;
                    cin.ignore();

                    if (insereAvant(listeEtudiant, newStudent(), pos) != -1)
                        cout << "Succes ...\n"
                             << endl;
                    else
                        cout << "Echec Reesayer ...\n"
                             << endl;
                    break;

                case '5':
                    cout << "Entrer la Position de l'Element : ";
                    cin >> pos;
                    cin.ignore();

                    if (insereApres(listeEtudiant, newStudent(), pos) != -1)
                        cout << "Succes ...\n"
                             << endl;
                    else
                        cout << "Echec Reesayer ...\n"
                             << endl;
                    break;

                case '6':

                    cout << "Entrer la Position de l'Element : ";
                    cin >> pos;
                    cin.ignore();

                    if (suppElement(listeEtudiant, pos) != -1)
                        cout << "Succes ...\n"
                             << endl;
                    else
                        cout << "Echec Reesayer ...\n"
                             << endl;
                    break;

                case '7':
                    afficherListe(listeEtudiant);
                    break;

                case '8':
                case '0':
                    detruire(listeEtudiant);
                    break;

                default:
                    cout << "Option Invalide !!!" << endl;
                    break;
                }
            }
        }
    } while (choix != '0' || choix != '8');

    return 0;
}
