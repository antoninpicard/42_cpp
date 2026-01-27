# CPP03 - GUIDE RAPIDE

## 🎯 THÈME
Héritage

---

## EX00: ClapTrap

**Valeurs initiales:**
- HP: 10
- Energy: 10
- Damage: 0

**Fonctions:**
- `attack()` → coûte 1 énergie
- `takeDamage()` → réduit HP
- `beRepaired()` → coûte 1 énergie, augmente HP

---

## EX01: ScavTrap

**Héritage:** `class ScavTrap : public ClapTrap`

**Valeurs:**
- HP: 100
- Energy: 50
- Damage: 20

**Spécial:** `guardGate()` → "Gate keeper mode"

**Attributs protected** dans ClapTrap pour accès dérivées

---

## EX02: FragTrap

**Valeurs:**
- HP: 100
- Energy: 100
- Damage: 30

**Spécial:** `highFivesGuys()` → demande high five

---

## 📊 Tableau récap

| Classe | HP | Energy | Damage |
|--------|-----|--------|--------|
| ClapTrap | 10 | 10 | 0 |
| ScavTrap | 100 | 50 | 20 |
| FragTrap | 100 | 100 | 30 |

---

## Chaînage construction/destruction

**Construction:** Base → Dérivée
```
ClapTrap constructor
ScavTrap constructor
```

**Destruction:** Dérivée → Base (inverse)
```
ScavTrap destructor
ClapTrap destructor
```

---

## 💡 QUESTIONS RAPIDES

**Héritage?**
> "Classe dérivée récupère attributs/méthodes de la base."

**Pourquoi protected?**
> "Pour que les dérivées accèdent aux attributs."

**Ordre construction/destruction?**
> "Construction: Base→Dérivée. Destruction: inverse."
