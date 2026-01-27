# CPP01 - GUIDE DE CORRECTION

## 🎯 THÈME DU MODULE
**Gestion de la mémoire, pointeurs, références et switch statements**

---

## 📚 CONCEPTS CLÉS À EXPLIQUER

### 1. Stack vs Heap
- **Stack:** Variables locales, automatiquement détruites en fin de scope
- **Heap:** Allocation avec `new`, destruction manuelle avec `delete`

### 2. Pointeurs vs Références
- **Pointeur:** Peut être NULL, peut changer de cible, syntaxe avec `*` et `->`
- **Référence:** Toujours valide, ne peut pas changer, syntaxe normale avec `.`

---

## 📝 EXERCICE PAR EXERCICE

### EX00: BraiiiiiiinnnzzzZ

**Ce qu'il faut dire:**
> "Cet exercice montre la différence entre allocation stack et heap. `newZombie()` alloue sur le heap avec `new` car le zombie doit survivre après la fonction. `randomChump()` alloue sur la stack car le zombie n'est utilisé que dans la fonction."

**Points techniques:**
- `newZombie()` retourne un pointeur → l'appelant doit faire `delete`
- `randomChump()` crée un zombie local → destruction automatique
- Le destructeur affiche un message pour voir quand l'objet est détruit

**Si on te demande "Pourquoi heap vs stack ?"**
> "Heap quand l'objet doit survivre après la fonction, stack pour usage temporaire local."

---

### EX01: Moar brainz!

**Ce qu'il faut dire:**
> "Ici on crée un tableau de zombies en une seule allocation avec `new Zombie[N]`. Important : on utilise `delete[]` et pas `delete` pour libérer un tableau."

**Points techniques:**
- `new Zombie[N]` → allocation d'un tableau
- Tous les zombies ont le même nom (passé en paramètre)
- `delete[]` appelle le destructeur pour chaque élément

**Si on te demande "Pourquoi une seule allocation ?"**
> "Plus efficace en mémoire, et le sujet le demande explicitement."

---

### EX02: HI THIS IS BRAIN

**Ce qu'il faut dire:**
> "Exercice simple pour montrer qu'un pointeur et une référence pointent vers la même adresse mémoire. Les 3 adresses affichées sont identiques."

**Points techniques:**
- `stringPTR = &brain` → pointeur vers brain
- `stringREF = brain` → référence vers brain (alias)
- Même adresse mémoire pour les 3

**Si on te demande "Différence pointeur/référence ?"**
> "Pointeur peut être NULL et changer, référence est toujours valide et fixe."

---

### EX03: Unnecessary violence

**Ce qu'il faut dire:**
> "Cet exercice montre quand utiliser référence vs pointeur. HumanA a une référence car il a TOUJOURS une arme. HumanB a un pointeur car il peut être sans arme au début."

**Points techniques:**
- **HumanA:** `Weapon& _weapon` → constructeur prend l'arme, toujours armé
- **HumanB:** `Weapon* _weapon` → peut être NULL, `setWeapon()` pour armer après
- `getType()` retourne `const std::string&` pour éviter une copie

**Si on te demande "Pourquoi ce choix ?"**
> "Référence = garantie d'existence. Pointeur = peut être NULL. HumanA est toujours armé, HumanB non."

---

### EX04: Sed is for losers

**Ce qu'il faut dire:**
> "Programme qui remplace toutes les occurrences d'une string dans un fichier. Important : on ne peut PAS utiliser `std::string::replace()`, c'est interdit par le sujet."

**Points techniques:**
- 3 paramètres : filename, s1 (à chercher), s2 (remplacement)
- Crée un fichier `<filename>.replace`
- Utilise `find()` et `substr()` pour faire le remplacement manuellement
- Gestion d'erreurs : fichier inexistant, s1 vide

**Si on te demande "Comment tu remplaces sans replace() ?"**
> "Je cherche avec `find()`, je copie avant avec `substr()`, j'ajoute s2, puis je continue après la position trouvée."

---

### EX05: Harl 2.0

**Ce qu'il faut dire:**
> "Harl se plaint selon 4 niveaux. Le sujet INTERDIT d'utiliser des if/else en cascade. On utilise un tableau de pointeurs vers fonctions membres."

**Points techniques:**
- 4 fonctions privées : `debug()`, `info()`, `warning()`, `error()`
- `complain()` utilise un tableau de pointeurs vers fonctions membres
- Syntaxe : `void (Harl::*functions[])(void) = {...}`
- Appel : `(this->*functions[i])()`

**Si on te demande "Pourquoi des pointeurs vers fonctions ?"**
> "Le sujet l'impose pour éviter les if/else. C'est plus élégant et extensible."

**Code clé à montrer:**
```cpp
void (Harl::*functions[])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
```

---

## 💡 QUESTIONS FRÉQUENTES EN CORRECTION

### "Quelle est la différence entre new et malloc ?"
> "`new` appelle le constructeur et est type-safe. `malloc` alloue juste de la mémoire brute. En C++, on utilise toujours `new`."

### "Pourquoi delete et pas free ?"
> "`delete` appelle le destructeur, `free` non. Il faut matcher : `new`→`delete`, `new[]`→`delete[]`."

### "C'est quoi une référence exactement ?"
> "Un alias vers une variable existante. Même adresse mémoire, syntaxe plus simple qu'un pointeur."

### "Quand utiliser pointeur vs référence ?"
> "Référence quand l'objet existe toujours. Pointeur quand il peut être NULL ou changer."

---

## ✅ CHECKLIST AVANT CORRECTION

- [ ] Je sais expliquer stack vs heap
- [ ] Je sais expliquer new/delete vs new[]/delete[]
- [ ] Je sais expliquer pointeur vs référence
- [ ] Je peux montrer le code des pointeurs vers fonctions membres (ex05)
- [ ] Je sais pourquoi HumanA a une référence et HumanB un pointeur

---

## 🎯 CONSEIL FINAL

**Reste simple et concret.** Si on te demande un concept, donne un exemple du code :
- "Regarde ex00, `newZombie()` retourne un pointeur car..."
- "Dans ex03, HumanA a une référence parce que..."

**Bon courage ! 🚀**
