# 📚 GUIDES DE CORRECTION - MODULES C++

Bienvenue dans tes guides de correction ! Ce dossier contient tout ce qu'il faut savoir pour expliquer ton code pendant les évaluations.

---

## 📖 CONTENU

- **CPP01_GUIDE.md** - Gestion mémoire, pointeurs, références
- **CPP02_GUIDE.md** - Surcharge d'opérateurs, Orthodox Canonical Form, fixed-point
- **CPP03_GUIDE.md** - Héritage
- **CPP04_GUIDE.md** - Polymorphisme, classes abstraites, interfaces

---

## 🎯 COMMENT UTILISER CES GUIDES

### Avant la correction :
1. **Lis le guide du module concerné** (5-10 minutes)
2. **Regarde les "Code clé" et "Points techniques"**
3. **Vérifie la checklist à la fin**

### Pendant la correction :
1. **Reste simple** - Explique avec tes mots
2. **Montre le code** - C'est plus clair qu'un long discours
3. **Utilise les exemples** du guide si besoin
4. **Réponds aux questions** avec les "Si on te demande..."

---

## 💡 CONSEILS GÉNÉRAUX

### ✅ À FAIRE
- Parler simplement et clairement
- Montrer le code en live
- Donner des exemples concrets
- Dire "Je ne sais pas" si tu ne sais vraiment pas (mieux que d'inventer)

### ❌ À ÉVITER
- Réciter par cœur sans comprendre
- Utiliser des mots trop techniques sans les expliquer
- Paniquer si on te pose une question difficile
- Mentir ou inventer

---

## 🔑 CONCEPTS CLÉS PAR MODULE

### CPP01 - Mémoire
- Stack vs Heap
- new/delete vs new[]/delete[]
- Pointeurs vs Références
- Pointeurs vers fonctions membres

### CPP02 - Opérateurs
- Orthodox Canonical Form (4 fonctions)
- Fixed-point numbers (8 bits fractionnaires)
- Surcharge d'opérateurs (18 types)
- Bit shifting

### CPP03 - Héritage
- Héritage : `class Derived : public Base`
- Chaînage construction/destruction
- public / protected / private
- Messages différents par classe

### CPP04 - Polymorphisme
- Fonctions virtuelles (`virtual`)
- Destructeur virtuel (obligatoire)
- Classes abstraites (pure virtual `= 0`)
- Interfaces (que des fonctions pures)
- Deep copy (copier le contenu, pas le pointeur)

---

## 🎓 QUESTIONS ULTRA-FRÉQUENTES

### "Quelle est la différence entre new et malloc ?"
> `new` appelle le constructeur et est type-safe. En C++, on utilise toujours `new`.

### "Pourquoi delete et pas free ?"
> `delete` appelle le destructeur. Il faut matcher : `new`→`delete`, `new[]`→`delete[]`.

### "C'est quoi une référence ?"
> Un alias vers une variable existante. Même adresse mémoire, syntaxe plus simple.

### "C'est quoi Orthodox Canonical Form ?"
> Les 4 fonctions obligatoires : constructeur par défaut, copy constructor, assignment operator, destructeur.

### "C'est quoi le polymorphisme ?"
> Utiliser un pointeur de classe de base pour manipuler des objets dérivés. La bonne fonction est appelée grâce à `virtual`.

### "Pourquoi destructeur virtuel ?"
> Pour que `delete` sur un pointeur de base appelle le destructeur de la classe dérivée. Sinon fuite mémoire.

### "C'est quoi deep copy ?"
> Copier le contenu pointé, pas juste le pointeur. Chaque objet a sa propre mémoire.

---

## 🚀 BON COURAGE !

**Tu as fait le code, tu peux l'expliquer !**

Ces guides sont là pour te rafraîchir la mémoire et te donner confiance.

**Reste calme, sois honnête, et tout ira bien.** 💪

---

## 📞 AIDE RAPIDE

Si tu paniques pendant la correction :
1. **Respire** 🧘
2. **Regarde le code** 👀
3. **Explique ce que tu vois** 🗣️
4. **Utilise les exemples** du guide 📖

**Tu vas gérer ! 🎉**
