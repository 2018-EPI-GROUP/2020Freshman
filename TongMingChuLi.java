package cn.sxt.lxy;

import java.sql.Date;
import java.util.*;//导入该包下所有的类。会降低编译速度，但不会降低运行速度。

public class TongMingChuLi{
    public static void main(String[] args) {
        //这里指的是java.sql.Date
        Date now;
        //java.util.Date因为和java.sql.Date类同名，需要完整路径
        java.util.Date  now2 = new java.util.Date();
        System.out.println(now2);
        //java.util包的非同名类不需要完整路径
        Scanner input = new Scanner(System.in);
    }
}