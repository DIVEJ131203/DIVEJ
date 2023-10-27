class LeapYear
{
public static void main(String args[])
{
int y=Integer.parseInt(args[0]);
boolean a;
if(y%4!=0)
{
a=false;
System.out.println("it is a common year"+a);
}
else if(y%100!=0)
{
a=true;
System.out.println(a);
}
else if(y%400!=0)
{
a=false;
System.out.println(a);
}
else
{
a=true;
System.out.println(a);
}}}