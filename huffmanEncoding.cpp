#include<iostream>
#include<fstream>
#include<map>
#include<queue>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char chr, int freq, Node* l = 0,Node* r = 0){
        this->ch = chr;
        this->freq = freq;
        this->left = l;
        this->right = r;
    }
};

struct comp{
    bool operator()(Node* &lhs, Node* &rhs){
        return lhs->freq > rhs->freq;
    }
};

void traverseTree(Node* root, map<char,string> & codes, string code=""){
    if(root->left == nullptr){
        codes[root->ch] = code;
        return;
    }

    traverseTree(root->left,codes,code + "0");
    traverseTree(root->right,codes,code + "1");
}

void generateEncodings(string out){
    map<char,int> dict;
    map<char,string> codes;
    for(auto ch : out){
        dict[ch]++;
        codes[ch] = "";
    }

    map<char,int> :: iterator it = dict.begin();
    priority_queue<Node*,vector<Node*>,comp> pq;

    Node *temp = 0;
    while(it != dict.end()){
        temp = new Node(it->first,it->second);
        pq.push(temp);
        cout<<it->first<<" : "<<it->second<<endl;
        it++;
    }

    cout<<"Size of queue : " <<pq.size()<<endl;

    Node * first = 0;
    Node * second = 0;
    Node * third = 0;

    while(pq.size() > 1){
        first = pq.top(); pq.pop();
        second = pq.top(); pq.pop();

        third = new Node(' ',first->freq + second->freq,first,second);
        pq.push(third);
    }

    cout<<"Root : "<<pq.top()->freq<<endl;

    traverseTree(pq.top(),codes);

    
    map<char,string> :: iterator it2 = codes.begin();

    while(it2 != codes.end()){
        cout<<it2->first<<" : "<<it2->second<<endl;
        it2++;
    }

}

int main(int argc, char const *argv[])
{
    /* code */

    string out;

    fstream file;
    file.open("unencodedText.txt",ios::in);

    file>>out;

    // cout<<out;

    out = "Huffman coding is a data compression algorithm.";
    generateEncodings(out);

    return 0;
}
