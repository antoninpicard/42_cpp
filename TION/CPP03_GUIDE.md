# CPP03 - GUIDE DE CORRECTION

## 🎯 THÈME DU MODULE
**Héritage (Inheritance)**

---

## 📚 CONCEPTS CLÉS À EXPLIQUER

### 1. Héritage
- Une classe **dérivée** hérite d'une classe **de base**
- Syntaxe : `class Derived : public Base`
- La classe dérivée a accès aux membres `public` et `protected` de la base

### 2. Chaînage Construction/Destruction
- **Construction :** Base → Dérivée
- **Destruction :** Dérivée → Base (ordre inverse)

### 3. Attributs protected
- Accessibles dans la classe et ses classes dérivées
- Pas accessibles de l'extérieur

---

## 📝 EXERCICE PAR EXERCICE

### EX00: Aaaaand... OPEN!

**Ce qu'il faut dire:**
> "ClapTrap est une classe de base qui représente un robot avec des points de vie, d'énergie et de dégâts. Il peut attaquer, prendre des dégâts et se réparer. Chaque action coûte de l'énergie."

**Points techniques:**
- **Attributs privés :**
  - `_name` : nom du ClapTrap
  - `_hitPoints` : 10 (points de vie)
  - `_energyPoints` : 10 (énergie)
  - `_attackDamage` : 0 (dégâts)

- **Fonctions :**
  - `attack()` : coûte 1 énergie, affiche un message
  - `takeDamage()` : réduit les HP
  - `beRepaired()` : coûte 1 énergie, augmente les HP

**Code clé:**
```cpp
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0)
        return;  // Ne peut pas attaquer
    
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
```

**Si on te demande "Pourquoi vérifier HP et énergie ?"**
> "Le sujet dit qu'on ne peut rien faire si HP=0 ou énergie=0. C'est logique : mort ou épuisé."

---

### EX01: Serena, my love!

**Ce qu'il faut dire:**
> "ScavTrap hérite de ClapTrap mais avec des valeurs différentes et une fonction spéciale `guardGate()`. On voit le chaînage construction/destruction."

**Points techniques:**
- **Héritage :** `class ScavTrap : public ClapTrap`
- **Attributs changés (dans le constructeur) :**
  - `_hitPoints` : 100
  - `_energyPoints` : 50
  - `_attackDamage` : 20
- **Fonction spéciale :** `guardGate()` - "Gate keeper mode"
- **Attributs protected dans ClapTrap** pour que ScavTrap y accède

**Code clé:**
```cpp
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}
```

**Chaînage visible :**
```
Construction:
1. ClapTrap constructor called
2. ScavTrap constructor called

Destruction:
1. ScavTrap destructor called
2. ClapTrap destructor called
```

**Si on te demande "Pourquoi cet ordre ?"**
> "On construit la base avant la dérivée (besoin des attributs de base). On détruit dans l'ordre inverse (la dérivée peut utiliser la base dans son destructeur)."

**Si on te demande "Pourquoi protected ?"**
> "Pour que les classes dérivées (ScavTrap) puissent accéder aux attributs. Private serait trop restrictif."

---

### EX02: Repetitive work

**Ce qu'il faut dire:**
> "FragTrap est comme ScavTrap : hérite de ClapTrap avec des valeurs différentes et sa propre fonction spéciale `highFivesGuys()`."

**Points techniques:**
- **Héritage :** `class FragTrap : public ClapTrap`
- **Attributs changés :**
  - `_hitPoints` : 100
  - `_energyPoints` : 100
  - `_attackDamage` : 30
- **Fonction spéciale :** `highFivesGuys()` - demande un high five

**Code clé:**
```cpp
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name 
              << " requests a positive high five! ✋" << std::endl;
}
```

**Comparaison des 3 classes :**

| Classe | HP | Energy | Damage | Spécial |
|--------|-----|--------|--------|---------|
| ClapTrap | 10 | 10 | 0 | - |
| ScavTrap | 100 | 50 | 20 | guardGate() |
| FragTrap | 100 | 100 | 30 | highFivesGuys() |

**Si on te demande "Pourquoi pas de virtual ?"**
> "Pas besoin ici. On n'utilise pas de polymorphisme (pas de pointeurs vers la classe de base). C'est pour le prochain module."

---

## 💡 QUESTIONS FRÉQUENTES EN CORRECTION

### "C'est quoi l'héritage ?"
> "Une classe dérivée récupère les attributs et méthodes d'une classe de base. Évite la duplication de code."

### "Différence public, protected, private ?"
- **public :** accessible partout
- **protected :** accessible dans la classe et ses dérivées
- **private :** accessible uniquement dans la classe

### "Pourquoi appeler le constructeur de base ?"
> "Pour initialiser les attributs de la classe de base. Syntaxe : `ScavTrap::ScavTrap() : ClapTrap() { ... }`"

### "Ordre construction/destruction ?"
> "Construction : Base → Dérivée. Destruction : Dérivée → Base (inverse)."

### "Pourquoi des messages différents ?"
> "Le sujet le demande. Ça montre que chaque classe a sa propre identité même si elles héritent."

---

## 🎯 EXEMPLE CONCRET

**Création d'un ScavTrap :**
```cpp
ScavTrap scav("ST-01");
// Affiche:
// ClapTrap ST-01 constructor called
// ScavTrap ST-01 constructor called
```

**Destruction :**
```cpp
// Fin de scope
// Affiche:
// ScavTrap ST-01 destructor called
// ClapTrap ST-01 destructor called
```

**Utilisation :**
```cpp
scav.attack("Enemy");        // Utilise la version ScavTrap (20 dégâts)
scav.guardGate();            // Fonction spéciale ScavTrap
scav.takeDamage(30);         // Héritée de ClapTrap
```

---

## ✅ CHECKLIST AVANT CORRECTION

- [ ] Je sais expliquer l'héritage
- [ ] Je sais expliquer public/protected/private
- [ ] Je sais expliquer le chaînage construction/destruction
- [ ] Je connais les valeurs de chaque classe (HP, Energy, Damage)
- [ ] Je sais pourquoi les attributs sont protected

---

## 🎯 CONSEIL FINAL

**Montre le chaînage en live :**
- "Regarde, quand je crée un ScavTrap, ClapTrap se construit d'abord..."
- "Et à la destruction, c'est l'inverse..."

**L'héritage c'est simple : une classe enfant hérite de papa/maman !**

**Bon courage ! 🚀**
