'''Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
2) Visualizzi a video l’array invertito, cioè, sostituendo il primo elemento con l’ultimo, il secondo con il
penultimo e così via;
3) Visualizzi a video la somma e media degli elementi del vettore;
4) Visualizzi a video tutti i numeri pari;
5) Visualizzi a video tutti i numeri dispari;
6) Ricerchi un numero (letto in input) nell’array;
7) Elimini un elemento (letto in input) dell’array (se esistente);
8) Alterni (o scambi) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).'''

from random import randrange

def menu():
    print("1 - Generare e Visualizzare array")
    print("2 - Visualizzare array invertito")
    print("3 - Visualizzare somma e media")
    print("4 - Visualizzare numeri pari array")
    print("5 - Visualizzare numeri dispari array")
    print("6 - Ricerca numero")
    print("7 - Elimina numero")
    print("8 - Alternare a due a due")
    print("9 - Ordinare l'array")
    print("10 - Exit")

array = []
exit = False

while exit == False:
    menu()
    scelta = input("Inserisci: ")
    match scelta:
        case "1":
            i = 0
            for _ in range(5):
                array.append(randrange(0, 100))
                i = i + 1
            print(array)
        case "2":
            array.reverse()
            print(array)
        case "3":
            summa = sum(array)   
            media = summa / len(array)
            print("Somma: ", summa)
            print("Media: ", media)
        case "4":
            for n in array:
                if n % 2 == 0:
                    print(n)
        case "5":
            for n in array:
                if n % 2 != 0:
                    print(n)
        case "6":
            ricerca = int(input("Inserisci numero per ricerca: "))
            if ricerca in array:
                print("Numero trovato")
            else:
                print("Numero non trovato") 
        case "7":
            elimina = int(input("Inserisci numero per ricerca: "))
            if elimina in array:
                array.remove(elimina)
                print("Numero eliminato")
        case "8":
            i = 0
            while i < len(array) -1:
                temp = array[i+1]
                array[i+1] = array[i]
                array[i] = temp
                i = i + 2
            print(array)    
        case "9":
            array.sort()
            print(array)
        case "10":
            exit = True