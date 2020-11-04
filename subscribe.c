#include <stdio.h>
#include <string.h>

#define TOPLEN 64
#define MESLEN 128

short set_channel(char* topic);

struct channel{
    char topic[TOPLEN];
    
};

struct sublist{

}

int main(){
    char message[MESLEN];
    struct channel channel;

    //1. channel hinzufügen
    char eingabe[TOPLEN];
    scanf("%s\n", eingabe);
    set_channel(eingabe);


    
    //2. Receiver registrieren


    
    return 0;
}

//===============
//SERVER
//1. Setzen des Channel Topics
short set_channel(char* topic){
    struct channel channel;
    sprintf(channel.topic, "%s", topic);
    printf("Channel: %s\n", channel.topic);
    return 1;
}


short subscribe (){

}



    //short set_channel (topic) = 1;  /* Setzen des Channel Topics     */
    //short subscribe () = 2;         /* Receiver registrieren         */
    //short unsubscribe () = 3;       /* Receiver deregistrieren       */
    //short publish (message) = 4;    /* Nachricht an Channel schicken */
    