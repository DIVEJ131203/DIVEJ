#include<stdio.h>
#define capacity 6
int queue[capacity];
int front = -1, rear = -1;
int isFull ()
{
  if ((front == rear + 1) || (front == 0 && rear == capacity - 1))
    {
      return 1;
    }
  return 0;
}
int isEmpty ()
{
  if (front == -1)
    {
      return 1;
    }
  return 0;
}
void enqueue (int value)
{
  if (isFull ())
    printf ("Overflow condition\n");

  else
    {
      if (front == -1)
	front = 0;

      rear = (rear + 1) % capacity;
      queue[rear] = value;
      printf ("%d was enqueued to circular queue\n", value);
    }
}
int dequeue ()
{
  int variable;
  if (isEmpty ())
    {
      printf ("Underflow condition\n");
      return -1;
    }
  else
    {
      variable = queue[front];
      if (front == rear)
	{
	  front = rear = -1;
	}
      else
	{
	  front = (front + 1) % capacity;
	}
      printf ("%d was dequeued from circular queue\n", variable);
      return 1;
    }
}
void print ()
{
  int i;
  if (isEmpty ())
    printf ("Nothing to dequeue\n");
  else
    {
      printf ("\nThe queue looks like: \n");
      for (i = front; i != rear; i = (i + 1) % capacity)
	{
	  printf ("%d ", queue[i]);
	}
      printf ("%d \n\n", queue[i]);

    }
}

int main ()
{

  dequeue ();

  enqueue (10);
  enqueue (20);
  enqueue (30);
  enqueue (40);
  enqueue (50);

  print ();
  dequeue ();
  dequeue ();

  print ();

  enqueue (40);
  enqueue (45);
  enqueue (50);
  enqueue (55);
  print ();

  return 0;
}
