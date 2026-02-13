cmake_minimum_required(VERSION 3.10)
project(DSA C)

add_library(array
    Array/DynamicArray.c
)
target_include_directories(array PUBLIC Array)

add_library(graph
    Graph/matrixGraph.c
    Graph/matrixGraphWeighted.c
)
target_include_directories(graph PUBLIC Graph)

add_library(hashTable
    HashTable/hash.c
)
target_include_directories(hashTable PUBLIC HashTable)

add_library(heap
    Heap/maxHeap.c
    Heap/minHeap.c
)
target_include_directories(heap PUBLIC Heap)

add_library(linkedList
    LinkedList/doublyLinkedList.c
    LinkedList/singlyLinkedList.c
)
target_include_directories(linkedList PUBLIC LinkedList)

add_library(queue
    Queue/circularQueue.c
    Queue/linearQueue.c
)
target_include_directories(queue PUBLIC Queue)

add_library(stack
    Stack/dynamicSizeStack.c
    Stack/fixedSizeStack.c
)
target_include_directories(stack PUBLIC Stack)

add_library(tree
    Tree/AVLTree.c
    Tree/binarySearchTree.c
)
target_include_directories(tree PUBLIC Tree)


add_executable(binarySearch
    ArrayImplementation/Searching/binarySearch.c
)
target_link_libraries(binarySearch PRIVATE array)

add_executable(linearSearch
    ArrayImplementation/Searching/linearSearch.c
)
target_link_libraries(linearSearch PRIVATE array)
