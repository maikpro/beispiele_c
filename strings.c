#include <stdio.h>

#define MAXSIZE 60

struct Person {
    char* vorname;
    char* nachname;
};

void einfacheAusgabe();
void uebergabeArray(char *array);
char *gebeArrayZurueck();
char* gebeArrayZurueckMitPerson(struct Person *p);


int main(){
    //einfacheAusgabe();
    
    //char array[MAXSIZE];
    //uebergabeArray(&array[0]);

    //char *array2;
    //array2 = gebeArrayZurueck();
    //printf("%s\n", array2);


    struct Person person;
    char *array3;
    person.vorname = "Maik";
    person.nachname = "Proba";

    array3=gebeArrayZurueckMitPerson(&person);
    printf("%s\n", array3);

    return 0;
}

void einfacheAusgabe(){
    char array[MAXSIZE];

    sprintf(array, "%s, %s", "einfacheAusgabe:  Hello", "World");
    printf("%s\n", array);
}

void uebergabeArray(char *array){
    sprintf(array, "%s, %s", "uebergabeArray:  Hello", "World");
    printf("%s\n", array);
}

char* gebeArrayZurueck(){
    char static array[MAXSIZE];
    sprintf(array, "%s, %s", "gebeArrayZurueck:  Hello", "World");
    return(&array[0]);
}

char* gebeArrayZurueckMitPerson(struct Person *p){
    char static array[MAXSIZE];
    sprintf(array, "%s, %s", p->vorname, p->nachname);
    return(&array[0]);
}