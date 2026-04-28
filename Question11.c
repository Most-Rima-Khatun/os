#include<stdio.h>

void solve(){
    int  n, f;
    printf("Enter Number of Pages : \n");
    scanf("%d",&n);

    printf("Enter the number of frames : \n");
    scanf("%d",&f);

    int hit = 0, miss = 0,flag,front = 0;
    int pages[n],frames[f];

    printf("Enter the page references string :\n");

    for(int i = 0; i < n ; i++){
        scanf("%d",&pages[i]);
    }

    printf("Enter the number of frames");
    for(int i = 0; i < f; i++){
        frames[i] = -1;
    }
    printf("\nPages\tFrames\n");

    for(int i = 0; i < n; i++){
        flag = 0;

        for(int j = 0 ; j < f;j++){
            if(frames[j] == pages[i]){
                flag = 1;
                hit++;
                break;
            }
        }

        if(flag == 0){
            frames[front] = pages[i];
            front = (front + 1 ) % f ;
            miss++;
        }

        printf("%d\t",pages[i]);
        for(int k = 0; k < f; k++){
            if(frames[k]!=-1){
                printf("%d ",frames[k]);
            }else{
                printf("%d ",frames[k]);
            }
        }
        printf("\n");
    }
    printf("\n Total page faults = %d",miss);
    printf("\nTotal page hits = %d\n",hit);
}
int main(){
    solve();
    return 0;
}