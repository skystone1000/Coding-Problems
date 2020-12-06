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

// 28 Maximum Depth of Binary Tree

class Solution{
	public int maxDepth(TreeNode root){
		if(root == null){ return 0; }

		int left = maxDepth(root.left);
		int right = maxDepth(root.right);

		return Math.max(left, right) + 1;
	}
}

// 29 (101. Symmetric Tree)
class Solution{
	public boolean isSymmetric(TreeNode root){
		if(root == null) { return true; }
		return isSymmetric(root.left, root.right);
	}

	public boolean isSymmetric(TreeNode left, TreeNode right){
		if(left == null || right == null){
			return left == right;
		}

		if(left.val != right.val){
			return false;
		}

		return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
	}
}

// 30 (286. Walls & Gates)

class Solution{
	public void wallsAndGates(int[][] rooms){
		for(int i=0;i<rooms.length;i++){
			for(int j=0;j<rooms[i].length;j++){
				if(rooms[i][j] == 0){
					dfs(i, j, 0, rooms);
				}
			}
		}
	}

	publc void dfs(int i, int j, int count, int[][] rooms){
		if(i<0 || i>=rooms.length || j<0 || j>=rooms.length || rooms[i][j] < count){
			return ;
		}

		rooms[i][j] = count;
		dfs(i+1, j, count+1, rooms);
		dfs(i-1, j, count+1, rooms);
		dfs(i, j+1, count+1, rooms);
		dfs(i, j+1, count+1, rooms);
	}
}

 
// 31 (905. Sort Array By Parity)

class Solution{
	public int[] sortArrayByParity(int[] A){
		int index = 0;
		for(int i=0;i<A.length;i++){
			if(A[i] % 2 == 0){
				int temp = A[index];
				A[index] = A[i];
				A[i] = temp;

				index++;
			}
		}

		return A;
	} 
}

// 32 (40. Combination Sum II)

class Solution{
	public List<List<Integer>> combinationSum2(int candidates, int target){
		List<List<Integer>> result = new ArrayList<>();
		Arrays.sort(candidates);
		
		findCombinations(candidates, 0, target, new ArrayList<Integer>(), result);
		return result;
	}

	public void findCombinations(int[] candidates, int index, int target, List<Integer> current, List<List<Integer>> result) {
		if(target == 0) {
			result.add(new ArrayList<>(current));
			return;
		}

		if(target < 0){
			return;
		}

		for(int i=index; i<candidates.length; i++){
			if(i == index || candidates[i] != candidates[i-1]) {
				current.add(candidates[i]);
				findCombinations(candidates, i+1, target-candidates[i], current, result);
				current.remove(current.size() - 1);
			}
		}
	}
}

// 33 (79. Word Search)

class Solution{
	public boolean exist(char[][] board, String word){
		for(int i=0;i<board.length;i++){
			for(int j=0;j<board[i].length;j++){
				if(board[i][j] == word.charAt(0) && dfs(board, i, j, 0, word)){
					return true;
				}
			}
		}
		return false;
	}

	public boolean dfs(char[][] board, int i, int j, int count, String word){
		if(count == word.length()){
			return true;
		}

		if(i<0 || i>=board.length || j<0 || j>=board[i].length 
			|| board[i][j] != word.charAt(count)){
			return false;
		}

		char temp = board[i][j];
		board[i][j] = ' ';
		boolean found = dfs(board, i+1, j, count+1, word)
			|| dfs(board, i-1, j, count+1, word)
			|| dfs(board, i, j+1, count+1, word)
			|| dfs(board, i, j-1, count+1, word);

		board[i][j] = temp;
		return found;
	}
}


// 34 (763. Partition Labels)

class Solution{
	public List<Integer> partitionLabels(String S) {
		List<Integer> partitionLengths = new ArrayList<>();
		int[] lastIndexes = new int[26];
		for(int i=0;i<S.length(); i++){
			lastIndexes[S.charAt(i) - 'a'] = i;
		}

		int i=0;
		while(i<S.length()){
			int end = lastIndexes[S.charAt(i) - 'a'];
			int j = i;
			while(j != end){
				end = Math.max(end, lastIndexes[S.charAt(j++) - 'a'])
			}

			partitionLengths.add(j - i + 1);
			i = j + 1;
		}

		return partitionLengths;
	}
}


// 35 (14. Longest Common Prefix)

class Solution{
	public String longestCommonPrefix(String[] strs){
		String longestCommonPrefix = "";
		if(strs == null || strs.length == 0){
			return longestCommonPrefix;
		}

		int index = 0;
		for(char c:strs[0]/toCharArray()){
			for(int i=1;i<strs.length;i++){
				if(index >= strs[i].length() || c != strs[i].charAt(index)){
					return longestCommonPrefix;
				}
			}

			longestCommonPrefix += c;
			index++;
		}

		return longestCommonPrefix;
	}
}

// =====================================================================
// 36 (78. Subsets)

