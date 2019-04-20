#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Computelps(char* pat, int M, int *lps){//This function is used to calculate the lps. It is very tricky,but it works.
    lps[0]=0;//lps[0] is always equal to 0
    int i = 1, len = 0;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];//If there is no match at all, it will finally go to 0
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return;
}

void Findpat(char* pat, char* txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    Computelps(pat, M, lps);
    int i=0, j=0;// i for txt, j for pat
    while(i<N){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==M){
            printf("Pattern found in %d\n", i-j);
            j = lps[j-1];
        }
        else if(i<N-M+1 && pat[j]!=txt[i]){
            if(j!=0)  j = lps[j-1];
            else i++;
        }
    }
    return;
}

int main(){
    char txt[] = "AAAABAAABA"; 
    char pat[] = "AAAB";
    Findpat(pat, txt);
    return 0; 
}