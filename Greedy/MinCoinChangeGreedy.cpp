vector<int> findMinCoinChange(Int V) {
  vector<int> ans;
  int deno[] = {1,2,5,10,20,50,100,200,500,1000};
  int n=sizeof(deno)/sizeof(int);
  
  for(int i=n-1; i>=0; i--) {
    while(V>=deno[i]) {
      V-=deno[i];
      ans.emplace_back(deno[i]);
    }
  }
  return ans;
}
