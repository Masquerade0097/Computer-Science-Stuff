vector<int> wave(vector<int> &A) {
    vector<int> p;
    std::sort (A.begin(), A.end());
    
    for (int i=0;i<A.size();i=i+2){
        if (i+1==A.size()) {
            p.push_back(A[i]);
            break;
        }
        p.push_back(A[i+1]);
        p.push_back(A[i]);
    }
    return p;
}

