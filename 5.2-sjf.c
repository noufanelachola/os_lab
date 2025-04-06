#include <stdio.h>

struct process{
	int pid,at,bt,ct,tat,wt;
} processArray[20], temp;

int i,j,n,time = 0,completed = 0,ind;
float tat,wt;

int main(){

	printf("Enter number of process : ");
	scanf("%d",&n);

	//Read processes
	printf("Enter processes :\n");
	for(i=0;i<n;i++){
		printf("P%d : ",i+1);
		scanf("%d",&processArray[i].pid);
	
		printf("Enter the Arrival Time : ");
		scanf("%d",&processArray[i].at);

		printf("Enter the Burst Time : ");
		scanf("%d",&processArray[i].bt);
	}

	//Sort
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(processArray[i].at > processArray[j].at || (processArray[i].at==processArray[j].at && processArray[i].bt>processArray[j].bt)){
				temp = processArray[i];
				processArray[i] = processArray[j];
				processArray[j] = temp;
			}
		}
	}
	
	
	while(completed < n){
        int shortest = 1e9;
        ind = -1;
    
        for(i=0;i<n;i++){
            if(processArray[i].at <= time && processArray[i].ct == 0){
                if(processArray[i].bt < shortest){
                    shortest = processArray[i].bt;
                    ind = i;
                }
            }
        }
    
        if(ind != -1){
            processArray[ind].ct = time + processArray[ind].bt;
            processArray[ind].tat = processArray[ind].ct - processArray[ind].at;
            processArray[ind].wt = processArray[ind].tat - processArray[ind].bt;
    
            tat += processArray[ind].tat;
            wt += processArray[ind].wt;
    
            printf("Time = %d, PID = %d, CT = %d\n", time, processArray[ind].pid, processArray[ind].ct);
    
            time = processArray[ind].ct;
            completed++;
        } else {
            time++; 
        }
    }
    
	tat = tat/n;
	wt = wt/n;

	//Show processes	
	printf("Answer is :\n ");
	printf("PID\tAt\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",processArray[i].pid,processArray[i].at,processArray[i].bt,processArray[i].ct,processArray[i].tat,processArray[i].wt);
	}

	printf("Avg TAT : %f , Avg WT : %f",tat,wt);

}
