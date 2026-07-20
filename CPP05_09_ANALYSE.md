# Analyse CPP05 → CPP09

---

## CPP05 — Gestion d'exceptions

### Ex00 : Bureaucrat basique + exceptions

**Concept :** Introduction aux exceptions custom. La classe `Bureaucrat` a un grade entre 1 (le plus haut) et 150 (le plus bas). Dépasser ces bornes lève une exception.

**Ce que tu dois savoir :**
- `throw` pour lancer une exception
- Classes d'exception imbriquées héritant de `std::exception`
- `try / catch` pour attraper les exceptions
- `what()` override pour afficher un message custom

**Erreurs détectées :** Aucune.

---

### Ex01 : Formulaires (Form)

**Concept :** Ajout d'une classe `Form` avec deux grades : un pour signer, un pour exécuter. Le `Bureaucrat` peut signer un formulaire si son grade est suffisant.

**Ce que tu dois savoir :**
- Les membres `const` doivent être initialisés dans la liste d'initialisation
- `signForm()` appelle `beSigned()` qui lève une exception si grade insuffisant
- Relation entre deux classes avec exceptions croisées

**Erreurs détectées :** Aucune.

---

### Ex02 : Formulaires abstraits (AForm)

**Concept :** `Form` devient `AForm` (classe abstraite). Trois formulaires concrets héritent de `AForm` :
- `ShrubberyCreationForm` : crée un fichier avec un arbre ASCII
- `RobotomyRequestForm` : 50% de chance de succès, utilise `rand()`
- `PresidentialPardonForm` : message de grâce présidentielle

**Ce que tu dois savoir :**
- Méthode virtuelle pure : `virtual void execute(Bureaucrat const&) const = 0;`
- Le destructeur de la classe abstraite doit être `virtual`
- Vérifier que le formulaire est signé ET que le grade est suffisant avant d'exécuter

**Erreurs détectées :** Aucune.

---

### Ex03 : Intern (Factory Pattern)

**Concept :** La classe `Intern` peut créer n'importe quel formulaire à partir d'un nom en string. C'est le patron de conception **Factory**.

**Ce que tu dois savoir :**
- Utilisation d'un tableau de pointeurs de fonctions pour mapper les noms aux constructeurs
- `makeForm()` retourne un `AForm*` — le client doit vérifier que ce n'est pas `NULL`
- Séparation des responsabilités : `Intern` fabrique, `Bureaucrat` signe et exécute

**Erreurs détectées :**
- Le code client doit vérifier que `makeForm()` ne retourne pas `NULL` avant d'utiliser le pointeur (nom de formulaire inconnu).

---

## CPP06 — Casts C++

### Ex00 : Convertisseur de types scalaires

**Concept :** Détecter automatiquement le type d'un littéral (`char`, `int`, `float`, `double`, pseudo-littéraux comme `nan`, `+inf`) et afficher sa conversion vers tous les autres types.

**Ce que tu dois savoir :**
- `static_cast<>` pour les conversions entre types arithmétiques
- Détection du type par analyse de la string (suffixe `f`, point décimal, plage de valeur)
- Gestion des cas impossibles : caractères non affichables, valeurs hors range
- `std::numeric_limits<>` pour tester les bornes

**Erreurs détectées :**
- Comparaisons de flottants avec cast vers `long` fragiles — utiliser une comparaison epsilon ou `std::numeric_limits` à la place.

---

### Ex01 : Sérialisation de pointeurs

**Concept :** Convertir un pointeur en entier et le reconvertir en pointeur. Démonstration de `reinterpret_cast`.

**Ce que tu dois savoir :**
- `reinterpret_cast<uintptr_t>(ptr)` : pointeur → entier
- `reinterpret_cast<Data*>(raw)` : entier → pointeur
- `uintptr_t` est garanti assez grand pour stocker un pointeur
- Ce cast ne change pas les bits, il change juste l'interprétation

**Erreurs détectées :** Aucune.

---

### Ex02 : RTTI et dynamic_cast

**Concept :** Identifier à l'exécution le type réel d'un objet via RTTI (Run-Time Type Information).

