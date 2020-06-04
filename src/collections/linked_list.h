// for reference
// https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
// https://stackoverflow.com/questions/7186103/how-to-elegantly-implement-a-series-of-functions-in-different-type-versions-usin/7186396#7186396

#ifndef COL_LINKED_LIST_H
#define COL_LINKED_LIST_H

#include <iostream>

enum status: int { SUCCESS, EMPTY_LIST };

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
        size_t length;
        int iteration_counter;
        void init();
    public:
        LinkedList<T>();
        LinkedList<T>(size_t, T*);
        LinkedList<T>(std::initializer_list<T>);
        ~LinkedList<T>();
        void append(T);
        void prepend(T);
        status popfirst(T*);
        status poplast(T*);
        void print();
        size_t get_length();
        void start_loop();
        bool next(T*, size_t*);
        bool next(T*);
        status to_array(T**);
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
void LinkedList<T>::init() {
    this->first_node = NULL;
    this->last_node = NULL;
    this->length = 0;
    this->iteration_counter = 0;
}

template <class T>
LinkedList<T>::LinkedList() {
    this->init();
}


template <class T>
LinkedList<T>::LinkedList(size_t length, T* array) {
    this->init();
    for(size_t i=0;i<length;i++) {
        this->append(array[i]);
    }
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> list) {
    this->init();
    for(T item : list) {
        this->append(item);
    }
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
bool LinkedList<T>::next(T *result, size_t *iteration_counter) {
    bool needs_to_continue;
    if(this->loop_cursor == NULL) {
        needs_to_continue= false;
    } else {
        needs_to_continue = true;
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
bool LinkedList<T>::next(T *result) {
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
status LinkedList<T>::to_array(T** result) {
    size_t length = this->get_length();
    status status;
    if(length == 0) {
        status = status::EMPTY_LIST;
    } else {
        status = status::SUCCESS;
        T* new_array = new T[length];
        this->start_loop();
        size_t position;
        T current_value;
        while(this->next(&current_value, &position)) {
            new_array[position] = current_value;
        }
        *result = new_array;
    }
    return status;
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



template <class T>
status LinkedList<T>::popfirst(T *result) {
    status status;
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
status LinkedList<T>::poplast(T *result) {
    status status;
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
size_t LinkedList<T>::get_length() {
    return this->length;
}

#endif
