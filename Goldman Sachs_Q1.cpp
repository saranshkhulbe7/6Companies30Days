class Solution{
    
    void quickSort(string &str, int lb, int ub) {
        int low = lb, high = ub;
        int pivot = str[(low + high) / 2];
        
        do {
        while (str[low] < pivot) low++;
        
        while (str[high] > pivot) high--;
        
          if (low <= high) {
            std::swap(str[low], str[high]);
            low++; high--;
          }
        }while (low <= high);
        
        
          if (lb < high) quickSort(str, lb, high);
        
          if (low < ub) quickSort(str, low, ub);
    }
    string sort(string s)
    {
        quickSort(s, 0, s.size()-1);
        return s;
    }
  public:
    vector<vector<string> > Anagrams(vector<string>& sl) {
        //code here
        int n = sl.size();
        vector<vector<string>> V; //ultimate ans
        vector<string> str_or(n, "");
        int itr = 0;
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<n; i++)
        {
            string s = sort(sl[i]);
            if(mp.find(s)==mp.end())
            {
                str_or[itr] = s;
                itr++;
            }
            mp[s].push_back(sl[i]);
        }
        for(int i=0; i<itr; i++)
        {
            V.push_back(mp[str_or[i]]);
        }
        return V;
    }
};
