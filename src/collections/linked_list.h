// for reference
// https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
// https://stackoverflow.com/questions/7186103/how-to-elegantly-implement-a-series-of-functions-in-different-type-versions-usin/7186396#7186396

#ifndef COL_LINKED_LIST_H
#define COL_LINKED_LIST_H

#include <iostream>

template <class T>
class Node {
    public:
        T value;
        Node * next_node;
        Node * previous_node;
        Node(T);
        ~Node();
        void init(T);
};

template <class T>
class LinkedList {
    private:
        Node<T> *first_node;
        Node<T> *last_node;
        Node<T> *loop_cursor;
        int length;
        int iteration_counter;
    public:
        LinkedList<T>();
        ~LinkedList<T>();
        void append(T);
        void prepend(T);
        T popfirst(int*);
        T poplast(int*);
        void print();
        int get_length();
        void start_loop();
        int next(T*, int*);
        int next(T*);
        T* to_array();
};





template <class T>
Node<T>::Node(T value) {
    this->init(value);
}

template <class T>
void Node<T>::init(T value) {
    this->value = value;
    this->next_node = NULL;
    this->previous_node = NULL;
}

template <class T>
Node<T>::~Node() {
    this->next_node = NULL;
    this->previous_node = NULL;
}


template <class T>
LinkedList<T>::LinkedList() {
    this->first_node = NULL;
    this->last_node = NULL;
    this->length = 0;
    this->iteration_counter = 0;
}


template <class T>
void LinkedList<T>::append(T value) {
    Node<T> *new_node;
    new_node = new Node<T>(value);
    if(this->first_node == NULL) {
        this->last_node = new_node;
        this->first_node = new_node;
    } else {
        new_node->previous_node = this->last_node;
        this->last_node->next_node = new_node;
        this->last_node = new_node;
    }
    this->length = this->length + 1;
}

template <class T>
void LinkedList<T>::prepend(T value) {
    Node<T> *new_node;
    new_node = new Node<T>(value);
    if(this->first_node == NULL) {
        this->last_node = new_node;
        this->first_node = new_node;
    } else {
        new_node->next_node= this->first_node;
        this->first_node->previous_node = new_node;
        this->first_node = new_node;
    }
    this->length = this->length + 1;
}

template <class T>
void LinkedList<T>::start_loop() {
    this->iteration_counter = 0;
    this->loop_cursor = this->first_node;
}

template <class T>
int LinkedList<T>::next(T *result, int *iteration_counter) {
    int needs_to_continue;
    if(this->loop_cursor == NULL) {
        needs_to_continue= 0;
    } else {
        needs_to_continue = 1;
        if(iteration_counter != NULL) {
            *iteration_counter = this->iteration_counter;
        }
        if(result != NULL) {
            *result = this->loop_cursor->value;
        }
        this->loop_cursor = this->loop_cursor->next_node;
        this->iteration_counter = this->iteration_counter + 1;
    }
    return needs_to_continue;
}

template <class T>
int LinkedList<T>::next(T *result) {
    return this->next(result, NULL);
}

template <class T>
void LinkedList<T>::print() {
    T current_value;
    this->start_loop();
    while(this->next(&current_value)) {
        std::cout << current_value;
        std::cout << "->";
    }
    std::cout << "\n";
}

template <class T>
T* LinkedList<T>::to_array() {
    T * result;
    result = (T*)malloc(sizeof(T) * this->get_length());
    T current_value;
    int position;
    this->start_loop();
    while(this->next(&current_value, &position)) {
        result[sizeof(T) * position] = current_value;
    }
    return result;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *current_node;
    Node<T> *next_node;
    this->last_node = NULL;
    if(this->first_node != NULL) {
        current_node = this->first_node;
        while(current_node != NULL) {
            next_node = current_node->next_node;
            delete current_node;
            current_node = next_node;
        }
    }
}


enum status: int { SUCCESS, EMPTY_LIST };

template <class T>
T LinkedList<T>::popfirst(int *result) {
    int status;
    if(this->first_node != NULL) {
        Node<T>* first_node;
        first_node = this->first_node;
        status = status::SUCCESS;
        if(first_node->next_node != NULL) {
            first_node->next_node->previous_node = NULL;
            this->first_node = first_node->next_node;
        } else {
            this->first_node = NULL;
            this->last_node = NULL;
        }
        *result = first_node->value;
        delete first_node;
        this->length = this->length - 1;
    } else {
        status = status::EMPTY_LIST;
    }
    return status;
}

template <class T>
T LinkedList<T>::poplast(int *result) {
    int status;
    if(this->last_node!= NULL) {
        Node<T>* last_node;
        last_node = this->last_node;
        status = status::SUCCESS;
        if(last_node->previous_node != NULL) {
            last_node->previous_node->next_node = NULL;
            this->last_node = last_node->previous_node;
        } else {
            this->first_node = NULL;
            this->last_node = NULL;
        }
        *result = last_node->value;
        delete last_node;
        this->length = this->length - 1;
    } else {
        status = status::EMPTY_LIST;
    }
    return status;
}

template <class T>
int LinkedList<T>::get_length() {
    return this->length;
}

#endif
