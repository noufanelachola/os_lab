#include <stdio.h>

int main(){
    int i,j,m,n,allocated[20][20],max[20][20],need[20][20],available[20];

    printf("Enter the number of processes : ");
    scanf("%d",&m);

    printf("Enter the number of resources : ");
    scanf("%d",&n);

    printf("Enter the allocation matrix : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("[%d][%d] : ",i+1,j+1);
            scanf("%d",&allocated[i][j]);
        }
    }

    printf("Enter the max matrix : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("[%d][%d] : ",i+1,j+1);
            scanf("%d",&max[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    printf("Enter available matrix : \n");
    for(j=0;j<n;j++){
        printf("[%d] : ",j+1);
        scanf("%d",&available[j]);
    }



    printf("\nAllocation matrix : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",allocated[i][j]);
        }
        printf("\n");
    }
    
    printf("Max matrix : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    
    printf("Need matrix : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }

}