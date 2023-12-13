/*5A) 
Implement Circular Queue using Array. Perform following operations on it:
	Insertion  b) Deletion  c) Display d) Check Queue Full Condition
*/


#include<iostream>

using namespace std;

class CircularQueue {
  	private:
  		int front;
  		int rear;
  		int arr[5];
		int itemCount;
  		
		public:
  		CircularQueue() 
		{
      		front = -1;
      		rear = -1;
      		for (int i = 0; i < 5; i++) 
        		arr[i] = 0;
      	}  
  	bool isFull(); 
  	void enqueue(int val); 
  	int  dequeue();
  	void display(); 
	bool isEmpty();

};
int main() 
{
  	CircularQueue q1;
  	int value, option;

  	do{
    	cout<<"\n Operations on Queue ";
    	cout << "1. Enqueue()" << endl;
    	cout << "2. Dequeue()" << endl;
    	cout << "3. isFull()" << endl;
    	cout << "4. display()" << endl;
    	cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    	cin >> option;

    	switch (option) 
		{
    		case 0:
      			break;
    		case 1:
      			cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      				cin >> value;
      			q1.enqueue(value);
      			break;
    		case 2:
      			cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
      			break;
            case 3:
      			if (q1.isFull())
        			cout << "Queue is Full" << endl;
      			else
        			cout << "Queue is not Full" << endl;
      			break;
            case 4:
      			cout << "Display Function Called - " << endl;
      			q1.display();
      			break;
            default:
      			cout << "Enter Proper Option number " << endl;
    	}

  	} while (option != 0);

  	return 0;
}

bool CircularQueue::isFull()
	{
    	if ((rear + 1) % 5 == front)
      		return true;
   		else
      		return false;
  	}

void CircularQueue::enqueue(int val)
  	{
    	if (isFull()) 
		{
 	    	cout << "Queue full" << endl;
   		  	return;
    	} 
		else if (isEmpty()) 
		{
     		rear = 0;
      		front = 0;
     		arr[rear] = val;
    	} 
    	
		else 
		{
      		rear = (rear + 1) % 5;
      		arr[rear] = val;

   		}
  	}

//pop element from front	
int CircularQueue::dequeue()
	{
    	int x = 0;
    	if (isEmpty()) 
		{
      		cout << "Queue is Empty" << endl;
      		return x;
   	 	} 
   	 	
		else if (rear == front) 
		{
      		x = arr[rear];
      		rear = -1;
      		front = -1;
			itemCount--;
      		return x;
    	} 
		
		else 
		{
      		cout << "front value: " << front << endl;
      		x = arr[front];
      		arr[front] = 0;
      		front = (front + 1) % 5;
			itemCount--;
      		return x;
    	}
  	}

void CircularQueue::display()
	{
    	cout << "All values in the Queue are - " << endl;
    	for (int i = 0; i < 5; i++) 
      		cout << arr[i] << "  ";
    
	}

bool CircularQueue::isEmpty() {
    return (front == -1 && rear == -1);
}

	
	/*Algorithm:




1. **Initialization**
   - Initialize front and rear as -1.
   - Create an array of fixed size to store the elements.

2. **isFull() Function**
   - Check if ((rear + 1) % size) is equal to front.
   - If true, return true (Queue is full).
   2. If rear != max - 1, then rear will be incremented to the mod(maxsize) and the new value will be
inserted at the rear end of the queue.
3. If front != 0 and rear = max - 1, then it means that queue is not full therefore, set the value of rear to
0 and insert the new element there.
   - Otherwise, return false.

3. **isEmpty() Function**
   - Check if front and rear are both -1.
   - If true, return true (Queue is empty).
   - Otherwise, return false.

4. **enqueue() Function**
   - Check if the queue is full using the isFull() function.
     - If full, display "Queue full" and return.
   - Check if the queue is empty using the isEmpty() function.
     - If empty, set front and rear to 0 and insert the value at the rear position.
   - If not empty, increment the rear circularly and insert the value at the new rear position.
   Step 1: if (rear+1) %MAX = front
Write �OVERFLOW "

Step2: [End Of if]
Step 3: if Front = -1 and Rear = -1
i. set front = rear= 0
ii. else if rear = MAX - 1 and front ! = 0
set rear = 0
iii. else
Step 4: end if
1.set rear= (rear + 1) % MAX
Step 5: set QUEUE[rear] = VAL
Step 6: Exit

5. dequeue() Function
.
   To delete an element from the circular queue, we must check for the three following conditions.
1. If front = -1, then there are no elements in the queue and therefore this will be the case of an underflow
condition.
2. If there is only one element in the queue, in this case, the condition rear = front holds and therefore, both
are set to -1 and the queue is deleted completely.
3. If front = max -1 then, the value is deleted from the front end the value of front is set to 0.
4. Otherwise, the value of front is incremented by 1 and then delete the element at the front end.

6. display() Function
   - Iterate through the array and print all elements.

7. Main Function
   - Create an instance of the CircularQueue class.
   - Use a do-while loop to display the menu and perform operations until the user chooses to exit.
   - Inside the loop, use a switch-case structure to perform the selected operation:
     - Enqueue: Take input, call enqueue() method.
     - Dequeue: Call dequeue() method and display the dequeued value.
     - isFull: Call isFull() method and display whether the queue is full or not.
     - display: Call display() method to print all elements.
     - Default: Display an error message for an invalid option.
   - Exit the loop and the program when the user chooses option 0.
*/
	
