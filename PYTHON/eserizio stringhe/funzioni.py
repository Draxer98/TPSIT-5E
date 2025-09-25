def soloLettere(parola:str):
    return parola.isalpha()

def creaLists(parola):
    pari = ""
    dispari = ""
    for i, p in enumerate(parola):
        if i % 2 == 0:
            pari += p
        else:
            dispari += p
    return pari, dispari

def doppie(parola):
    return len(set(parola)) < len(parola)

def lungaCorta(parola, parola2):
    if len(parola) > len(parola2):
        return True
    else:
        return False

def stesseLettere(parola:str,parola2:str):
    comuni = set(parola) & set(parola2)
    for lettera in comuni:
        print(lettera)

def piuVocali(parola:str,parola2:str):
    contatoreVocaliParola = 0
    contatoreVocaliParola2 = 0
    vocali = "aeiouAEIOU"
    for p in parola:
        if p in vocali:
            contatoreVocaliParola += 1
    for p in parola2:
        if p in vocali:
            contatoreVocaliParola2 += 1
    if contatoreVocaliParola > contatoreVocaliParola2:
        return 0
    elif contatoreVocaliParola2 > contatoreVocaliParola:
        return 1
    else:
        return 2

def piuConsonanti(parola:str,parola2:str):
    contatoreConsonantiParola = 0
    contatoreConsonantiParola2 = 0
    consonanti = "qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM"
    for p in parola:
        if p in consonanti:
            contatoreConsonantiParola += 1
    for p in parola2:
        if p in consonanti:
            contatoreConsonantiParola2 += 1
    if contatoreConsonantiParola > contatoreConsonantiParola2:
        return 0
    elif contatoreConsonantiParola > contatoreConsonantiParola2:
        return 1
    else:
        return 2        
