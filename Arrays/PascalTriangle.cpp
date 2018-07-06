vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > b;
    vector<int> t;
    t.push_back(1);
    
    if (A==0) {
        return b;
    }
    
    if (A==1) {
        b.push_back(t);
        return b;
    }
    
    b.push_back(t);
    // cout << b[0][0];
    
    for (int i=1;i<A;i++) {
        vector<int> temp(i+1);
        for(int j=0;j<i+1;j++) {
            if (j==0){
                temp[0] = 1;
            }
            else if (j==i) {
               temp[j] = b[i-1][j-1]; 
            //   cout << temp[j];
            }
            else {
                temp[j] = b[i-1][j] + b[i-1][j-1];
            }
        }
        b.push_back(temp);
    }
    
    return b;
}
