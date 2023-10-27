package com.course.structure;
import java.util.Scanner;

public class Q1{
    public static void main(String args[]) {
        
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Building only, 2. House, 3. School ");
        int input = sc.nextInt();
        if (input == 1) {
            Building b = new Building();
            b.assign();
            b.display();
        }
        else if (input == 2) {
            House h =  new House();
            h.assign();
            h.display();
        }
        else if (input == 3) {
            School s = new School();
            s.assign();
            s.display();
        }
        
    }
}
class Building{
    Scanner sc = new Scanner(System.in);

    double sqFootage;
    int stories;

    public Building() {
        sqFootage = -1;
        stories = -1;
    }

    public void assign() {
        System.out.print("Enter the square footage ");
        sqFootage = sc.nextDouble();
        System.out.print("Enter number of stories ");
        stories = sc.nextInt();
    }

    public void display() {
        System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories);
    }
}

class School extends Building {
    int numOfClassRooms;
    String gradeLev;

    public School() {
        numOfClassRooms = -1;
        gradeLev = "Default";
    }

    public void assign() {
        super.assign();
        System.out.print("Enter number of class rooms ");
        numOfClassRooms = sc.nextInt();
        String dump = sc.nextLine();
        System.out.print("Enter grade level ");
        gradeLev = sc.next();
    }

    public void display() {
        super.display();
        System.out.println("Number of classrooms: "+numOfClassRooms+"\nGrade Level: "+gradeLev);
    }
}

class House extends Building {
    int numOfBed,numOfBath;
    Scanner sc = new Scanner(System.in);

    public House() {
        super();
        numOfBed = -1;
        numOfBath = -1;
    }

    public void assign() {
        super.assign();
        System.out.print("Enter number of bedrooms ");
        numOfBed = sc.nextInt();
        System.out.print("Enter number of bathrooms ");
        numOfBath = sc.nextInt();
    }

    public void display() {
        super.display();
        System.out.println("Number of bedrooms: "+numOfBed+"\nNumber of bathrooms: "+numOfBath);
    }
}
