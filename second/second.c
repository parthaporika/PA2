#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>


char* count (unsigned short x){
    int cnt = 0;
    unsigned short temp;
    temp = 1;
    while(temp <= x){
        if((x&temp) == temp){
            cnt++;
        }
        temp = temp<<1;
    }
    if (cnt%2 == 0){
        return "Even-Parity";
    }
    return "Odd-Parity";
}

int pairs (unsigned short x){
    unsigned short temp, temp2;
    int cnt = 0;
    temp = 1;
    while (temp < x){
         if ((x&temp) == temp){
             temp2 = temp<<1;
             if ((x&temp2) == temp2){
                 cnt++;
                 temp = temp<<1;
             }
         }
         temp = temp<<1;
    }
    return cnt;
}


int main(int argc, char* argv[]){

    if (argc < 2) {
	    printf("error\n");
		return 0;
    }
    unsigned short x = atoi(argv[1]);
    //printf("%d\n", x);
    printf("%s\t%d", count(x), pairs(x));
}