# CPP04 - GUIDE DE CORRECTION

## 🎯 THÈME DU MODULE
**Polymorphisme de sous-type, classes abstraites et interfaces**

---

## 📚 CONCEPTS CLÉS À EXPLIQUER

### 1. Polymorphisme
- Utiliser un pointeur de classe de base pour manipuler des objets dérivés
- Nécessite des fonctions **virtuelles** (`virtual`)
- Permet d'appeler la bonne fonction selon le type réel de l'objet

### 2. Classe Abstraite
- Contient au moins une fonction **pure virtuelle** : `virtual void func() = 0;`
- **Ne peut pas être instantiée** directement
- Sert de base pour d'autres classes

### 3. Interface
- Classe abstraite pure (que des fonctions virtuelles pures)
- Définit un contrat que les classes dérivées doivent respecter

### 4. Deep Copy
- Copier le contenu pointé, pas juste le pointeur
- Évite que deux objets partagent la même mémoire

---

## 📝 EXERCICE PAR EXERCICE

### EX00: Polymorphism

**Ce qu'il faut dire:**
> "On crée une hiérarchie Animal → Dog/Cat avec polymorphisme. Le mot-clé `virtual` permet d'appeler la bonne fonction `makeSound()` selon le type réel (Dog ou Cat), même via un pointeur Animal."

**Points techniques:**
- **Animal :** classe de base avec `makeSound()` virtuel
- **Dog/Cat :** classes dérivées qui redéfinissent `makeSound()`
- **WrongAnimal/WrongCat :** sans `virtual` pour montrer la différence

**Code clé:**
```cpp
// Animal.hpp
class Animal {
protected:
    std::string type;
public:
    virtual ~Animal();  // Destructeur virtuel OBLIGATOIRE
    virtual void makeSound() const;  // Fonction virtuelle
};

// Dog.cpp
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

// main.cpp
const Animal* dog = new Dog();
dog->makeSound();  // Appelle Dog::makeSound() grâce au virtual
delete dog;  // Appelle ~Dog() puis ~Animal() grâce au virtual
```

**Avec WrongAnimal (sans virtual) :**
```cpp
const WrongAnimal* cat = new WrongCat();
cat->makeSound();  // Appelle WrongAnimal::makeSound() (pas le bon!)
```

**Si on te demande "Pourquoi virtual ?"**
> "Sans `virtual`, le compilateur choisit la fonction selon le type du pointeur (Animal), pas le type réel (Dog). Avec `virtual`, il regarde le type réel à l'exécution."

**Si on te demande "Pourquoi destructeur virtuel ?"**
> "Pour que `delete` appelle le bon destructeur. Sans `virtual`, seul ~Animal() serait appelé, causant des fuites mémoire."

---

### EX01: I don't want to set the world on fire

**Ce qu'il faut dire:**
> "On ajoute une classe Brain avec 100 idées. Dog et Cat ont chacun leur propre Brain alloué dynamiquement. Important : il faut faire une **deep copy** pour que chaque objet ait son propre Brain."

**Points techniques:**
- **Brain :** tableau de 100 `std::string ideas`
- **Dog/Cat :** attribut `Brain* _brain`
- **Construction :** `_brain = new Brain()`
- **Destruction :** `delete _brain`
- **Deep copy obligatoire**

**Code clé:**
```cpp
// Dog.hpp
class Dog : public Animal {
private:
    Brain* _brain;
public:
    Dog();
    Dog(const Dog& other);  // Deep copy
    Dog& operator=(const Dog& other);  // Deep copy
    ~Dog();
};

// Dog.cpp - Constructeur
Dog::Dog() : Animal() {
    type = "Dog";
    _brain = new Brain();  // Allocation
}

// Dog.cpp - Copy constructor (DEEP COPY)
Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);  // Nouvelle Brain, copie du contenu
}

// Dog.cpp - Assignment operator (DEEP COPY)
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;  // Libère l'ancien
        _brain = new Brain(*other._brain);  // Nouveau Brain
    }
    return *this;
}

// Dog.cpp - Destructeur
Dog::~Dog() {
    delete _brain;  // Libération
}
```

**Test deep copy :**
```cpp
Dog original;
Dog copy = original;  // Deep copy
// original et copy ont des Brain différents
// Modifier copy ne modifie pas original
```

**Si on te demande "C'est quoi deep copy ?"**
> "Copier le contenu pointé, pas juste le pointeur. Sinon les deux objets partagent la même mémoire → problème à la destruction (double free)."

**Si on te demande "Pourquoi delete avant new dans operator= ?"**
> "Pour libérer l'ancien Brain avant d'en allouer un nouveau. Sinon fuite mémoire."

---

### EX02: Abstract class

**Ce qu'il faut dire:**
> "Animal devient une classe abstraite : on ne peut plus faire `new Animal()`. On utilise une fonction pure virtuelle pour forcer les classes dérivées à l'implémenter."

**Points techniques:**
- **AAnimal** (ou Animal) : classe abstraite
- `virtual void makeSound() const = 0;` : fonction pure virtuelle
- **Impossible d'instancier** AAnimal directement
- Dog et Cat **doivent** implémenter `makeSound()`

