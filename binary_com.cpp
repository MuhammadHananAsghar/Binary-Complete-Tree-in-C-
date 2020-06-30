// CREATED BY MUHAMMAD HANAN ASGHAR
// PYTHONIST
#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *right;
  Node *left;
}*root;
class BinaryTree{
  public:
  BinaryTree(){
    root = NULL;
  }
  void Insert(int data){
    Node *node = new Node();
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    if(root == NULL){
      root = node;
      cout<<endl<<"Inserted At Root";
    }else{
      Node *temp, *parent;
      temp = root;
      while(temp != NULL){
        parent = temp;
        if(data > temp->data){
          temp = temp->right;
        }else{
          temp = temp->left;
        }
      } 
      if(data>parent->data){
          parent->right = node;
          cout<<endl<<"Inserted At Right";
        }
        else if(data<parent->data){
          parent->left = node;
          cout<<endl<<"Inserted At Left";
        }
    }
  }
  void Display(Node *temp){
    if(temp != NULL){
      Display(temp->left);
      cout<<temp->data<<" - ";
      Display(temp->right);
    }
  }
  Node *findMinimum(Node *temp){
    while(temp->left != NULL){
      temp = temp->left;
    }
    return temp;
  }
  void removeDatas(int data,Node *temp){
    if(temp == NULL){
      return;
    }else if(data > temp->data){
      removeDatas(data, temp->right);
    }else if(data < temp->data){
      removeDatas(data, temp->left);
    }else{
      // For Leaf Nodes
      if(temp->left == NULL && temp->right == NULL){
        delete temp;
        temp = NULL;
      }else if(temp->left==NULL){
        Node *temp2 = root;
        temp = temp->right;
        delete temp2;
      }else if(temp->right == NULL){
        Node *temp2 = root;
        temp = temp->left;
        delete temp2;
      }else{
        Node *temp2 = findMinimum(temp->right);
        temp->data = temp2->data;
        removeDatas(temp2->data, temp->right);
      }
    }
  }
  void removeData(int data){
    removeDatas(data,root);
  }
  void height(Node *temp){
    int count = 0;
    while(temp->left != NULL){
      count++;
      temp = temp->left;
    }
   cout<<endl<<"Height of Tree is Towards Left -> "<<count;
  }
  void height2(Node *temp){
    int count = 0;
    while(temp->right != NULL){
      count++;
      temp = temp->right;
    }
   cout<<endl<<"Height of Tree is Towards Right -> "<<count;
  }
  void Inorder(Node *temp){
    if(temp!=NULL){
      Inorder(temp->left);
      cout<<temp->data<<" - ";
      Inorder(temp->right);
    }
  }
  void Preorder(Node *temp){
    if(temp!=NULL){
      cout<<temp->data<<" - ";
      Preorder(temp->left);
      Preorder(temp->right);
    }
  }
  void Postorder(Node *temp){
    if(temp!=NULL){
      Postorder(temp->left);
      Postorder(temp->right);
      cout<<temp->data<<" - ";
    }
  }
  void Search(int key){
    if (root == NULL){
      cout<<endl<<"No Node Present";
    }
    else{
      Node *temp = root;
      while(temp!=NULL){
        if(key==temp->data){
          cout<<endl<<"Found At Root"<<". Level -> "<<1;
          break;
        }
        else if(key>temp->data){   
          while(temp->right->data != key){
            temp = temp->right;
          }
          cout<<endl<<"Found At Right.";
          break;
        }
        else if(key<temp->data){
          while(temp->left->data != key){
            temp = temp->left;
          }
          cout<<endl<<"Found At Left.";
          break;
        }
        else{
          cout<<endl<<"Node Hani";
          break;
        }
      }
    }
  }
};


int main() {
  BinaryTree b;
  b.Insert(10);
  b.Insert(20);
  b.Insert(5);
  b.Insert(11);
  b.Insert(4);
  b.Insert(3);
  b.Insert(6);
  cout<<endl;
  b.Display(root);
  b.removeData(11);
  cout<<endl;
  b.Display(root);
}
