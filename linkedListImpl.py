# Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

# Implement these functions in your linked list class:

# get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
# addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
# addAtTail(val) : Append a node of value val to the last element of the linked list.
# addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
# deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 

#Node structure:
class Node:
    def __init__(self, data):
        self.data = data    #value to store the data of the Node
        self.next = None    #variable to point at the next element in the Linked List

    # #TThis function to display a more detailed data values of the Node
    # def __repr__(self):
    #     return self.data

class MyLinkedList:

    def __init__(self):
        """
        Initializing the head node:
        """
        self.head = None
    # #to display the element more effectively
    # def __repr__(self):
    #     node = self.head
    #     listOfNodes = []
    #     #traverse through the linked list and print element out if it is not none
    #     while node is not None:
    #         listOfNodes.append(node.data)
    #         node = node.next

    #     listOfNodes.append("None")
       
    #     return " -> ".join(listOfNodes)
    
    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        count = 0 #create a count variable to count the index within the list. 
        retVal = 0
        current = self.head #the current element will start at the head of the linked list
        #loop through the linked list from head to tail
        while current is not None:
            if count == index:      
                retVal = current.data
            count += 1
            current = current.next

        return retVal


    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        # create a temporary Node with the data value to be added into the list
        temp_node = Node(val)
        #inserting element into the head node
        
        temp_node.next = self.head
        self.head = temp_node

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        #create a new node that will hold the value needed to pass in
        newNode = Node(val)
        # if the list is empty, then we will just add the element in as a head node
        if (self.head == None):
            self.head = newNode
            return
        #loop through the linked list from head and to its tail and add element to the linked list at the end
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = newNode


    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        #Create a node structrue of the new element to be added into the linked list
        new_node = Node(val)
        count = 0 #create a count variable to count the index within the list. 
        current = self.head #the current element will start at the head of the linked list
        #loop through the linked list from head to tail
        while current is not None:
            if count == index -1 :   
                current.next = new_node    #the pointer of the deleted data will also point to the node after your immediate node in the linked list.
                new_node.next = current.next.next
            count += 1
            current = current.next

        

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        count = 0 #create a count variable to count the index within the list. 
        current = self.head #the current element will start at the head of the linked list
        #loop through the linked list from head to tail
        while current is not None:
            if count == index:   
                 #Delete an the element at the current index
                current.data = current.next.data    #the current data will be overrwritten with data from the next node
                current.next = current.next.next    #the pointer of the deleted data will also point to the node after your immediate node in the linked list.
            count += 1
            current = current.next

    #Function to print out each element in the linked list
    def printList(self):
        #create a temp node that start from the head
        temp = self.head
        #loop through the linked list from head to tail and print each element out
        while (temp):
            print (temp.data) #print the data
            temp = temp.next #iterate to the next element

#driver code to run the function
def main():
    linked_list = MyLinkedList()
    linked_list.addAtHead(4)
    linked_list.addAtHead(5)
    linked_list.addAtHead(6)
    linked_list.addAtTail(10)
    linked_list.addAtTail(11)
    linked_list.addAtTail(12)
    linked_list.deleteAtIndex(3)
    linked_list.addAtIndex(5, 3)
    

    linked_list.printList()
    

main()


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)