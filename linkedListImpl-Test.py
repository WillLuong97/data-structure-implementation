#Python program to test out the linked list implementation
import unittest
import linkedListImpl
class linked_list_implementation_test(unittest.TestCase):
    def test_node_structure(self):
        myLinkedList = linkedListImpl.MyLinkedList()
        first_node = linkedListImpl.Node("a")
        myLinkedList.head = self.first_node
        desired_result = "a -> None"
        self.assertEqual(myLinkedList, desired_result)
        
        


        


#Main function
if __name__ == "__main__":
    unittest.main
