#include <stdio.h>

int i,j,n,quantum,completed,time;
float tat,wt;

struct Process {
    int pid,at,bt,rm,ct,tat,wt;
} processArray[20],temp;

void insert();
void sort();
void show();

int main(){
    completed = 0;
    time = 0;
    tat = 0;
    wt = 0;

    insert();
    sort();

    while(completed<n){
        for(i=0;i<n;i++){
            if(processArray[i].rm > 0 && processArray[i].at <= time){
                if(processArray[i].rm > quantum){
                    processArray[i].rm -= quantum;
                    time += quantum;
                }else{
                    time += processArray[i].rm;
                    processArray[i].rm = 0;
                    completed++;
                    processArray[i].ct = time;

                    processArray[i].tat = processArray[i].ct - processArray[i].at;
                    processArray[i].wt = processArray[i].tat - processArray[i].bt;
                    tat += processArray[i].tat;
                    wt += processArray[i].wt;
                }
            }
        }
    }

    tat /= n;
    wt /= n;

    show();
    printf("\nAverage TAT : %f , Average WT : %f\n",tat,wt);
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

        processArray[i].rm = processArray[i].bt;
    }

    printf("Enter the time quantum : ");
    scanf("%d",&quantum);
}

void sort(){
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(processArray[i].at > processArray[j].at){
                temp = processArray[i];
                processArray[i] = processArray[j];
                processArray[j] = temp;
            }
        }
    }
}

void show(){
    printf("\nS.NO\tPID\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++){
        temp = processArray[i];
        printf("\n %d\t%d\t%d\t%d\t%d\t%d\t%d",i+1,temp.pid,temp.at,temp.bt,temp.ct,temp.tat,temp.wt);
    }
}