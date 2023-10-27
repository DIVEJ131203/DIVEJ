import java.util.Scanner;
public class evaluate
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
System.out.println("enter a and b");
int a=in.nextInt();
int b=in.nextInt();
int o1=(a<<2)+(b>>2);
boolean o2=(b>0);
int o3=(a+b*100)/10;
int o4=(a&b);
System.out.println("(a << 2) + (b >> 2)="+o1);
System.out.println("b > 0= "+o2);
System.out.println("a + b * 100) / 10="+o3);
System.out.println("a & b="+o4);
}}