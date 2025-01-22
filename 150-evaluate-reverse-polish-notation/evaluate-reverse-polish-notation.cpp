class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int>s;
      int a,b;
      for(auto it:tokens){
        if(it =="+"){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a+b);
        }
       else if(it == "-"){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b-a);
        }
       else if(it=="*"){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a*b);
        }
       else if(it=="/"){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b/a);
        }

        else{
            s.push(stoi(it));
        }
      }
      return s.top(); 
    }
};