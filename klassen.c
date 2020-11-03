#include <stdio.h>

struct person {
    char* vorname;
    char* nachname;
};

void toString(struct person p);

int main (int argc, char *argv[]) {
    struct person a;
    struct person b;

    a.vorname="Maik";
    a.nachname="Proba";

    b.vorname="Hans";
    b.nachname="Müller";

    toString(a);
    toString(b);
}

void toString(struct person p){
    printf("Person: Vorname: %s, Nachname: %s\n", p.vorname, p.nachname);
}
