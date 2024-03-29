#include<stdio.h>


int minimumSum(int* nums, int numsSize) {
    int *numsgroup = (int*)malloc(sizeof(int) * numsSize);
    for(int i=0;i<numsSize;i++){
        numsgroup[i]=150;
    }
    int left,right;
    int leftmin,rightmin;
    int no=1;
    int min=150;
    int flag=0;
    int flagl=0;//leftmin flag
    int flagr=0;//rightmin flag

    for(no=1;no<numsSize-1;no++){
        leftmin=nums[no];
        rightmin=nums[no];
        for(left=0;left<no;left++){
            if(nums[left]<nums[no]){
                if(nums[left]<leftmin){
                    leftmin=nums[left];
                    flagl=1;
                }
            }
        }
        for(right=no+1;right<numsSize;right++){
            if(nums[right]<nums[no]){
                if(nums[right]<rightmin){
                    rightmin=nums[right];
                    flagr=1;
                }
            }
        }
        if (flagl==1&&flagr==1)
        {
            numsgroup[no]=leftmin+rightmin+nums[no];
        }else{
            numsgroup[no]=150;
        }
    }
    for(no=1;no<numsSize-1;no++){
        if(numsgroup[no]!=150){
            flag=1;
            break;
        }
    }
    if(flag==0){   
        return -1;
    }else{
        for(no=1;no<numsSize-1;no++){
            if(min>numsgroup[no]){
                min=numsgroup[no];
            }
        }
    }
    free(numsgroup);
    return min;
}