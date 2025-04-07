#include <stdio.h>

int i,j,k,np,nf,page[20],frame[20],page_fault,avail,time[20],ind,minimum,flag1,flag2,counter;

int lru();

int main(){

    printf("Enter the number of page request : ");
    scanf("%d",&np);

    printf("Enter the page requests : \n");
    for(i=0;i<np;i++){
        printf("[%d] : ",i+1);
        scanf("%d",&page[i]);
    }

    printf("Enter number of frames : ");
    scanf("%d",&nf);

    for(i=0;i<nf;i++){
        frame[i] = -1;
    }

    printf("Ref\tFrames\n");
    for(i=0;i<np;i++){
        printf("%d\t",page[i]);
        flag1 = flag2 = 0;

        for(j=0;j<nf;j++){
            if(page[i] == frame[j]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0){
            for(j=0;j<nf;j++){
                if(frame[j] == -1){
                    frame[j] = page[i];
                    counter++;
                    time[j] = counter;
                    page_fault++;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            k = lru();
            frame[k] = page[i];
            counter++;
            time[k] = counter;
            page_fault++;
        }

        for(k=0;k<nf;k++){
            printf("%d\t",frame[k]);
        }
        printf("\n");

    }

    printf("Page faults : %d",page_fault);
}

int lru(){
    ind = 0;
    minimum = time[0];

    for(k=1;k<nf;k++){
        if(time[k] < minimum){
            ind = k;
            minimum = time[k];
        }
    }
    return ind;
}