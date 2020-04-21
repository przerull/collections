#include <string>
#include <iostream>
#include "linked_list.h"
//#include <fructose/fructose.h>


//struct simpletest : public fructose::test_base<simpletest> {
//    void test_get_length(const std::string& test_name) {
//        LinkedList<int> mylist;
//        mylist.append(1);
//        mylist.append(2);
//        mylist.append(3);
//        mylist.append(4);
//        mylist.append(5);
//        fructose_assert(mylist.get_length() == 5);
//    }
//};


int main(int argc, char** argv) {
    //simpletest tests;
    //tests.add_test("test_get_length", &simpletest::test_get_length);
    //tests.run(argc, argv);
    LinkedList<int> mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.append(4);
    mylist.append(5);
    mylist.print();

    LinkedList<int>* other_list = new LinkedList<int>();

    other_list->append(2);
    other_list->append(3);
    other_list->append(4);
    other_list->prepend(-1);
    other_list->prepend(-2);
    other_list->prepend(-3);
    other_list->print();
    int value;
    other_list->popfirst(&value);
    std::cout << "value=" << value << std::endl;
    other_list->popfirst(&value);
    std::cout << "value=" << value << std::endl;
    std::cout << "length=" << other_list->get_length()<< std::endl;
    other_list->poplast(&value);
    std::cout << "value=" << value << std::endl;
    std::cout << "length=" << other_list->get_length()<< std::endl;
    delete other_list;

    LinkedList<std::string>* string_list = new LinkedList<std::string>();
    string_list->append("a moose");
    string_list->append("once");
    string_list->append("bit my sister");
    string_list->print();
    delete string_list;
    //LinkedList__print(other_list);
    //int value;
    //LinkedList__popfirst(other_list, &value);
    //printf("value=%d\n", value);
    //LinkedList__popfirst(other_list, &value);
    //printf("value=%d\n", value);
    //LinkedList__print(other_list);
    //LinkedList__poplast(other_list, &value);
    //printf("value=%d\n", value);
    //LinkedList__print(other_list);
    //printf("length=%d\n", LinkedList__length(other_list));
    //LinkedList__destroy(&other_list);
    //LinkedList last_list;
    //LinkedList__create(&last_list);
    //printf("length=%d\n", LinkedList__length(last_list));
    //LinkedList__destroy(&last_list);
    return 0;
}
