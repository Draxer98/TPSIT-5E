'''
Scrivere un programma in PYTHON che dopo aver inserito una stringa a 
piacere determini e o verifichi:
1) Che contenga solo lettere;
2) Il conteggio di una lettera (se presente) scelta dall’utente;
3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; 
la 2° le lettere di posizione dispari;
4) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
5) Quale delle 2 è più lunga e più corta;
6) Quali sono le lettere contenute in ambedue le stringhe;
7) Quale delle 2 stringhe contiene più vocali;
8) Quale delle 2 stringhe contiene più consonanti;
'''
import funzioni as f
_continue = True
pari = ""
dispari = ""

#1) Che contenga solo lettere;
while _continue:
    parola = input("Inserisci una parola (no lettere): ")
    if not f.soloLettere(parola):
        print("Hai inserito una lettera, riprova")
    else:
        _continue = False

#2) Il conteggio di una lettera (se presente) scelta dall’utente;
contaLettera = input("Conteggio lettera cercata: ")

print(parola.count(contaLettera))

#3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; 
#la 2° le lettere di posizione dispari;
pari, dispari = f.creaLists(parola)

print(pari)
print(dispari)

#4) Verifichi se contiene doppie.
if f.doppie(parola):
    print("Contiene doppie")
else:
    print("Non contiene doppie")

parola2 = input("Inserisci una seconda parola: ")

#5) Quale delle 2 è più lunga e più corta;
if f.lungaCorta(parola,parola2):
    print("La prima parola è piu' lunga della seconda")
else:
    print("La seconda parola è piu' lunga della prima o uguale")

#6) Quali sono le lettere contenute in ambedue le stringhe;
f.stesseLettere(parola,parola2)

#7) Quale delle 2 stringhe contiene più vocali;
if f.piuVocali(parola,parola2) == 0:
    print("La prima parola ha piu' vocali")
elif f.piuVocali(parola,parola2) == 1:
    print("La seconda parola ha piu' vocali")
elif f.piuVocali(parola, parola2) == 2:
    print("Hanno lo stesso numero di voacali")

#8) Quale delle 2 stringhe contiene più consonanti;
if f.piuConsonanti(parola,parola2) == 0:
    print("La prima parola ha piu' consonanti")
elif f.piuConsonanti(parola,parola2) == 1:
    print("La seconda parola ha piu' consonanti")
elif f.piuConsonanti(parola, parola2) == 2:
    print("Hanno lo stesso numero di consonanti")