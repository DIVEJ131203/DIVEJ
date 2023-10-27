import java.util.Scanner;
public class NumberCheck
{
  public static void main(String args[])
{
  int countP=0;
  int countN=0;
  int count=((0;
  {
    int[] arr= new int[10];
    Scanner scan = new Scanner(System.in)
    
    System.ot.println("Enter 10 Numbers: ");
    for(i=0;i<10;i++)
     {
       if (arr[i]<0)
       countN++
       else if(arr[i]>0)
       countP++
       else
       count++
     }

System.out.println("\nTOATAL POSITIVE NUMBER:"+countP);
System.out.println("\nTOATAL NEGATIVE NUMBER:"+countN);
System.out.println("\nTOATAL 0 NUMBER:"+count);
}