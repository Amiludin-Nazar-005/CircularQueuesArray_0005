#include <iostream>
using namespace std;

class queues
{
    int front, rear, max = 5;
    int queue_array[5];

public:
    queues()
    {
        front = -1;
        rear = -1;
    }

    void insert()
    {
        int num;
        cout << "enter a number: ";
        cin >> num;
        cout << endl;
        // cek apakah antrian penuh

        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
            cout << "\nQueue overFlow\n";
            return;
        }
        // cek apakah antrian kosong
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            // jika rear berada di posisi terakhir array kembali ke awal array
            if (rear == max - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
        queue_array[rear] = num;
    }

    void remove()
    {
        // cek apakah antrian kosong
        if (front == -1)
        {
            cout << "queue underFlow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[front] << "\n";
        // cek jika antian hanya memiliki satu elemnt
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // jika elemen yang di hapus berada di posisi terakhir array, kembali ke awal array
            if (front == max - 1)
                front = 0;
            else
                front = front + 1;
        }
    }

    void display()
    {
        int front_position = front;
        int rear_position = rear;
        // cek apakah antian kososng
        if (front == -1)
        {
            cout << "queue is empty\n";
            return;
        }
        cout << "\nElements is teh queue are...\n";
        // jika fornt_position <= rear position, iterasi dari front hingga rear
        if (front_position <= rear_position)
        {
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "   ";
                front_position++;
            }
            cout << endl;
        }
        else
        {
            // jika fornt_position > rear_position ,iterasi dari front hingga ahir array
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "   ";
                front_position++;
            }
            front_position = 0;
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "   ";
                front_position++;
            }
            cout << endl;
        }
    }
};

int main()
{
    queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2. implement deleted operation" << endl;
            cout << "3. display value" << endl;
            cout << "4. exit" << endl;
            cout << "enter your choice (1-4): " << endl;
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "invalid option !!" << endl;
                break;
            }
            }
        }
        catch (exception& e){
            cout << "check for the value entersed" << endl;
        }
    }
    return 0;
}