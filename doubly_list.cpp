//Односвязный список - массив в котором хранится текущее значение элемента массива и адрес следующего элемента
template <typename T> class DoublyList {
private:
    class Node;
    
    unsigned int length = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    class Node {
    public:
        Node* pNext;
        Node* pPrev;
        T data;

        Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
public:

    DoublyList(std::initializer_list<T> args) {
        for (int arg : args) {
            push_back(arg);
        }
    }

    // ~DoublyList() {
    //     clear();
    // }

    void push_back(T data) {
        length++;

        if (head == nullptr) {
            head = new Node(data);
            tail = head;
        } else {
            Node *current = new Node(data);
            tail->pNext = current;
            current->pPrev = tail;
            tail = current;
        }
    }

    void push_front(T data) {
        head = new Node(data, head);

        length++;
    }

    void pop_back() {
        Node* address = tail;
        tail = tail->pPrev;
        delete address;
        tail->pNext = nullptr;


        length--;
    }

    void pop_front() {
        Node *new_head = head->pNext;
        delete head;
        head = new_head;
        length--;
    }

    void insert(T value, int index) {
        int counter;
        Node* new_element = new Node(value);
        Node* element;

        if (index > length/2) {
            element = tail;
            counter = length;

            while (element != nullptr) {
                if (counter == index) {
                    new_element->pNext = element->pNext;
                    new_element->pPrev = element;
                    element->pNext = new_element;
                    new_element->pNext->pPrev = new_element;
                    break;
                }
                element = element->pPrev;
                counter-=1; 
            }
        } else {
            element = head;
            counter = 0;
            
            while (element != nullptr) {
                if (counter == index-1) {
                    new_element->pNext = element->pNext;
                    new_element->pPrev = element;
                    element->pNext = new_element;
                    new_element->pNext->pPrev = new_element;
                    break;
                }
                element = element->pNext;
                counter+=1; 
            }
        }
        
        length++;
    }

    void removeAt(int index) {
        int counter;
        Node* element;
        index++;

        if (index > length/2) {
            element = tail;
            counter = length;

            while (element != nullptr) {
                if (counter == index-1) {
                    Node* del_element = element->pNext;
                    element->pNext = element->pNext->pNext;
                    element->pNext->pPrev = element;
                    delete del_element;
                    break;
                }
                element = element->pPrev;
                counter-=1; 
            }
        } else {
            element = head;
            counter = 0;
            while (element != nullptr) {
                if (counter == index-1) {
                    Node* del_element = element->pNext;
                    element->pNext = element->pNext->pNext;
                    element->pNext->pPrev = element;
                    delete del_element;
                    break;
                }
                element = element->pNext;
                counter+=1; 
            }
        }
        
        length--;
    }

    void clear() {
        while (length) {
            pop_front();
        }
    }

    T& operator[] (const int index) {
        int counter = 0;
        Node* element = head;
        while (element != nullptr) {
            if (counter == index) {
                return element->data;
            }

            element = element->pNext;
            counter+=1;
        }

        throw std::out_of_range("Index out of range");
    }

    int get_length() {
        return length;
    }

    void set_length(unsigned int new_length) {
        for (unsigned int i = length; i < new_length; i++) {
            // std::cout << i << "\n";
            // T data;
            // data.value = 10;
            // data.key = "12";
            // std::cout << data.key << "\n" << data.value << "\n";
            push_back(T());
        }
        length = new_length;
    }

    void print() {
        Node* element = head;
        while (element != nullptr) {
            std::cout << element->data << "\n";
            element = element->pNext;
        }
    }
};

// int main() {
//     DoublyList<float> list = {1,2,3};
//     list.push_back(4);
//     list.push_front(0);

//     list.pop_back();
//     list.pop_front();

//     list.insert(100, 2);
//     list.print();

//     for (int i = 0; i < list.get_length(); i++) {
//         std::cout << list[i] << "\n";
//     }

//    return 0; 
// }