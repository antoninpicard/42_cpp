# CPP02 - GUIDE RAPIDE

## 🎯 THÈME
Surcharge d'opérateurs, Orthodox Canonical Form

---

## Orthodox Canonical Form (OCF)

**4 fonctions obligatoires:**
1. Constructeur par défaut
2. Copy constructor
3. Assignment operator `=`
4. Destructeur

---

## EX00: OCF de base

**L'essentiel:**
- Classe Fixed avec les 4 fonctions OCF
- `_fixedPointValue` (int) + `_fractionalBits = 8` (static const)
- Messages dans chaque fonction

**Protection auto-assignation:**
```cpp
if (this != &other)
```

---

## EX01: Conversions

**L'essentiel:**
- **Int → Fixed:** `n << 8`
- **Float → Fixed:** `roundf(f * 256)`
- **Fixed → Float:** `value / 256.0`
- **Fixed → Int:** `value >> 8`

**Opérateur <<:**
```cpp
std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}
```

---

## EX02: Opérateurs (18 total)

**6 comparaisons:** >, <, >=, <=, ==, !=
```cpp
bool operator>(const Fixed& other) const {
    return _fixedPointValue > other._fixedPointValue;
}
```

**4 arithmétiques:** +, -, *, /
```cpp
// Multiplication (shift pour précision)
Fixed operator*(const Fixed& other) const {
    result.setRawBits((_value * other._value) >> 8);
}
```

**4 incrémentations:** ++a, a++, --a, a--
```cpp
Fixed& operator++() { _value++; return *this; }  // pré
Fixed operator++(int) { Fixed tmp(*this); _value++; return tmp; }  // post
```

**4 min/max:** 2 versions (const et non-const)

---

## 💡 QUESTIONS RAPIDES

**OCF?**
> "4 fonctions: constructeur, copy, assignment, destructeur."

**Pourquoi shift dans * et /?**
> "Pour garder la précision des bits fractionnaires."

**Pré vs post incrémentation?**
> "Pré: incrémente puis retourne. Post: retourne puis incrémente."

**Epsilon?**
> "Plus petit incrément = 1/256 = 0.00390625"
