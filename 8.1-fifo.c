#include <stdio.h>

int i,j,k,np,nf,page[20],frame[20],page_fault,avail;

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

    j=0;

    printf("Ref\tFrames\n");
    for(i=0;i<np;i++){
        printf("%d\t",page[i]);
        avail = 0;

        for(k=0;k<nf;k++){
            if(frame[k]==page[i]){
                avail = 1;
                break;
            }
        }

        if(avail==0){
            page_fault++;
            frame[j] = page[i];
            j = (j+1)%nf;
        }

        for(k=0;k<nf;k++){
            printf("%d\t",frame[k]);
        }
        printf("\n");
    }

    printf("Page faults : %d",page_fault);
}