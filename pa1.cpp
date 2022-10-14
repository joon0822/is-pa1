#include<iostream>
#include<stdio.h>
#include<cmath>
#include<gmp.h>
#include<gmpxx.h> //g++ -o pa1 pa1.cpp -lm -lgmp -lgmpxx

using namespace std;

// validates the given two prime numbers
// Generates a (pulbic, private) key pair (e.g. integer)
// get prime number p, q and e, n, d where we store public key(e, n) and private key(d)
void Keygen(mpz_t p, mpz_t q, mpz_t e, mpz_t n, mpz_t d){
    /*  validation if p, q is prime */
    if(mpz_probab_prime_p(p, 10) == 0) {cout<<"p is not prime"<<endl; return;} // p is not prime
    if(mpz_probab_prime_p(q, 10) == 0) {cout<<"q is not prime"<<endl; return;}// q is not prime
    // now, both p and q are prime numbers

    /* generate key */
    // mpz_t n; // n : public key
    mpz_mul(n, p, q); // n =  pq

    mpz_t one;
    mpz_init(one);
    mpz_set_ui(one, 1); // one = 1

    mpz_t pminus, qminus;
    mpz_init(pminus);
    mpz_init(qminus);
    mpz_sub(pminus, p, one); // pminus = p-1
    mpz_sub(qminus, q, one); // qminus = q-1

    mpz_t phi; // phi(n)
    mpz_init(phi);
    mpz_mul(phi, pminus, qminus); // phi(n) = (p-1)(q-1)

    // choose int e s.t. 1<e<phi(n) and gcd(e, phi(n))=1
    // mpz_t e; // e : public key
    mpz_set_ui(e, 3); // start from e=3
    while(true){
        cout<<mpz_divisible_p(phi, e)<<endl;
        if(mpz_divisible_p(phi, e) == 0) break; // if phi(n) is not divisible by e -> gcd(e, phi(n)) == 1
        else mpz_add(e, e, one); // else, e=e+1
    }

    // mpz_t d; // d : private key
    mpz_set_ui(d, 1); // start form d=1
    mpz_t mod; mpz_init(mod);// modulus value
    mpz_t e_d; mpz_init(e_d);// e*d
    while(true){
        mpz_mul(e_d, e, d); // e_d = e * d
        mpz_mod(mod, e_d, phi);
        if(mpz_cmp(mod, one) == 0) break; // compare if mod = 1 -> it means 1 === e*d mod(phi(n))
        else mpz_add(d, d, one); // else, d=d+1
    }
    // so we finally get public key(d) and priavate key(e, n) from p and q.
    
}

// Given a plaintext(m) (integer) and the public key(e, n)
// Encrypts the paintext(m) and returns a ciphertext(c)
void Encrypt(mpz_t m, mpz_t e, mpz_t n, mpz_t c){

    mpz_powm(c, m, e, n); // set c === m^e (mod n)

}

// Given the ciphertext(c) and the private key(d)
// Decrypts the ciphertext(c) and returns the plaintext(m)
void Decrypt(mpz_t c, mpz_t d, mpz_t n, mpz_t m){
    
    mpz_powm(m, c, d, n); // set m === c^d (mod n)

}

int main(){
    int num = 0;
    // two prime numbers
    mpz_t p; mpz_init(p);
    mpz_t q; mpz_init(q);
    // public keys (e, n)
    mpz_t e; mpz_init(e);
    mpz_t n; mpz_init(n);
    // private key (d)
    mpz_t d; mpz_init(d);
    // plaintext(given message) (m)
    mpz_t m; mpz_init(m);
    // ciphertext
    mpz_t c; mpz_init(c);

    cout<<"Enter your choice (1.Encrypt  2.Decrypt  3.Exit): ";
    cin>>num;
    if(num==1){
        cout<<"give two prime numbers: ";
        cin>>p>>q;
        cout<<"give plaintext to encrypt: ";
        cin>>m;
        Keygen(p, q, e, n, d);
        cout<<"public key(e, n) is: "<<e<<" "<<n<<endl;
        cout<<"private key is: "<<d<<endl;
        Encrypt(m, e, n, c);
        cout<<"ciphertext is: "<<c<<endl;
        return 0;
    }
    else if(num==2){
        cout<<"give public key(n): ";
        cin>>n;
        cout<<"give private key: ";
        cin>>d;
        cout<<"give ciphertext to decrypt: ";
        cin>>c;
        Decrypt(c, d, n, m);
        cout<<"plaintext is: "<<m<<endl;
        return 0;
    }
    else if(num==3)return 0;
    
    return 0;
}
