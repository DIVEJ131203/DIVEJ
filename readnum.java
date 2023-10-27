import java.util.*;
public class readnum
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
System.out.println("enter an integer,double and char");
int x=in.nextInt();
double y=in.nextDouble();
char c=in.next().charAt(0);
byte b=(byte)x;
int c1=(int)c;
byte d1=(byte)y;
int d2=(int)y;
System.out.println("integer to byte "+b);
System.out.println("character to integer "+c1);
System.out.println("double to byte "+d1);
System.out.println("double to integer "+d2);
}
}





