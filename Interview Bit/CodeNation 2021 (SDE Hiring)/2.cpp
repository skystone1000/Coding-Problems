vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    int maxBit;
    vector<int> ansVec;

    int maxEle = *max_element(A.begin(), A.end());
    if(maxEle == 0){
    	int bsize = B.size();

    	for(int i=0;i<bsize;i++)
    		ansVec.push_back(2);
    	return ansVec;
    }

    maxBit = log2(maxEle);
    int count = 0;
    int total[maxBit+1][n+1];
    for(int i=0;i<maxBit;i++){
    	total[i][0] = 0;
    }

    while(count <= maxBit){
	    total[count][1] = A[0]&1;
	    for(int i=1;i+1<=n;i++){
		    total[count][i+1] = total[count][i] + (A[i] & 1);
		    A[i] = A[i] >> 1;
	    }
	    A[0] = A[0] >> 1;
	    count++;
    }

    int m = B.size();
    
    for(int i=0;i<m;i++){
    	int left = B[i][0];
    	int right = B[i][1];
    	right++;
    	left++;

    	int maxEle = -1, ans = 1;
    	for(int i=0;i<=maxBit;i++){
    		maxEle = max( total[i][right] - total[i][left-1] , maxEle);
    	}

    	if(maxEle >= 2){
    		ans = 0;
    	}else if(maxEle == 0){
    		ans = 2;
    	}

    	ansVec.push_back(ans);

    }

    return ansVec;
}
