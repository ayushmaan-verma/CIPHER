# CIPHER  
**An AI-Safe Cryptosystem for Text-Based Data Encryption**

## 📌 Overview
**CIPHER** is a lightweight, symmetric cryptosystem implemented in **C** for secure encryption and decryption of text-based data.  
It uses a custom-designed combination of **character flipping**, **position-based XOR operations**, and **partial reversals** to generate highly non-linear encrypted outputs that are resistant to pattern analysis and AI-based decryption attempts.

This project was developed as an academic mini-project with a focus on **bit manipulation**, **string handling**, and **algorithmic design**.

---

## 🔐 Key Features
- Symmetric encryption–decryption system  
- Position-dependent XOR masking  
- Multi-stage character transformation  
- Resistant to frequency and pattern analysis  
- Lightweight and fast (no external libraries)  
- Fully reversible and deterministic  

---

## 🧠 How It Works

### Encryption Process
1. Take plaintext input  
2. Reverse the entire message  
3. Apply position-based XOR masks on each character  
4. Reverse the first half of the transformed message  
5. Output the encrypted text  

### Decryption Process
1. Take encrypted input  
2. Reverse the first half of the message  
3. Apply the same XOR pattern (XOR is self-inverse)  
4. Reverse the entire message  
5. Retrieve the original plaintext  

> Since XOR is its own inverse, the same key pattern ensures reversible transformation.

---

## 🧩 XOR Mask Pattern

| Position (i mod 6) | XOR Key |
|--------------------|---------|
| 0 | 7 |
| 1 | 5 |
| 2 | 3 |
| 3 | 4 |
| 4 | 6 |
| 5 | 1 |


Applying the decryption process restores the original message exactly.

---

## ⚙️ Implementation Details
- Language: C  
- Compiler: GCC  
- Platform: Linux  
- Input Handling: `fgets()`  
- Core Concepts: Bitwise XOR, string reversal, loops, conditionals  

---

## ✅ Advantages
- Nonlinear and unpredictable transformations  
- AI-resistant encryption pattern  
- Minimal computational overhead  
- No external libraries required  
- Strong educational value  

---

## 🎯 Learning Outcomes
- Understanding symmetric cryptography  
- Practical bitwise manipulation  
- Secure string handling in C  
- Algorithm design and reversibility  
- Cryptography fundamentals  

---

## 🚀 Conclusion
CIPHER demonstrates how simple operations like XOR and controlled character transformations can create complex and secure encryption systems.  
It is both a practical security tool and a strong foundational project in **C programming and cryptography**.


