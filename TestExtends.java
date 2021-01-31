package cn.sxt.oo2;

  public class TestExtends {
    public static void main(String[] args) {
        Student s = new Student("高淇",172,"Java");
        s.rest();
        s.study();
        Student lxy = new Student("吕洵佑",180,"java");
    }
}
class Person {
    String name;
    int height;
    public void rest(){
        System.out.println("休息一会！");
    }
}
class Student extends Person {
    String major; //专业
    public void study(){
        System.out.println("在尚学堂，学习Java");
    }
    public Student(String name,int height,String major) {
        //天然拥有父类的属性
        this.name = name;
        this.height = height;
        this.major = major;
    }
}
//1.父类也称作超类、基类、派生类等。

//2.Java中只有单继承，没有像C++那样的多继承。多继承会引起混乱，使得继承链过于复杂，系统难于维护。

//3.Java中类没有多继承，接口有多继承。

//4.子类继承父类，可以得到父类的全部属性和方法 (除了父类的构造方法)，但不见得可以直接访问(比如，父类私有的属性和方法)。

//5.如果定义一个类时，没有调用extends，则它的父类是：java.lang.Object。
