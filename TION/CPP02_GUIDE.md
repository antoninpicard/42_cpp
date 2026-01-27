# CPP02 - GUIDE DE CORRECTION

## 🎯 THÈME DU MODULE
**Ad-hoc polymorphism, surcharge d'opérateurs et Orthodox Canonical Form**

---

## 📚 CONCEPTS CLÉS À EXPLIQUER

### 1. Orthodox Canonical Form (OCF)
Les **4 fonctions obligatoires** pour toute classe :
1. **Constructeur par défaut** : `Fixed()`
2. **Copy constructor** : `Fixed(const Fixed& other)`
3. **Copy assignment operator** : `Fixed& operator=(const Fixed& other)`
4. **Destructeur** : `~Fixed()`

### 2. Fixed-Point Numbers
- Nombre avec partie entière et partie fractionnaire
- Stocké comme un `int` avec des bits fractionnaires
- **8 bits fractionnaires** = précision de 1/256 = 0.00390625

### 3. Surcharge d'opérateurs
Permet d'utiliser les opérateurs (+, -, *, /, etc.) avec nos propres classes

---

## 📝 EXERCICE PAR EXERCICE

### EX00: My First Class in Orthodox Canonical Form

**Ce qu'il faut dire:**
> "Première classe en Orthodox Canonical Form. On a les 4 fonctions obligatoires : constructeur par défaut, copy constructor, assignment operator, et destructeur. Chacune affiche un message pour voir quand elle est appelée."

**Points techniques:**
- `_fixedPointValue` : stocke la valeur (int)
- `_fractionalBits` : toujours 8 (static const)
- `getRawBits()` : retourne la valeur brute
- `setRawBits()` : modifie la valeur brute

**Code clé:**
```cpp
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Utilise l'assignment operator
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}
```

**Si on te demande "Pourquoi if (this != &other) ?"**
> "Protection contre l'auto-assignation. Si on fait `a = a`, on ne fait rien."

---

### EX01: Towards a more useful fixed-point number class

**Ce qu'il faut dire:**
> "On ajoute des conversions : int→fixed-point et float→fixed-point, et inversement. On surcharge aussi l'opérateur << pour afficher."

**Points techniques:**
- **Int → Fixed:** `n << 8` (décale de 8 bits vers la gauche)
- **Float → Fixed:** `roundf(f * 256)` (multiplie par 2^8 et arrondit)
- **Fixed → Float:** `value / 256.0` (divise par 2^8)
- **Fixed → Int:** `value >> 8` (décale de 8 bits vers la droite)

**Code clé:**
```cpp
// Constructeur int
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

// Constructeur float
Fixed::Fixed(const float f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {}

// Conversion vers float
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Opérateur <<
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
```

**Si on te demande "Pourquoi << et >> ?"**
> "Bit shifting. Décaler de 8 bits = multiplier/diviser par 256. C'est rapide et précis."

**Si on te demande "Pourquoi roundf() ?"**
> "Pour arrondir correctement lors de la conversion float→fixed. Évite les erreurs d'arrondi."

---

### EX02: Now we're talking

**Ce qu'il faut dire:**
> "On surcharge 18 opérateurs ! 6 comparaisons, 4 arithmétiques, 4 incrémentations, et 4 fonctions statiques min/max."

**Points techniques:**

**1. Opérateurs de comparaison (6):**
```cpp
bool operator>(const Fixed& other) const {
    return _fixedPointValue > other._fixedPointValue;
}
// Pareil pour <, >=, <=, ==, !=
```

**2. Opérateurs arithmétiques (4):**
```cpp
// Addition : simple
Fixed operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue + other._fixedPointValue);
    return result;
}

// Multiplication : shift pour garder la précision
Fixed operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

// Division : shift avant de diviser
Fixed operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits((_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}
```

**3. Incrémentation (4):**
```cpp
// Pré-incrémentation (++a)
Fixed& operator++() {
    _fixedPointValue++;
    return *this;
}

// Post-incrémentation (a++)
Fixed operator++(int) {
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}
```

**4. Fonctions statiques min/max:**
```cpp
static Fixed& min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

static const Fixed& min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
```

**Si on te demande "Différence pré/post incrémentation ?"**
> "Pré (++a) : incrémente puis retourne. Post (a++) : retourne puis incrémente. Le post retourne une copie."

**Si on te demande "Pourquoi shift dans * et / ?"**
> "Pour garder la précision. Sans shift, on perdrait les bits fractionnaires."

**Si on te demande "C'est quoi epsilon ?"**
> "Le plus petit incrément possible. Ici c'est 1/256 = 0.00390625. On incrémente la valeur brute de 1."

---

## 💡 QUESTIONS FRÉQUENTES EN CORRECTION

### "C'est quoi Orthodox Canonical Form ?"
> "Les 4 fonctions obligatoires : constructeur par défaut, copy constructor, assignment operator, destructeur."

### "Pourquoi utiliser fixed-point au lieu de float ?"
> "Plus rapide sur certains processeurs (pas de FPU), précision contrôlée, déterministe. Utilisé en embarqué, jeux vidéo, audio."

### "Comment fonctionne le fixed-point ?"
> "On stocke un int. Les 8 bits de droite = partie fractionnaire, le reste = partie entière. 1 en valeur brute = 1/256 en réel."

### "Pourquoi 2 versions de min/max ?"
> "Une pour objets modifiables, une pour objets const. Surcharge sur const."

### "Pourquoi operator<< n'est pas membre ?"
> "Car le premier paramètre est std::ostream, pas Fixed. On ne peut pas modifier std::ostream."

---

## 🧮 EXEMPLE DE CALCUL

**Exemple : stocker 42.42**
```
42.42 * 256 = 10859.52 ≈ 10860 (après roundf)
En binaire : 10860 = 0010101001101100
             └─┬─┘ └────┬────┘
          entier(42)  fract(0.421875)
```

**Récupérer la valeur :**
```
10860 / 256 = 42.421875 ≈ 42.42
```

---

## ✅ CHECKLIST AVANT CORRECTION

- [ ] Je sais expliquer Orthodox Canonical Form
- [ ] Je sais expliquer fixed-point (8 bits fractionnaires)
- [ ] Je sais expliquer les conversions int/float ↔ fixed
- [ ] Je sais pourquoi on shift dans * et /
- [ ] Je sais la différence pré/post incrémentation
- [ ] Je sais pourquoi 2 versions de min/max

---

## 🎯 CONSEIL FINAL

**Montre le code et explique simplement :**
- "Regarde, pour multiplier deux fixed-point, je fais le produit puis je shift..."
- "L'opérateur << permet d'afficher directement avec std::cout..."

**Les maths peuvent paraître complexes, mais le code est simple !**

**Bon courage ! 🚀**
