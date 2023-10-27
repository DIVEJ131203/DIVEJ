import java.util.Scanner;
public class smallest
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
System.out.println("enter 3 numbers");
int a=in.nextInt();
int b=in.nextInt();
int c=in.nextInt();
int y=(a<b && a<c)? a:(b<a && b<c)?b:c;
System.out.println("smallest number="+y);
}}
