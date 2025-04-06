#include <stdio.h>
#include <limits.h>

struct process{
	int pid,at,bt,pr,ct,tat,wt;
} processArray[20], temp, pArray[20];

int i,j,n,time = 0,completed = 0,ind,shortest,l=0;
float tat,wt;

void insert();

int main(){

	insert();
	
	while(completed<n){
        ind = -1;
        
        for(i=0;i<n;i++){
            if(processArray[i].at <= time && processArray[i].ct == 0){
                if(ind == -1 || processArray[i].pr < processArray[ind].pr){
                    ind = i;
                }
            }
        }

        if(ind != -1){
            processArray[ind].ct = time + processArray[ind].bt;
            processArray[ind].tat = processArray[ind].ct - processArray[ind].at;
            processArray[ind].wt = processArray[ind].tat - processArray[ind].bt;
            
            time += processArray[ind].bt;
            pArray[l] = processArray[ind];
            tat += processArray[ind].tat;
            wt += processArray[ind].wt;
            l++;
            completed++;
        } else {
            time++;
        }

    }
    
	tat = tat/ (float)n;
	wt = wt/ (float)n;

	//Show processes	
	printf("\nAnswer is :\n ");
	printf("PID\tAt\tBT\tPR\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pArray[i].pid,pArray[i].at,pArray[i].bt,pArray[i].pr,pArray[i].ct,pArray[i].tat,pArray[i].wt);
	}

	printf("Avg TAT : %f , Avg WT : %f",tat,wt);

    printf("\nGantt Chart:\n");
    for(i = 0; i < n; i++){
        printf("| P%d ", pArray[i].pid);
    }
    printf("|\n");

}

void insert(){
    printf("Enter total number of processes : ");
    scanf("%d",&n);

    printf("\nEnter the processes : ");
    for(i=0;i<n;i++){
        printf("\nEnter PID of P%d : ",i+1);
        scanf("%d",&processArray[i].pid);

        printf("Enter arrival time of P%d : ",i+1);
        scanf("%d",&processArray[i].at);

        printf("Enter burst time of P%d : ",i+1);
        scanf("%d",&processArray[i].bt);

        printf("Enter priority of P%d : ",i+1);
        scanf("%d",&processArray[i].pr);
    }
}
