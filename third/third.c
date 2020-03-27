#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

int get(unsigned short x, int n){
    unsigned short temp = 1<<n;
    if ((x&temp) == temp){
        return 1;
    }
    return 0;
}

bool isPalindrome( unsigned short x){
    int j = 15;
    for (int i = 0; i < 8; i++){
        if (get(x, i) != get(x, j)){
            return false;
        }
        j--;
    }
    return true;
}

int main(int argc, char* argv[]){
    if (argc < 2) {
	    printf("error\n");
		return 0;
    }
    unsigned short x = atoi(argv[1]);
    if (isPalindrome(x)){
        printf("Is-Palindrome");
        return 0;
    }
    printf("Not-Palindrome");
    return 0;
}
