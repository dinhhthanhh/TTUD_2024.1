#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

int main(){
    queue<int> q;
    vector<string> results;
    string command;
    
    while(true){
        cin>>command;
        if(command == "PUSH"){
            int value;
            cin >> value;
            q.push(value);
        }
        else if(command == "POP"){
            if(!q.empty()){
                results.push_back(to_string(q.front()));
                q.pop();
            } else{
                results.push_back("NULL");
            }
        }
        else if (command == "#"){
            break;
        }
    }
    
    for(const string& results : results){
        std::cout << results << std::endl;
    }
    
    return 0;
}

