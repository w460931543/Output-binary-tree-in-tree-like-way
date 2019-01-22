#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<malloc.h>
#include<map>
#include<math.h>
#define LEFT 1
#define RIGHT 0
#define SPACE " "
using namespace std;
multimap<int,int> m;
int flr=-1;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL)
    {
    }
};
TreeNode* createNode()
{
    TreeNode *node;
    int i;
    scanf("%d",&i);
    if(i==0)
        node=NULL;
    else
    {
        node=(TreeNode*)malloc(sizeof(TreeNode));
        node->val=i;
        node->left=createNode();
        node->right=createNode();
    }
    return node;
}
void traversal(TreeNode *node,int floor)
{
    if(node==NULL)
    {
        m.insert(pair<int,int>(floor,0));
        if(floor>flr)
            flr=floor;
        return;
    }
    m.insert(pair<int,int>(floor,node->val));
//    cout<<node->val<<" ";
    traversal(node->left,floor+1);
    traversal(node->right,floor+1);
}
//1 3 7 15 的规律是2    1 0 2 3 0 0 4 0 0
int main()
{
    TreeNode *root=createNode();
    traversal(root,0);
    flr--;
    int k=0,i,j,l,n;
//    cout<<flr<<endl<<endl;
    for(multimap<int,int>::iterator it = m.begin(); it != m.end();)
    {
//        cout<<(*it).first<<" "<<(*it).second<<endl;
        i=0;
        j=pow(2,flr-(*it).first)-1;
        while(i++<j)
            cout<<SPACE;
////          cout<<k<<" "<<(*it).first<<endl;
        l=0,i=0;
        while((*it).first==k&&it!=m.end())
        {
            if(l == pow(2,(*it).first)/2&&0!=(*it).first)
            {
//                cout<<l<<"######"<<endl<<endl;
                while(i++<n-1)
                    cout<<SPACE;
            }
            if((*it).second!=0)
                cout<<(*it).second<<SPACE;
            it++;
            l++;
        }
//
        cout<<endl;
        k++;
        n=j;
    }
    return 0;
}
