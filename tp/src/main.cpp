#include "../include/file.h"
#include "../include/polygone.h"
#include <cstddef>
#include <iostream>
#include <typeinfo>

/**
 * @brief Fonction de test utilisées pour les question 1 à 5
 */
void test();
/**
 * @brief Fonction pour l'exo 1
 */
void exo1();

int main(void)
{
    File<Polygone*> polyFile;
    polyFile.push_back(new Carre(2));
    polyFile.push_back(new Cercle(5, "rouge"));
    polyFile.push_back(new TriangleEquilateral(3));
    for (size_t i = 0; i < polyFile.getSize(); i++) {
        std::cout << polyFile[i]->afficherCaracteristiques() << "\n";
        std::cout << "Perimetre: " << polyFile[i]->perimetre() << "\n";
        // ! Expression with side effect (clang-tidy)
        if (typeid(*polyFile[i]) == typeid(Cercle)) {
            auto cercle = static_cast<Cercle*>(polyFile[i]);
            std::cout << "Couleur du cercle: " << cercle->getCouleur() << std::endl;
        }
        std::cout << "\n";
    }
}

void exo1()
{
    // Le polymorphisme ne fonctionne qu'avec des pointeurs
    Polygone* polyTab[3] = { new Carre(2), new Cercle(5, "rouge"), new TriangleEquilateral(3) };
    std::cout << "Polycount: " << Polygone::getPolyCount() << std::endl;
    for (size_t i = 0; i < Polygone::getPolyCount(); i++) {
        std::cout << polyTab[i]->afficherCaracteristiques() << std::endl;
        std::cout << "Perimetre: " << polyTab[i]->perimetre() << std::endl;
        if (i == 1) {
            auto cercle = static_cast<Cercle*>(polyTab[i]);
            std::cout << "Couleur du cercle: " << cercle->getCouleur() << std::endl;
        }
    }
    // Suppression de chaque Polygone dans le tableau
    while (Polygone::getPolyCount() > 0)
        delete polyTab[Polygone::getPolyCount() - 1];
    // ! Potential memory leak (clang-tidy)
}

void test()
{
    Polygone coolPoly(5);
    std::cout << coolPoly.afficherCaracteristiques() << std::endl;
    Rectangle rect(4, 8);
    std::cout << rect.afficherCaracteristiques() << std::endl;
    Carre car(2);
    std::cout << car.afficherCaracteristiques() << std::endl;
    TriangleEquilateral tri(5);
    std::cout << tri.afficherCaracteristiques() << std::endl;
    Cercle cer(2, "bleu");
    std::cout << cer.afficherCaracteristiques() << std::endl;
    std::cout << "Perimetre du cercle: " << cer.perimetre() << std::endl;
    std::cout << "On change le rayon de 5" << std::endl;
    cer.setRayon(5);
    std::cout << "Perimetre du cercle: " << cer.perimetre() << std::endl;
}