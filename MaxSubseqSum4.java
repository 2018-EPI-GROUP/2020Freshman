public class MaxSubseqSum4 {
    //方法为分而治之
    //取三个数中的最大数
    public static int Max3(int a,int b,int c){
     if(a>=b&&a>=c)
         return a;
     if(b>=a&&b>=c)
         return b;
     if(c>=a&&c>=b)
         return c;

        return a;
    }
    //分而治之
    public static int DivideAndConquer(int a[],int left,int right){
        //如果分的部分仅有一个元素
        if(left==right){
            if(a[right]>0)
                return a[right];
            else
                return 0;
        }
        //计算左右子列和的最大值
        int center = (left+right)/2;
        int MaxLeftSum = DivideAndConquer(a,left,center);
        int MaxRightSum = DivideAndConquer(a,center+1,right);
        //计算跨界子列和的最大值
        int MaxLeftBorderSum = 0;
        int LeftBorderSum = 0;
        for(int i=center;i>=left;i--){
            LeftBorderSum+=a[i];
            if(LeftBorderSum>MaxLeftBorderSum)
                MaxLeftBorderSum=LeftBorderSum;
        }
        int MaxRightBorderSum = 0;
        int RightBorderSum = 0;
        for(int i=center+1;i<=right;i++){
            RightBorderSum+=a[i];
            if(RightBorderSum>MaxRightBorderSum)
                MaxRightBorderSum=RightBorderSum;
        }
        return Max3(MaxLeftSum,MaxRightSum,MaxRightBorderSum+MaxLeftBorderSum);
    }
    public static int MaxSubseqSum4(int n,int a[]){
        System.out.println(DivideAndConquer(a,0,n-1));
        return DivideAndConquer(a,0,n-1);
    }
    public static void main(String[] args) {
        int a[]={1,4,3};
        MaxSubseqSum4(3,a);
    }
}
