# CPP04 - GUIDE RAPIDE

## 🎯 THÈME
Polymorphisme, classes abstraites, interfaces

---

## EX00: Polymorphisme

**L'essentiel:**
- `virtual` pour polymorphisme
- Destructeur virtuel **OBLIGATOIRE**

**Avec virtual:**
```cpp
const Animal* dog = new Dog();
dog->makeSound();  // Appelle Dog::makeSound()
delete dog;  // Appelle ~Dog() puis ~Animal()
```

**Sans virtual (WrongAnimal):**
```cpp
const WrongAnimal* cat = new WrongCat();
cat->makeSound();  // Appelle WrongAnimal (mauvais!)
```

---

## EX01: Brain (Deep Copy)

**L'essentiel:**
- Brain = tableau 100 strings
- Dog/Cat ont `Brain* _brain`
- **Deep copy obligatoire**

**Deep copy:**
```cpp
Dog::Dog(const Dog& other) {
    _brain = new Brain(*other._brain);  // Nouveau Brain
}

Dog& operator=(const Dog& other) {
    delete _brain;  // Libère ancien
    _brain = new Brain(*other._brain);  // Nouveau
}
```

**Si on demande:**
> "Deep copy = copier le contenu, pas le pointeur. Sinon double free."

---

## EX02: Classe abstraite

**L'essentiel:**
- Fonction pure virtuelle: `virtual void func() = 0;`
- **Impossible d'instancier** la classe abstraite

```cpp
class AAnimal {
    virtual void makeSound() const = 0;  // Pure virtuelle
};

// AAnimal* a = new AAnimal();  // ERREUR
AAnimal* dog = new Dog();  // OK
```

---

## EX03: Interfaces & Materia

**Interfaces:**
- ICharacter
- IMateriaSource

**Classes concrètes:**
- Ice: "* shoots an ice bolt at <name> *"
- Cure: "* heals <name>'s wounds *"

**Character:**
- Inventaire 4 slots
- `equip()` → ajoute dans slot vide
- `unequip()` → **NE DELETE PAS**
- `use()` → utilise la Materia

**MateriaSource:**
- 4 templates max
- `learnMateria()` → clone et stocke
- `createMateria()` → clone et retourne

**Points critiques:**
```cpp
// unequip NE DELETE PAS (sujet le dit)
void unequip(int idx) {
    _inventory[idx] = 0;  // Pas de delete
}

// Deep copy obligatoire
Character(const Character& other) {
    for (int i = 0; i < 4; i++)
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
}
```

---

## 💡 QUESTIONS RAPIDES

**Polymorphisme?**
> "Pointeur de base manipule objets dérivés. virtual appelle la bonne fonction."

**Pourquoi destructeur virtuel?**
> "Pour que delete appelle le destructeur dérivé. Sinon fuite."

**Deep copy?**
> "Copier le contenu pointé, pas le pointeur."

**Classe abstraite?**
> "Au moins une fonction pure virtuelle (= 0). Pas instantiable."

**Interface?**
> "Classe abstraite pure (que des fonctions = 0)."

**Pourquoi unequip ne delete pas?**
> "Le sujet le dit. L'utilisateur gère la mémoire après."
