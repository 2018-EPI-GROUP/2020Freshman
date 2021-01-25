package cn.sxt.game;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/*飞机与游戏的主窗口
 */
public class MyGameFrame extends JFrame {
    Image bg =GameUtil.getImage("images/bg.jpg");
    Image plane =GameUtil.getImage("images/plane.png");
    int planeX=250;
    int planeY=250;
    public void paint(Graphics g) {//自动被调用
        g.drawImage(bg, 0, 0, null);
        g.drawImage(plane, planeX, planeY, null);
        planeX++;
    }
        //帮助我们反复的重画窗口！
        class PaintThread extends Thread{
            @Override
            public void run() {
                super.run();
                while (true){
                    System.out.println("last");
                    repaint();//重画
                    try {
                        Thread.sleep(40); //1s = 1000ms
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }

    //初始化窗口
    public void launchFrame(){
        this.setTitle("吕酱的奇妙冒险");
        this.setVisible(true);
        this.setSize(500,500);
        this.setLocation(500,500);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        new PaintThread().start();
    }
    public static void main(String[] args) {
        MyGameFrame f = new MyGameFrame();
        f.launchFrame();
    }
}
