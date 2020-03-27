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

unsigned short comp(unsigned short x, int n){
    int know = get(x, n);
    unsigned short temp = 1<<n;
    if (know == 1){
        return x^temp;
    }
    return x|temp;
}

unsigned short set(unsigned short x, int n, int v){
    int know = get(x, n);
    if (know == v){
        return x;
    }
    return comp(x, n);
}

int main(int argc, char** argv){
    if (argc < 2) {
		printf("error\n");
		return 0;
	}
    FILE *fp = fopen(argv[1], "r");
    unsigned short x;
    int r = fscanf(fp, "%hu\n", &x);
    int n;
    int v;
    char func[5];
    r = fscanf(fp, "%s\t%d\t%d\n", func, &n, &v);
    while (r != EOF){
        if (strcmp(func, "get") == 0){
            printf("%d\n", get(x, n));
        }else if (strcmp(func, "comp") == 0){
            x = comp(x, n);
            printf("%d\n", x);
        }else {
            x = set(x, n, v);
            printf("%d\n", x);
        }
        r = fscanf(fp, "%s\t%d\t%d\n", func, &n, &v);
    }
    fclose(fp);
}