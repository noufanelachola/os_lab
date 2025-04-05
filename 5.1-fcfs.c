#include <stdio.h>

int i,j,n;

struct Process {
    int pid,at,bt,ct,tat,wt;
} processArray[20],temp;

void insert();
void sort();
void show();

int main(){
    insert();
    sort();
    show();
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
    }
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
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",i+1,temp.pid,temp.at,temp.bt,temp.ct,temp.tat,temp.wt);
    }
}