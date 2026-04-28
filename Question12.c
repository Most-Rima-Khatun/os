#include<stdio.h>

void solve(){
    int n, f;
    int pos, miss = 0;

    printf("Enter the number of pages :");
    scanf("%d",&n);
    printf("Enter the number of frames :");
    scanf("%d",&f);

    int pages[n],frames[f],time[f];
    printf("Enter pages references string :\n");
    for(int i = 0 ; i < n;i++){
        scanf("%d",&pages[i]);
    }
    
    for(int i = 0; i < f; i++){
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPages\tFrames\n");

    int flag,counter=0;
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < f; j++){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            pos = 0;

            for(int j = 0 ; j < f;j++){
                if(time[j]< time[pos]){
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            miss++;
        }

        printf("%d\t",pages[i]);
        for(int k = 0; k < f;k++){
            if(frames[k] != -1){
                printf("%d ",frames[k]);
            }else{
                printf("-");
            }
        }printf("\n");
    }
    printf("\n Total pages fault : %d\n",miss);
}
int main(){
    solve();
    return 0;
}