**Ce que tu dois savoir :**
- `dynamic_cast<A*>(ptr)` retourne `nullptr` si le cast échoue (version pointeur)
- `dynamic_cast<A&>(ref)` lève `std::bad_cast` si le cast échoue (version référence)
- Nécessite que la classe de base ait au moins une méthode virtuelle
- `generate()` retourne aléatoirement un `A*`, `B*` ou `C*` sous forme de `Base*`

**Erreurs détectées :** Aucune.

---

## CPP07 — Templates

### Ex00 : Fonctions génériques

**Concept :** Créer des fonctions templates de base : `swap`, `min`, `max`.

**Ce que tu dois savoir :**
- Syntaxe `template <typename T>`
- Les fonctions templates sont définies dans le `.hpp` (pas dans un `.cpp`)
- `min` et `max` retournent `const T&` pour éviter les copies inutiles
- Le type `T` doit supporter les opérateurs `<` et `>`

**Erreurs détectées :** Aucune.

---

### Ex01 : iter — fonction d'ordre supérieur

**Concept :** Template de fonction qui applique une fonction à chaque élément d'un tableau.

**Ce que tu dois savoir :**
- Deux paramètres template : `T` (type du tableau) et `F` (type de la fonction)
- Signature : `template<typename T, typename F> void iter(T* arr, size_t len, F func)`
- La fonction peut être un pointeur de fonction, un lambda, ou un foncteur

**Erreurs détectées :** Aucune.

---

### Ex02 : Classe template Array

**Concept :** Créer une classe tableau générique avec gestion de mémoire, copie profonde et vérification des bornes.

**Ce que tu dois savoir :**
- Template de classe : `template <typename T> class Array`
- Constructeur par défaut, constructeur de taille, constructeur de copie
- `operator[]` avec vérification des bornes (throw si hors range)
- Version `const` et non-`const` de `operator[]`
- La forme canonique orthodoxe (constructeur copie + operateur= avec copie profonde)

**Erreurs détectées :** Aucune.

---

## CPP08 — Conteneurs STL

### Ex00 : easyfind

**Concept :** Wrapper générique autour de `std::find` qui lève une exception si la valeur n'est pas trouvée.

**Ce que tu dois savoir :**
- Template sur le type de conteneur `T` (pas sur le type de valeur)
- `std::find(container.begin(), container.end(), value)` retourne `end()` si pas trouvé
- Fonctionne avec `vector`, `list`, `deque`, etc. (tout ce qui a `begin()`/`end()`)

**Erreurs détectées :**
- L'exception lancée est `std::exception()` générique. Préférer une exception custom ou `std::runtime_error` avec un message clair.

---

### Ex01 : Span

**Concept :** Classe avec capacité fixe qui calcule la plus courte et la plus longue distance entre ses éléments.

**Ce que tu dois savoir :**
- `shortestSpan()` : trier une copie, puis trouver la différence minimale entre éléments consécutifs
- `longestSpan()` : `max - min` avec `std::max_element` et `std::min_element`
- `addRange()` template pour insérer depuis un range d'itérateurs
- Exception si conteneur plein ou moins de 2 éléments pour calculer un span

**Erreurs détectées :** Aucune.

---

### Ex02 : MutantStack

**Concept :** `std::stack` n'a pas d'itérateurs. `MutantStack` en ajoute en exposant les itérateurs du conteneur interne.

**Ce que tu dois savoir :**
- `std::stack<T>` utilise en interne un `std::deque<T>` accessible via `this->c`
- Il suffit de définir `begin()`, `end()`, `rbegin()`, `rend()` (et leurs variantes `const`)
- Exemple d'héritage public d'un conteneur STL (déconseillé en prod, mais valide ici)

**Erreurs détectées :** Aucune.

---

## CPP09 — Applications réelles

### Ex00 : Bitcoin Exchange

**Concept :** Lire une base de données CSV de prix Bitcoin par date, puis calculer la valeur d'un portefeuille à une date donnée (avec interpolation vers la date précédente si nécessaire).

