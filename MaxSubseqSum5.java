public class MaxSubseqSum5 {
    //此方法为线性处理
    public static int LinearMethod(int a[],int N){
        int ThisSum=0;
        int MaxSum=0;
        for(int i=0;i<N;i++){
            ThisSum+=a[i];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
            else if(ThisSum<0)
                ThisSum=0;
        }
        System.out.println(MaxSum);
        return MaxSum;
    }

    public static void main(String[] args) {
        int a[]={1,-1,6};
        int N=3;
        LinearMethod(a,N);
    }
}
