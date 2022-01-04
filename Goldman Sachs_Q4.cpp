string encode(string s)
{     
  //Your code here 
  int n = s.size();
  int i=0, j=0;
  string str = "";
  while(j<n)
  {
      while(j<n && s[i]==s[j])
      {
          j++;
      }
      str+=(s[i]+to_string(j-i));
      i=j;
  }
  return str;
}     
 
