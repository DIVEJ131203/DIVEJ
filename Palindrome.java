class Palindrome
import java.util.Scanner;
public static void main(String args[])
{
int rev,sum=0,temp;
 Scanner scan = new Scanner(System.in);
System.out.println("input a number:");
int n=in.nextInt();
temp=n;
while(n>0)
{
r=n%10;
sum=(sum*10)+r;
n=n%10;
}
if(temp==sum)
System.out.println("it is a palindrome");
else
System.out.println("it is not a palindrome");
}
}