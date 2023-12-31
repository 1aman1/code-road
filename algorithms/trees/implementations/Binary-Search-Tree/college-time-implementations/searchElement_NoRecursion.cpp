#include<bits/stdc++.h>

using namespace std;

class tNode{
public:
  size_t data;
  tNode* left;
  tNode* right;
  tNode( int item ): data( item )
  {}
};

void levelOrder( tNode* pRoot ){
  queue<tNode*> Q;

  tNode* temp = NULL;
  Q.push( pRoot );
  while( !Q.empty() ){
    temp = Q.front(); Q.pop();

    cout << temp->data << " ";

    if( temp->left )
      Q.push( temp->left );
    if( temp->right )
      Q.push( temp->right );
  }
  while( !Q.empty() ) Q.pop();
  cout << endl;
}


int searchElement( tNode* pRoot , int value ){
  if(!pRoot )
   return 0;
  queue<tNode*> Q;
  tNode* tmp = NULL;
  int checkVar;
  Q.push( pRoot );
  while ( !Q.empty() ){
    tmp = Q.front(); Q.pop();
    if( tmp->data == value )
      return 1;
    if( tmp->left )
      Q.push( tmp->left );
    if( tmp->right )
      Q.push( tmp->right );
  }
  return 0;
}


int main(){

  tNode* root = new tNode(1);
  tNode* newNode1 = new tNode(2);
  tNode* newNode2 = new tNode(3);
  tNode* newNode3 = new tNode(4);
  tNode* newNode4 = new tNode(5);
  tNode* newNode5 = new tNode(6);
  tNode* newNode6 = new tNode(7);
  root->left = newNode1;
  root->right = newNode2 ;
  newNode1->left = newNode3;
  newNode1->right= newNode4;
  newNode2->left = newNode5;
  newNode2->right = newNode6;

  cout << "elements present are: ";
  levelOrder( root );
  cout << "\n\t" << ( (searchElement( root, 4 ) == 1 ? "found" : "notFound"));

  return 0;
}