**Ce que tu dois savoir :**
- `std::map<std::string, float>` pour stocker date → prix (trié automatiquement)
- `lower_bound()` pour trouver la date la plus proche inférieure ou égale
- Validation des dates (format YYYY-MM-DD, jours valides, années bissextiles)
- Parsing de CSV avec `getline` et `find`

**Erreurs détectées :**
- Si le fichier ne s'ouvre pas, le code affiche juste un message et retourne silencieusement sans signaler l'erreur à l'appelant.
- `strtof()` n'est pas vérifié pour overflow/underflow.

---

### Ex01 : RPN (Notation Polonaise Inversée)

**Concept :** Évaluer une expression mathématique en notation polonaise inversée (les opérateurs viennent après les opérandes) avec une pile.

**Exemple :** `3 4 + 2 *` = `(3 + 4) * 2 = 14`

**Ce que tu dois savoir :**
- `std::stack<int>` pour stocker les opérandes
- Pour chaque token :
  - Si c'est un chiffre → `push`
  - Si c'est un opérateur → `pop` deux valeurs, calculer, `push` le résultat
- Vérifier qu'il y a assez d'opérandes sur la pile avant chaque opération

**Erreurs détectées :**
- Seuls les chiffres de 0 à 9 sont acceptés (nombres à un seul chiffre). Cela correspond aux specs du sujet, mais à noter.
- Tous les cas d'erreur affichent le même message `"Error"` sans détail.

---

### Ex02 : PmergeMe (Ford-Johnson Sort)

**Concept :** Implémenter l'algorithme de tri **Ford-Johnson** (merge-insertion sort), qui est théoriquement optimal en nombre de comparaisons. L'exercice demande d'implémenter le même algorithme avec `std::vector` et `std::deque` et de comparer les performances.

**Fonctionnement de l'algorithme :**
1. Former des paires d'éléments et comparer
2. Trier récursivement les "gagnants" (plus grands de chaque paire)
3. Insérer les "perdants" dans la séquence triée en utilisant l'ordre de Jacobsthal pour minimiser les comparaisons
4. Gérer l'élément orphelin si le nombre d'éléments est impair

**Ce que tu dois savoir :**
- Suite de Jacobsthal : 0, 1, 1, 3, 5, 11, 21, 43... → définit l'ordre optimal d'insertion
- `std::lower_bound()` pour l'insertion binaire dans la séquence triée
- `std::clock()` pour mesurer le temps d'exécution
- La différence de performance entre `vector` (accès aléatoire O(1)) et `deque` (meilleures insertions en début)

**Erreurs détectées (IMPORTANTES) :**
- **Bug critique :** La valeur `-1` est utilisée comme sentinelle pour marquer les paires déjà traitées. Si l'entrée contient des nombres négatifs ou la valeur `-1`, l'algorithme produit des résultats incorrects.
- La recherche des paires par valeur du gagnant est O(n²) — inefficace pour de grands tableaux. Il faudrait tracker les indices des paires.

---

## Récapitulatif des erreurs

| Module | Exercice | Niveau | Description |
|--------|----------|--------|-------------|
| cpp06 | ex00 | Mineur | Comparaison de flottants fragile avec cast vers `long` |
| cpp08 | ex00 | Mineur | Exception générique au lieu d'un type spécifique |
| cpp09 | ex00 | Mineur | Erreur de fichier gérée silencieusement |
| cpp09 | ex01 | Info | Seuls les nombres à un chiffre sont supportés |
| cpp09 | ex02 | **Critique** | Sentinelle `-1` : bug si l'entrée contient des négatifs |
| cpp09 | ex02 | Moyen | Recherche de paires en O(n²) |

---

## Concepts clés par module

| Module | Concept principal |
|--------|------------------|
| cpp05 | Exceptions custom, classes imbriquées, polymorphisme |
| cpp06 | `static_cast`, `reinterpret_cast`, `dynamic_cast`, RTTI |
| cpp07 | Templates de fonctions et de classes |
| cpp08 | Conteneurs STL, algorithmes, itérateurs |
| cpp09 | Parsing de fichiers, structures de données, algorithmique avancée |
