# Aleksandra Dmitruka,ad22069

#B22. Sastādīt programmu, kura reizina un dala racionālus skaitļus, 
#racionālos skaitļus uzdodot kā divu veselu skaitļu pāri (1/3 tiek uzdota kā divi skaitļi 1 un 3). 
#Rezultātam jābūt kā nesaīsināmam daļskaitlim. Risinājumā izmantot funkciju, kas reizina divus racionālus skaitļus un funkciju,
#kas pārveido racionālu skaitli par nesaīsināmu daļskaitli

# Programma izveidota: 21.10.2022




def reiz (a,b,c,d): #Atkarība no padodamo datu secības reizina vai dala racionālus skaitļus (daļas)
    a=a*b
    c=c*d

    return a,c

def nesadal(k,m,n,l): # Aprēķina skaitītāja un saucēja lielāko kopīgo dalītaju,izmantojot Eiklīda algoritmu,un iegūst nesaīsināmo daļskaitli,dalot tos ar LKD
    if k<0:           # Nodrošina ieejas datu korektumu, jo, LKD var apreķināt tikai skaitļu moduļiem t.i. tikai pozitivajiem skaitļiem
        k=-k
    if m<0:
        m=-m

    while(m!=0 and k!=0): #Izmanto Eiklīda algoritmu, lai atrastu LKD
        if k>m:
            k=k%m
        else:
            m=m%k
    m=m+k

    n=n//m
    l=l//m

    return n,l
    




ok=1
while ok== 1 : #lauj atkārtot visu programmu, ja lietotājs beigās ievadīs ciparu 1
   
    numone,denone,numtwo,dentwo=map(int, input("Enter the numerator and denominator of the first the second fraction! Observe the input order and use spaces:").split())


    while denone==0 or dentwo==0:  #Nodrošina ieejas datu korektumu
         print("Error! The denominator of any fraction cannot be zero!\n")
         numone,denone,numtwo,dentwo=map(int, input("Enter the numerator and denominator of the first the second fraction! Observe the input order and use spaces:").split())


    #Papildmainīgaie a,b,c,d ir ievesti, lai izmantotu oriģinālus skaitļus citās darbībās


    a,b=reiz(numone,numtwo,denone,dentwo) #reizina racionālus skaitļus
    c,d=reiz(numone,dentwo,denone,numtwo) #dala racionālus skaitļus


    ##print(a)
    ##print(b)    Starpvērtību parbaude
    ##print(c)
    ##print(d)




    rezone,reztwo=nesadal(a,b,a,b)    #saīsina reizinajumu
    rezthree,rezfour=nesadal(c,d,c,d) #saīsina dalījumu 


    print("The division of fractions",numone,"/",denone,"and",numtwo,"/",dentwo,"is equal to",rezthree,"/",rezfour,)

    print("The multiplication of fractions",numone,"/",denone,"and",numtwo,"/",dentwo,"is equal to",rezone,"/",reztwo,)

    ok = int(input("Enter 0 to exit or 1 to continue:\n")) 

    if ok !=1:  
       break


     
 #        Ievads       |                     Programmas vēlamā reakcija                    |                    Rezultāts C++
 # --------------------+-------------------------------------------------------------------+----------------------------------------------------------------
 #       2 3 4 5       |        "Devision is 5/6  | Multiplication is 8/15"                |                          +
 #      -10 3 6 7      |        "Devision is -35/9 | Multiplication is -20/7"              |                          +
 #      21 -6 2 4      |         "Devision is 7/-1 | Multiplication is 7/-4"               |                          +
 #     -3 -7 -4 -5     |        "Devision is 15/28 | Multiplication is 12/35"              |                          +
 #      -4 0 2 7       |              Kļūda.Nedrīkst dalīt ar nulli                        | izdod paziņojumu "Error!The denominator of any fraction cannot be zero."      
 # 2 1234567 3 12345678| "Devision is 8230452\1234567| Multiplication is 1\2540261108571"  |                          +

