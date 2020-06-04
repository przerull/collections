#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include "src/collections/linked_list.h"

template class LinkedList<int>;


class LinkedListTest: public ::testing::Test {
    protected:
        void SetUp() override {
            mylist.append(1);
            mylist.append(2);
            mylist.append(3);
            mylist.append(4);
            mylist.append(5);
        }

        LinkedList<int> mylist;
};

TEST_F(LinkedListTest, TestGetLength) {
    ASSERT_EQ(mylist.get_length(), 5);
}
TEST_F(LinkedListTest, TestCreateFromArray) {
    int my_array[5] = {3, 4, 5, 6, 7};
    LinkedList<int>* newlist = new LinkedList<int>(4, my_array);
    ASSERT_EQ(newlist->get_length(), 4);
    newlist->start_loop();
    int value;
    ASSERT_EQ(newlist->next(&value), true);
    ASSERT_EQ(value, 3);
    ASSERT_EQ(newlist->next(&value), true);
    ASSERT_EQ(value, 4);
    ASSERT_EQ(newlist->next(&value), true);
    ASSERT_EQ(value, 5);
    ASSERT_EQ(newlist->next(&value), true);
    ASSERT_EQ(value, 6);
    ASSERT_EQ(newlist->next(&value), false);
    ASSERT_EQ(value, 6);
    newlist->print();
    delete newlist;
}

TEST_F(LinkedListTest, TestCreateFromInitializer) {
    LinkedList<int>* newlist = new LinkedList<int>({2, 3, 4, 5});
    ASSERT_EQ(newlist->get_length(), 4);
    delete newlist;
}

TEST_F(LinkedListTest, TestPopfirstEmptyList) {
    LinkedList<int> list2;
    int value;
    value = 123;
    ASSERT_EQ(list2.popfirst(&value), status::EMPTY_LIST);
    ASSERT_EQ(value, 123);
}

TEST_F(LinkedListTest, TestPopFirst) {
    int value;
    ASSERT_EQ(mylist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(value, 1);
    ASSERT_EQ(mylist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(value, 2);
    ASSERT_EQ(mylist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(value, 3);
    ASSERT_EQ(mylist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(value, 4);
    ASSERT_EQ(mylist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(value, 5);
    ASSERT_EQ(mylist.popfirst(&value), status::EMPTY_LIST);
    ASSERT_EQ(value, 5);
}

TEST_F(LinkedListTest, TestPopLast) {
    int value;
    ASSERT_EQ(mylist.poplast(&value), status::SUCCESS);
    ASSERT_EQ(value, 5);
    ASSERT_EQ(mylist.poplast(&value), status::SUCCESS);
    ASSERT_EQ(value, 4);
    ASSERT_EQ(mylist.poplast(&value), status::SUCCESS);
    ASSERT_EQ(value, 3);
    ASSERT_EQ(mylist.poplast(&value), status::SUCCESS);
    ASSERT_EQ(value, 2);
    ASSERT_EQ(mylist.poplast(&value), status::SUCCESS);
    ASSERT_EQ(value, 1);
    ASSERT_EQ(mylist.poplast(&value), status::EMPTY_LIST);
    ASSERT_EQ(value, 1);
}


TEST_F(LinkedListTest, TestPrepend) {
    mylist.prepend(-12);
    ASSERT_EQ(mylist.get_length(), 6);
    int value;
    ASSERT_EQ(mylist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(value, -12);
}


TEST_F(LinkedListTest, TestPrependEmpty) {
    LinkedList<int> testlist;
    ASSERT_EQ(testlist.get_length(), 0);
    testlist.prepend(8);
    ASSERT_EQ(testlist.get_length(), 1);
    int value;
    ASSERT_EQ(testlist.popfirst(&value), status::SUCCESS);
    ASSERT_EQ(testlist.get_length(), 0);
    ASSERT_EQ(value, 8);
}

TEST_F(LinkedListTest, TestToArray) {
    int * values;
    ASSERT_EQ(mylist.to_array(&values), status::SUCCESS);
    ASSERT_EQ(values[0], 1);
    ASSERT_EQ(values[1], 2);
    ASSERT_EQ(values[2], 3);
    ASSERT_EQ(values[3], 4);
    ASSERT_EQ(values[4], 5);
    delete [] values;
}


TEST_F(LinkedListTest, TestToArrayEmpty) {
    LinkedList<int> testlist;
    int * values;
    ASSERT_EQ(testlist.to_array(&values), status::EMPTY_LIST);
}
//int main(int argc, char** argv) {
//
//    LinkedList<int>* other_list = new LinkedList<int>();
//
//    other_list->append(2);
//    other_list->append(3);
//    other_list->append(4);
//    other_list->prepend(-1);
//    other_list->prepend(-2);
//    other_list->prepend(-3);
//    other_list->print();
//    int value;
//    other_list->popfirst(&value);
//    std::cout << "value=" << value << std::endl;
//    other_list->popfirst(&value);
//    std::cout << "value=" << value << std::endl;
//    std::cout << "length=" << other_list->get_length()<< std::endl;
//    other_list->poplast(&value);
//    std::cout << "value=" << value << std::endl;
//    std::cout << "length=" << other_list->get_length()<< std::endl;
//    delete other_list;
//
//    LinkedList<std::string>* string_list = new LinkedList<std::string>();
//    string_list->append("a moose");
//    string_list->append("once");
//    string_list->append("bit my sister");
//    string_list->print();
//    delete string_list;
//    //LinkedList__print(other_list);
//    //int value;
//    //LinkedList__popfirst(other_list, &value);
//    //printf("value=%d\n", value);
//    //LinkedList__popfirst(other_list, &value);
//    //printf("value=%d\n", value);
//    //LinkedList__print(other_list);
//    //LinkedList__poplast(other_list, &value);
//    //printf("value=%d\n", value);
//    //LinkedList__print(other_list);
//    //printf("length=%d\n", LinkedList__length(other_list));
//    //LinkedList__destroy(&other_list);
//    //LinkedList last_list;
//    //LinkedList__create(&last_list);
//    //printf("length=%d\n", LinkedList__length(last_list));
//    //LinkedList__destroy(&last_list);
//    return 1;
//}
