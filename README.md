# RSA ENCRYPTION / DECRYPTION

## 1. Compile Code
you can compile with g++ -o pa1 pa1.cpp -lm -lgmp -lgmpxx   
and run the code with ./pa1

## 2. Program Information
when you run the code, you can choose one option.
```
Enter your choice (1.Encrypt  2.Decrypt  3.Exit): 
```
   
### 2.1. Encrypt
In Encrpytion, you have to give two prime numbers (p, q) and plaintext (m) to encrpt.
```
give two prime numbers: p, q
give plaintext to encrypt: m
```
and you can get public key(e, n), private key(d), and ciphertext(c).
```
public key(e, n) is: e, n
private key is: d
ciphertext is: c
```

### 2.2. Decrypt
In Decrpytion, you have to give private key(n), private key(d) and ciphertext(c). 
```
give public key(n): n
give private key: d
give ciphertext to decrypt: c
```
and you can get decrypted original plaintext(m).
```
plaintext is: m
```
### 2.3. Exit
When you choose Exit, you can simply exit program.



## 3. Running Example
running example looks like below.
![title](/img.png)

