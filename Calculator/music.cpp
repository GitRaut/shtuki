#include "sup_pup.h"

void change_music(string com){
    if(com == "/mus1"){
        PlaySound( "music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    }
    else if(com == "/mus2"){
        PlaySound( "quiet.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    }
    else if(com == "/mus3"){
        //mciSendString(TEXT("play naruto.wav"), NULL, 0, NULL);
        PlaySound( "naruto.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    }
    else if(com == "/mus4"){
        PlaySound( "quiet2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    }
}
