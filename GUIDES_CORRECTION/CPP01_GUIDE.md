# CPP01 - GUIDE RAPIDE

## 🎯 THÈME
Mémoire, pointeurs, références

---

## EX00: BraiiiiiiinnnzzzZ

**L'essentiel:**
- `newZombie()` → heap (new) → doit delete
- `randomChump()` → stack → destruction auto

**Si on demande:**
> "Heap pour survivre après la fonction, stack pour usage temporaire."

---

## EX01: Moar brainz!

**L'essentiel:**
- `new Zombie[N]` → tableau en une fois
- `delete[]` pour libérer (pas delete)

---

## EX02: HI THIS IS BRAIN

**L'essentiel:**
- Pointeur et référence = même adresse
- Référence = alias, pointeur = peut être NULL

---

## EX03: Unnecessary violence

**L'essentiel:**
- **HumanA:** référence `Weapon&` → toujours armé
- **HumanB:** pointeur `Weapon*` → peut être NULL

**Si on demande:**
> "Référence = toujours valide. Pointeur = peut être NULL."

---

## EX04: Sed is for losers

**L'essentiel:**
- Remplace s1 par s2 dans fichier
- **INTERDIT:** `std::string::replace()`
- Utilise `find()` + `substr()` manuellement

---

## EX05: Harl 2.0

**L'essentiel:**
- **INTERDIT:** if/else en cascade
- Utilise tableau de pointeurs vers fonctions membres

**Code clé:**
```cpp
void (Harl::*functions[])(void) = {
    &Harl::debug, &Harl::info, 
    &Harl::warning, &Harl::error
};
(this->*functions[i])();
```

---

## 💡 QUESTIONS RAPIDES

**new vs malloc?**
> "new appelle le constructeur, malloc non."

**Pointeur vs référence?**
> "Pointeur peut être NULL, référence toujours valide."

**delete vs free?**
> "delete appelle le destructeur. new→delete, new[]→delete[]"
