class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q;
        queue<int>Dire;
        queue<int>Radiant;
        for(int i=0; i<senate.length(); i++) { 
            q.push(i);
            if(senate[i]=='R') Radiant.push(i);
            else Dire.push(i);
        } 
        while(q.size()>1){
            if(senate[q.front()]=='X') q.pop(); 
            else if(senate[q.front()]=='R'){
                if(Dire.size()==0) return "Radiant";
                else {
                    senate[Dire.front()]='X';
                    Dire.pop();
                    q.push(q.front());
                    q.pop();
                    Radiant.push(Radiant.front());
                    Radiant.pop();
                }
            }
            else { 
                if(Radiant.size()==0) return "Dire";
                else {
                    senate[Radiant.front()]='X';
                    Radiant.pop();
                    q.push(q.front());
                    q.pop();
                    Dire.push(Dire.front());
                    Dire.pop();
                }
            }
        }
        if(senate[q.front()]=='R') return "Radiant";
        else return "Dire";
    }
};