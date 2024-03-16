struct elem{

int num;
elem*next;

};

/**
void add_linked (elem* &first, elem* &last, int n);
Funkcija add_linked(first, last, el) -
pievieno vienvirziena saistītajām sarakstam(first, last) galā mezglu ar veselo skaitli(elementu) n .
*/
void add_linked(elem* &first, elem* &last, int n);



/**
void delete_all_linked(elem* &first);
Funkcija delete_all_linked (elem* &first) izdzēš pirmo elementu un parada nākošo par pirmo kamēr saraksts nav beidzies, tas ir,
atbrīvo saraksta mezgliem piešķirto atmiņu
*/
void delete_all_linked(elem* &first);



/**
void print_linked(elem *first);
Funkcija print_linked(elem *first) izdruka saraksta esošus elementus, sakot ar pirmo elemetu
*/
void print_linked(elem *first);


/**


bool at_least_two(elem *first);
Funkcija at_least_two(elem *first) pārbauda, vai saraksta ir vismaz 2 elementi. Ja ir -atgiež bula tipa mainīgo true, citādi izmet (ar throw) paziņojumu ar skaidrojumu

bool at_least_two(elem *first);
*/

/**
void remove_linked(elem *&first, bool ok);
Funkcija remove_linked(elem *&first, bool ok) apstradā sarakstu tikai tad, ja ok= true(tas ir, sarakstā ir vismaz 2 elementi).Iizmet no saraksta tos elementus, kuru vērtība
mazāka par tam sekojošā elementa vērtību, sakot ar pirmo elementu
*/
void remove_linked(elem *&first);



