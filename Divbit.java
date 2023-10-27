import java.util.Scanner;
public class Divbit
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
System.out.println("enter 1 for multiplication and 2 for division");
int n=in.nextInt();
if(n==1)
{
System.out.println("enter a number to multiply by 2");
int a=in.nextInt();
System.out.println(a<<1);
}
else
{
System.out.println("enter number to divide by 2");
int b=in.nextInt();
System.out.println(b>>1);
}}}

