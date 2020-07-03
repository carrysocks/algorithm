#include <iostream>

using namespace std;

struct node{
    int value;
    node *next; 
};

class linked_list{
private:
    int size;
    node *head;
    node *tail;
public:
    linked_list(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    
    void insert(int index, T value){
        if(index<0 || index>size) return;
        if(index==0){
             node *new_node = 
        }
        else if(index==size)
        else{
            for(int i=0;i<index-1;i++){
                current_node=current_node->next;
            }
            
        }
        size+=1;
    }
    
    void delete_node(int index){
       if(index<0 || index>=size) return;
       if(index==0){
           node *current_node = head->next;
           delete head;
           head = current_node;
       }
       else{
           node *current_node = head;
           for(int i=0;i<index-1;i++){
               current_node = current_node->next;
           }
           
           current_node->next = current_node->next->next;
       }
       size-=1;
    }
    
    int read(int index){
        node *current_node = head;
        
        for(int i=0;i<index;i++){
            if(current_node==NULL) return NULL;
            current_node = current_node->next;
        }
        
        return current_node->value;
    }
    
    int index_of(int value){
        node *current_node = head;
        int find_index=0;
        
        while(current_node!=NULL){
            if(current_node->value == value) return find_index;
            current_node = current_node->next;
            find_index+=1;
        }
        
        return NULL;
    }
};

int main(){
    linked_list li;
    li.add_node(1);
    li.add_node(3);
    li.delete_node(0);
    cout<<li.read(0);
}
