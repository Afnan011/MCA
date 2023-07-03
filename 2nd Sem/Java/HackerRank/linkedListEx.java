public class linkedListEx {

    class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }

    }

    Node head = null;

    public static void main(String[] args) {

        linkedListEx list = new linkedListEx();

        list.insertAtBeg(3);
        list.insertAtBeg(2);
        list.insertAtBeg(1);

        list.insertAtEnd(5);
        list.insertAtEnd(6);

        list.insertAtPos(4, 4);

        list.display();
        list.middleNode();

    }


    private void display() {

        Node ptr = head;

        while (ptr != null) {
            System.out.print(ptr.data + "  ");
            ptr = ptr.next;
        }

        System.out.println();

    }

    private void insertAtBeg(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;
    }


    private void insertAtEnd(int data) {

        Node newNode = new Node(data);

        if (head == null) {
            insertAtBeg(data);
            return;
        }

        Node ptr = head;
        while(ptr.next != null)
        {
            ptr = ptr.next;
        }

        ptr.next = newNode;

    }

    private int countNode()
    {
        int i = 0;
        Node ptr = head;

        while (ptr != null) {
            i++;
            ptr = ptr.next;
        }
        return i;
    }

    private void insertAtPos(int data, int pos) {
    
        if(head == null)
        {
            insertAtBeg(data);
            return;
        }

        Node ptr = head;
        Node prev = null;
        int i = 0;
        int n = countNode();

        if(n < 1 || pos > n)
        {
            System.out.println("Invalid position. ");
            return;
        }


        while (i != pos-1) {
            prev = ptr;
            ptr = ptr.next;
            i++;
        }

        if (prev == null) {
            insertAtBeg(data);
            return;
        }


        Node newNode = new Node(data);

        newNode.next = ptr;
        prev.next = newNode;

    }


    private Node middleNode() {
        Node ptr = head;
        int i = 0;

        while (ptr.next != null) {
            ptr = ptr.next;
            i++;
        }

        int mid = i/2;
        i = 0;
        ptr = head;

        while (i != mid) {
            System.out.print(ptr.data + " ");
            ptr = ptr.next;
            i++;
        }

        return head;
    }
}