class Solution{
	public List<List<Integer>> subsets(int[] nums){
		List<List<Integer>> subsets = new ArrayList<>();
		generateSubsets(0, nums, new ArrayList<Integer>(), subsets);

		return subsets;
	}

	public void generateSubsets(int index, int[] nums, List<Integer> current, List<List<Integer>> subsets){
		subsets.add(new ArrayList<>(current));
		for(int i=index; i<nums.length;i++){
			current.add(nums[i]);
			generateSubsets(i+1, nums, current, subsets);
			current.remove(current.size() - 1);
		}
	}
}

// 37 (21. Merger two Sorted Lists)

class Solution{
	public ListNode mergeTwoLists(ListNode l1, Listnode l2){
		ListNode dummy = new ListNode(-1);
		ListNode head = dummy;
		while(l1 != null && l1 != null){
			if(l1.val < l2.val){
				dummy.next = l1;
				l1 = l1.next;
			} else{
				dummy.next = l2;
				l2 = l2.next;
			}
			dummy = dummy.next;
		}

		if(l1 != null){
			dummy.next = l1;
		}else{
			dummy.next = l2;
		}

		return head.next;
	}
}

// =====================================================================
// 38 (322. Coin Change)

class Solution{
	public int coinChange(int[] coins, int amount){
		int[] dp = new int[amount+1];
		Arrays.fill(dp, amount+1);
		dp[0] = 0;
		for(int i=0;i<=amount;i++){
			for(int j=0;j<coins.length;j++){
				if(coins[j] <= i){
					dp[i] = Math.min(dp[i], 1+dp[i-coins[j]]);
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
}


class Solution{
	public int coinChange(int[] coins, int amount){
		// Sorted Initially
		Array.sort(coins);
		int[] dp = new int[amount+1];
		Arrays.fill(dp, amount+1);
		dp[0] = 0;
		for(int i=0;i<=amount;i++){
			for(int j=0;j<coins.length;j++){
				if(coins[j] <= i){
					dp[i] = Math.min(dp[i], 1+dp[i-coins[j]]);
				}
				// Added this else statement
				else{
					break;
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
}

// 39 (199. Binary Tree Right Side View)

class Solution{
	public List<Integer> rightSideView(TreeNode root){
		List<Integer> visibleValues = new ArrayList<>();
		if(root == null){
			return visibleValues;
		}

		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()) {
			int size = queue.size();
			for(int i=0;i<size;i++){
				TreeNode current = queue.remove();
				if(i == size-1){
					visibleValues.add(current.val);
				}
				if(current.left != null){
					queue.add(current.left);
				}
				if(current.right != null){
					queue.add(current.right);
				}
			}
		}

		return visibleValues;
	}
}

// 40 (1119. Remove Vowels from a String)

class Solution{
	public String removeVowels(String S){
		Set<Character> vowels = new hashSet<>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');

		StringBuilder result = new StringBuilder();
		for(char c : S.toCharArray()){
			if(!vowels.contains(c)){
				result.append(c);
			}
		}

		return result.toString();
	}
}

// 41 (64. Minimum Path Sum)

class Solution {
	public int minPathSum(int[][] grid){
		if(grid == null || grid.length == 0){
			return 0;
		}

		int[][] dp = new int[grid.length][grid[0].length];
		for(int i=0; i<dp.length; i++){
			for(int j = 0; j<dp[i].length; j++){
				dp[i][j] += grid[i][j];
				if(i>0 && j>0){
					dp[i][j] += Math.min(dp[i-1][j], dp[i][j-1]);
				} else if(i>0){
					dp[i][j] += [i-1][j];
				} else if(j>0){
					dp[i][j] += dp[i][j-1];
				}
			}
		}

		return dp[dp.length - 1][dp[0].length - 1];
	}
}

// 42 (257. Binary Tree Paths)

class Solution {
	public List<String> binaryTreePaths(TreeNode root){
		List<String> paths = new ArrayList<>();
		if(root == null){
			return paths;
		}

		dfs(root, "", paths);
		return paths;
	}

	public void dfs(TreeNode root, String path, List<String> paths){
		path += root.val;
		if(root.left == null && root.right == null){
			paths.add(path);
			return;
		}
		if(root.left != null){
			dfs(root.left, path + "->",paths);
		}
		if(root.right != null){
			dfs(root.right, path + "->", paths);
		}
	}
}

// 43 (345. Reverse Vowels of a String)

class Solution {
	public String reverseVowels(String s){
		Set<Character> vowels = new HashSet<>();
		vowels.add('A');
		vowels.add('E');
		vowels.add('I');
		vowels.add('O');
		vowels.add('U');
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');

		char[] characters = s.toCharArray();
		int i = 0;
		int j = s.length() - 1;
		while(i<j){
			while(i < j && !vowels.contains(characters[i])){
				i++;
			}
			while(i < j && !vowels.contains(characters[i])){
				j--;
			}

			char temp = characters[i];
			characters[i++] = characters[j];
			characters[j--] = temp;
		}

		return new String(characters);
	}
}

// 44 (160. Intersection of Two Linked Lists)
