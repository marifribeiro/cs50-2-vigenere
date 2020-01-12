# Index

1. [Vigenere's Cipher](https://github.com/maryplank/SAP003-cipher#vigeneres-cipher) 

2. [How it works](https://github.com/maryplank/SAP003-cipher#how-it-works)

3. [About the aplication](https://github.com/maryplank/SAP003-cipher#about-the-application)

4. [Usage](https://github.com/maryplank/SAP003-cipher#usage)

# Vigenere's Cipher

It's a encryption method where you shift each letter of the text according to each letter value of a keyword.
It's simmilar to [Caesar's cipher](https://github.com/maryplank/cs50-2-caesar), but with a twist. Instead of a numerical key, you use the values of the letters in a keyword to make the encryption.

For example, the word "LOVE", when encrypted using Vigenere's cipher with the *keyword **dog** (this will be our little secret, ok?)* will become "OCBH".

# How it works
Let's count the letters of the alphabet **starting at 0.**
So: A = 0, B = 1, C = 2... and so on, until Z = 25.
On the example above, we have the following letters of the text we want to encrypt:

|Letter | Value |
|-------|-------|
|L      |11     |
|O      |14     |
|V      |21     |
|E      |4      |

And there is our keyword **dog***:

|Letter | Value |
|-------|-------|
|D      |3      |
|O      |14     |
|G      |6      |


If we add our *super-secret keyword*, our text will be encrypted like this:

|Letter| Value| Keyword letter |keyword value | Result                   | New letter |
|------|------|----------------|--------------|--------------------------|------------|
|L     |11    |D               |3             |3 + 11 = 14               |O           |
|O     |14    |O               |14            |14 + 14 = 28 (28 - 26 = 2)|C           |
|V     |21    |G               |6             |21 + 6 = 27 (27 - 26 = 1) |B           |
|E     |4     |D               |3             |4 + 3 = 7                 |H           |

Let's talk about some weird things in this table:
Dog is a smaller word than Love. In this case, the keyword will repeat itself as much times as needed to encrypt the whole text.
In reverse, if the keyword is bigger than the text to be encrypt, it will just use as many letters of the keyword as it takes to encrypt the whole text.
When the sum of the plaintext letter and the respective keyword letter is bigger than 26 (the number of letters in the alphabet), it will go around it back to "a". That is what happens in our example above.


# About the application

This is a command line application and it was developed fully in C.

It will encrypt uppercase letters, keeping them uppercased and the same goes for lowercase letters. Numbers, punctuation (commas, periods, exclamation points and question marks) and special characters (like letters with accents and other signals) will remain as they are typed, they will be not encrypted.

Example:

**¡Este es un texto de ejemplo! ¿Cómo será encriptado?**

Using the keyword of **banana**, this text will be encrypted as:

**¡Eftr et ua trxuo qe rjfmclb! ¿Cómb srrá eaceiqtndb?**

As you can see, the letters with accents and puctuation were not encrypted, so you should have that in mind when typing your message.


## Usage

You will need to install the [CS50 library](https://cs50.readthedocs.io/library/c/) to use this program.

Clone this repository, then, through the command line, enter the program's folder and run the following command to compile:

`gcc -o vigenere vigenere.c -ls50`

Then run the application. Keep in mind the key to encrypt must be only one word:

`./vigenere <keyword>`

The program will ask for a plaintext, which will be spilled back to you using the keyword you inserted in the previous command.

```
Plaintext: <text to encrypt>
Ciphertext: <return of the text you typed using the keyword you provided>
```

