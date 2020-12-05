// 22 Merge K Sorted Lists

class Solution {
	public ListNode mergeKLists(ListNode[] lists){
		PriorityQueue<Integer> minHeap = new PriorityQueue<>();
		for(ListNode head : lists) {
			while(head != null) {
				minHeap.add(head.val);
				head = head.next;
			}										
		}							
										
		ListNode dummy = new ListNode(-1);
		ListNode head = dummy;
		while(!miHeap.isEmpty()) {														
			head.next = new ListNode(minHeap.remove());									
			head = head.next;						
		}					
		
		return dummy.next;
	}
}

// 23 Grouped Anagrams

class Solution {
	public List<List<String>> groupedAnagrams(String[] strs) {
		List<List<String>> groupedAnagrams = new ArrayList<>();
		HashMap<String, List<String>> map = new HashMap<>();
		for(String current: strs) {
			char[] characters = current.toCharArray();
			Arrays.sort(characters);
			String.sorted = new String(characters);
			if(!map.containskey(sorted)) {
				map.put(sorted, new ArrayList<>());
			}
			map.get(sorted).add(current);
		}

		groupedAnagrams.addAll(map.values());
		return groupedAnagrams;
	}
}

// 24 Unique Paths

class Solution {
	public int uniquePaths(int m,int n) {
		int[][] dp = new int[m][n];
		for(int i = 0; i < dp.length; i++) {
			dp[i][0] = 1;
		}
		for(int i = 0; i < dp[0].length; i++) {
			dp[0][i] = 1;
		}

		for(int i = 1; i < dp.length; i++) {
			for(int j=1; j<dp[i].length; j++) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}

		return dp[m-1][n-1];
	}
}

// 25 House Robber

class Solution {
	public int rob(int[] nums) {
		if(nums == null || nums.length == 0) { return 0; }
		if(nums.length == 1) { return nums[0]; }
		if(nums.length == 2) { return Math.max(nums[0], nums[1]); }

		int []dp = new int[nums.length];
		dp[0] = nums[0];
		dp[1] = Math.max(nums[0], nums[1]);
		for(int i = 2 ; i < dp.length ; i++) {
			dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
		}

		return dp[nums.length - 1];		
	}
}

// 26 Path Sum 2

class Solution {
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		List<List <Integer>> paths = new ArrayList<>();
		findPaths(root, sum, new ArrayList<Integer>(), paths);
		retunrn paths;
	}

	public void findPaths(TreeNode root, int sum, List<Integer> current, List<List<Integer>> paths){
		if(root == null){ return; }

		current.add(root.val);
		if(root.val == sum && root.left == null && root.right == null){
			paths.add(current);
			return;
		}

		findPaths(root.left, sum-root.val, new ArrayList<Integer>(current), paths);
		findPaths(root.right, sum-root.val, new ArrayList<Integer>(current), paths);
	}
}

// 27 Same Tree

class Solution{
	public boolean isSameTree(TreeNode p, TreeNode q){
		if(p==null && q==null) {
			return true;
		} else if(p==null || q==null){
			return false;
		} else if(p.val != q.val){
			return false;
		} else{
			return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
		}
	}
}