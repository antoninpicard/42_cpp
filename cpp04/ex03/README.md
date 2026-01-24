# Exercise 03: Interface & Recap

## Description
Cet exercice implémente un système de Materia avec des interfaces (classes abstraites pures) en C++98.

## Architecture

### Classes Abstraites / Interfaces
- **AMateria** : Classe abstraite de base pour toutes les materias
- **ICharacter** : Interface pour les personnages
- **IMateriaSource** : Interface pour la source de materias

### Classes Concrètes
- **Ice** : Materia de type "ice" qui tire un boulon de glace
- **Cure** : Materia de type "cure" qui soigne les blessures
- **Character** : Implémente ICharacter avec un inventaire de 4 slots
- **MateriaSource** : Implémente IMateriaSource pour apprendre et créer des materias

## Fonctionnalités

### Character
- Inventaire de 4 slots maximum
- Équipe les materias dans le premier slot vide
- Peut déséquiper sans supprimer la materia (gestion manuelle de la mémoire)
- Deep copy lors de la copie

### MateriaSource
- Peut apprendre jusqu'à 4 materias (templates)
- Crée de nouvelles materias par clonage des templates
- Retourne NULL si le type est inconnu

## Compilation
```bash
make
```

## Exécution
```bash
./materia
```

## Tests
Le programme inclut :
1. Le test du sujet (affiche les deux lignes attendues)
2. Test d'inventaire plein
3. Test de unequip et gestion mémoire
4. Test d'opérations invalides
5. Test de type inconnu
6. Test de deep copy
7. Test de MateriaSource pleine

## Gestion Mémoire
- Aucune fuite mémoire (vérifié avec valgrind)
- Deep copy correcte pour Character et MateriaSource
- Ownership : learnMateria prend ownership de la materia passée
