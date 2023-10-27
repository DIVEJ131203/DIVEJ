import java.util.Scanner;
public class Calc
{
public static void main(String args[])
{
Scanner in= new Scanner(System.in);
char c;
do
{
char op;
float a,b;
System.out.println("enter 2 numbers to operate on");
 a=in.nextFloat();
 b=in.nextFloat();
System.out.println("enter an operator");
op=in.next().charAt(0);
switch(op)
{
case '+':
System.out.println("addition of two numbers is="+(a+b));
break;
case '-':
System.out.println("Subtraction of two numbers="+(a-b));
break;
case '*':
System.out.println("Multiplication of two nums="+(a*b));
break;
case '/':
System.out.println("Division of two nums="+(a/b));
break;
default:
System.out.println("wrong input");
}
System.out.println("enter y to continue and n to terminate");
 c=in.next().charAt(0);
}while(c=='y');
}}
