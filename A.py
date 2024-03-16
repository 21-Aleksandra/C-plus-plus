# Aleksandra Dmitruka,ad22069

# A30. Dots naturāls skaitlis n. Noskaidrot, vai šī skaitļa pirmais cipars
# ir vienāds ar pēdējo ciparu (piemēram, 18961). Skaitļa dalīšana ciparos jāveic skaitliski.

# Programma izveidota: 14.09.2022
# Mainīta: 21.09.22. Uzlabota ieejas datu korektības nodrošināšana

ok=1
while ok== 1 : #lauj atkārtot visu programmu, ja lietotājs beigās ievadīs ciparu 1
   
    num=int(input("Enter a natural number:"))

    while num<=0:  #Nodrošina ieejas datu korektumu
         print("Error! Natural numbers belong to the intveral num>0. Please try again.\n")
         num=int(input("Enter a natural number:")) 

    
    last=num%10
        
    first=num #Izveido skaitļa kopiju, kuru var modificēt, un atļauj izmantot oriģinālo skaitli citās darbībās
    while (first>=10):
        first=first//10
        
            
  
    if first==last:
        print("The first(",first,")and last(",last,")digits of a number(",num,")ARE equal\n")

    else:
        print("The first(",first,")and last(",last,")digits of a number(",num,")AREN'T equal\n")


    ok = int(input("Enter 0 to exit or 1 to continue:\n"))

    if ok !=1:  
       break


     
 #    Ievads   |       Programmas vēlamā reakcija          |                       Rezultāts Python
 # ------------+-------------------------------------------+---------------------------------------------------------------------------
 #     6       |       Paziņojums "Digits ARE equal"       |                            +
 #    464      |       Paziņojums "Digits ARE equal"       |                            +
 # 399999999997|      Paziņojums "Digits AREN'T equal"     |                            +
 #     47      |       Paziņojums "Digits AREN'T equal"    |                            +
 #      0      | Kļūda.Nepieder naturalo skaitļu intervālam|  izdod paziņojumu "Error! Natural numbers belong to the intveral num<=0."     
 #    -98      | Kļūda.Nepieder naturalo skaitļu intervālam|  izdod paziņojumu "Error! Natural numbers belong to the intveral num<=0."

