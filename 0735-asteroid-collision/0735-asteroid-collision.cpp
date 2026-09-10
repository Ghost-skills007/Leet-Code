class Solution {
public:
    typedef int ll ; 
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<ll> s ; 

        for(ll i = 0 ; i<asteroids.size() ; i++){
       
            if(asteroids[i] < 0){
               if(s.size() == 0){
                 s.push(asteroids[i]) ; 
               }
               else{
                  ll k = asteroids[i] ; 
                  while(s.size() != 0 && s.top() > 0 ){
                      ll gh = s.top() ;
                      s.pop() ; 
                      if(abs(gh) > abs(k)){
                        s.push(gh) ; 
                        k = INT_MAX ;
                        break;
                      }
                      else if(abs(gh) < abs(k)){
                        continue ;  
                      }
                      else{
                        k = INT_MAX ; 
                        break;
                      }
                  }

                  if(k != INT_MAX && k<0){
                    s.push(k) ; 
                  } 
               }
            } 
            else {
              s.push(asteroids[i]) ; 
            }   
        }

        vector<ll> ans ; 
        while(s.size() != 0){
            ll h = s.top() ; 
            s.pop() ; 
            ans.push_back(h) ; 
        }
        
        reverse(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};