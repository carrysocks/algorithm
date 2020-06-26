#include <iostream>
#include <cstdlib>
using namespace std;
 
class InvaildIndexException{};

template <typename T>
class ListNode{
public:
    T value;
    ListNode<T> *next;
    
    ListNode<T>(): next(nullptr){};
    ListNode<T>(T value1, ListNode<T> *next1): value(value1),next(next1){};
};

template<typename T>
class LinkedList{
public:
    int size;
    ListNode<T> *head;
    
    // 생성자
    LinkedList<T>(): size(0),head(nullptr){};
    
    // 소멸자 
    ~LinkedList<T>(){
        ListNode<T> *t1 = head, *t2;
        while(t1 != nullptr){
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }
    
    void insert(int n, T value){
        try{
            if(n<0 || n>size) throw InvaildIndexException();
            if(n==0) head = new ListNode<T>(value,head);
            else{
                ListNode<T> *dest = head;
                ListNode<T> *newNode = new ListNode<T>(value,dest->next);
                for(int i=0;i<n-1;i++)
                    dest = dest->next;
                dest->next = newNode;//  화살표는 점같은 존재.
            }
            size++;    
        }
        catch(InvaildIndexException){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(1);
        }
    }
    
    void erase(int n){
        try{
            if(n<0 || n>size) throw InvaildIndexException();
            if(n==0){
               ListNode<T> *dest = head->next;
               delete head;
               head = dest;
            }
            else{
                ListNode<T> *dest = head;
                for(int i=0;i<n-1;i++)
                    dest = dest->next;
                delete dest->next;
                dest->next = dest->next->next;
            }
            size--;
        }
        catch(InvaildIndexException){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(1);
        }
    }
    
    int search(T value){
        ListNode<T> *dest = head;
        for(int i=0;i<size;i++){
           if(dest->value == value) return i;
           dest = dest->next;
        }
        return -1;
    }
};

template<typename T>
ostream& operator <<(ostream &out, const LinkedList<T> &LL){ // 원소들을 한 줄에 차례대로 출력
    ListNode<T> *temp = LL.head;
    out << '[';
    for(int i=0; i<LL.size; i++){
        out << temp->value;
        temp = temp->next;
        if(i < LL.size-1) out << ", ";
    }
    out << ']';
    return out;
}

int main(){
    LinkedList<int> LL;
    LL.insert(0, 1); cout << LL << endl;
    LL.insert(1, 2); cout << LL << endl;
    LL.insert(2, 3); cout << LL << endl;
    LL.insert(0, 4); cout << LL << endl;
    LL.insert(0, 5); cout << LL << endl;
    LL.insert(5, 6); cout << LL << endl;
    LL.insert(4, 7); cout << LL << endl;
    LL.insert(1, 8); cout << LL << endl;
    LL.erase(4); cout << LL << endl;
    LL.erase(0); cout << LL << endl;
    LL.erase(5); cout << LL << endl;
    LL.insert(3, 9); cout << LL << endl;
    LL.erase(1); cout << LL << endl;
    LL.insert(1, 10); cout << LL << endl;
}

