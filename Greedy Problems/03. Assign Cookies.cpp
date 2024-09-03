class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        //your code goes here
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int l = 0;
        int r = 0;

        int n = Student.size();
        int m = Cookie.size();

        while(l < n && r < m) {
            if(Cookie[r] >= Student[l]) {
                l++;
            }
            r++;
        }

        return l;

    }
};