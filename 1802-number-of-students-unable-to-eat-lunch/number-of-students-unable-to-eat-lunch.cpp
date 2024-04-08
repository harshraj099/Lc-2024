class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      int n=students.size();
     int m=n;
     int ct=0;
     while(students.size()>0 && ct<students.size()){
        if(students[0]==sandwiches[0]){
            students.erase(students.begin(),students.begin()+1);
            sandwiches.erase(sandwiches.begin(),sandwiches.begin()+1);
            ct=0;
        }
        else  {
          students.push_back(students[0]);
            students.erase(students.begin(),students.begin()+1);
            ct++;
        }
     } 
     return students.size();
    }
};