**Code clé:**
```cpp
// AAnimal.hpp
class AAnimal {
protected:
    std::string type;
public:
    virtual ~AAnimal();
    virtual void makeSound() const = 0;  // Pure virtuelle
};

// main.cpp
// AAnimal* animal = new AAnimal();  // ERREUR : classe abstraite
AAnimal* dog = new Dog();  // OK : Dog implémente makeSound()
```

**Si on te demande "Pourquoi classe abstraite ?"**
> "Un Animal générique n'a pas de son. Seuls Dog et Cat ont des sons spécifiques. Ça force à utiliser une classe dérivée concrète."

**Si on te demande "Différence virtuelle vs pure virtuelle ?"**
> "Virtuelle : peut avoir une implémentation par défaut. Pure virtuelle (= 0) : pas d'implémentation, classe abstraite."

---

### EX03: Interface & recap

**Ce qu'il faut dire:**
> "On implémente un système de Materia (sorts) avec des interfaces. ICharacter et IMateriaSource définissent des contrats. Character a un inventaire de 4 Materias."

**Points techniques:**

**1. AMateria (classe abstraite) :**
```cpp
class AMateria {
protected:
    std::string _type;
public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;  // Pure virtuelle
    virtual void use(ICharacter& target);
};
```

**2. Ice et Cure (classes concrètes) :**
```cpp
// Ice
AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
```

**3. ICharacter (interface) :**
```cpp
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

**4. Character (implémentation) :**
```cpp
class Character : public ICharacter {
private:
    std::string _name;
    AMateria* _inventory[4];  // 4 slots
public:
    void equip(AMateria* m);  // Ajoute dans premier slot vide
    void unequip(int idx);    // Retire mais NE DELETE PAS
    void use(int idx, ICharacter& target);  // Utilise la Materia
};
```

**5. MateriaSource (templates de Materias) :**
```cpp
class MateriaSource : public IMateriaSource {
private:
    AMateria* _templates[4];  // 4 templates max
public:
    void learnMateria(AMateria* m);  // Clone et stocke
    AMateria* createMateria(std::string const & type);  // Clone et retourne
};
```

**Points critiques :**
- `unequip()` **ne delete pas** la Materia (le sujet le dit)
- `learnMateria()` **clone** la Materia (ne stocke pas le pointeur direct)
- `createMateria()` **clone** et retourne une nouvelle Materia
- Deep copy obligatoire pour Character

**Si on te demande "Pourquoi unequip ne delete pas ?"**
> "Le sujet le dit explicitement. C'est à l'utilisateur de gérer la mémoire après unequip. On peut stocker l'adresse avant d'unequip."

**Si on te demande "Pourquoi clone() ?"**
> "Pour créer une copie indépendante. Chaque Character a ses propres Materias, chaque MateriaSource a ses propres templates."

**Si on te demande "C'est quoi une interface ?"**
> "Une classe abstraite pure (que des fonctions virtuelles pures). Définit un contrat sans implémentation."

---

## 💡 QUESTIONS FRÉQUENTES EN CORRECTION

### "C'est quoi le polymorphisme ?"
> "Utiliser un pointeur de classe de base pour manipuler des objets dérivés. La bonne fonction est appelée grâce à `virtual`."

### "Pourquoi destructeur virtuel ?"
> "Pour que `delete` sur un pointeur de base appelle le destructeur de la classe dérivée. Sinon fuite mémoire."

### "Différence classe abstraite vs interface ?"
> "Classe abstraite : au moins une fonction pure virtuelle. Interface : que des fonctions pures virtuelles (pas d'attributs, pas d'implémentation)."

### "C'est quoi deep copy ?"
> "Copier le contenu pointé, pas le pointeur. Chaque objet a sa propre mémoire."

### "Pourquoi virtual = 0 ?"
> "Fonction pure virtuelle. Pas d'implémentation, rend la classe abstraite."

---

## 🎯 EXEMPLE CONCRET EX03

```cpp
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());  // Clone et stocke le template
src->learnMateria(new Cure());

ICharacter* me = new Character("me");

AMateria* tmp = src->createMateria("ice");  // Clone du template
me->equip(tmp);  // Ajoute à l'inventaire

ICharacter* bob = new Character("bob");
me->use(0, *bob);  // "* shoots an ice bolt at bob *"

delete bob;
delete me;  // Deep copy : delete les Materias
delete src;  // Delete les templates
```

---

## ✅ CHECKLIST AVANT CORRECTION

- [ ] Je sais expliquer le polymorphisme
- [ ] Je sais pourquoi destructeur virtuel
- [ ] Je sais expliquer deep copy
- [ ] Je sais la différence classe abstraite / interface
- [ ] Je sais pourquoi unequip ne delete pas
- [ ] Je sais expliquer clone()

---

## 🎯 CONSEIL FINAL

**Le CPP04 est le plus complexe. Reste calme et explique avec des exemples :**
- "Regarde, sans virtual, ça appelle la mauvaise fonction..."
- "Avec deep copy, chaque objet a son propre Brain..."
- "Clone() crée une copie indépendante..."

**Montre le code, c'est plus clair que de longs discours !**

**Bon courage ! 🚀**
