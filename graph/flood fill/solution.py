class Solution:
	def floodFill(self, image, sr, sc, newColor):
	    def dfs(image,srow,scol,initial,visited,newcolour,forrow,forcol):
	        image[srow][scol]=newcolour
	        for i in range(4):
	            n=srow+forrow[i]
	            m=scol+forcol[i]
	            if n>=0 and n<len(image) and m>=0 and m<len(image[0]) and image[n][m]==initial and visited[n][m]==0:
	                visited[n][m]=1
	                dfs(image,n,m,initial,visited,newcolour,forrow,forcol)
		initial=image[sr][sc]
		visited=[[0 for i in range(len(image[0]))]for i in range(len(image))]
		forrow=[-1,0,1,0]
		forcol=[0,1,0,-1]
		dfs(image[:],sr,sc,initial,visited,newColor,forrow,forcol)
		return image[:]

#{ 
 # Driver Code Starts
import sys
sys.setrecursionlimit(10**7)
if __name__ == '__main__':

	T=int(input())
	for i in range(T):
		n, m = input().split()
		n = int(n)
		m = int(m)
		image = []
		for _ in range(n):
			image.append(list(map(int, input().split())))
		sr, sc, newColor = input().split()
		sr = int(sr); sc = int(sc); newColor = int(newColor);
		obj = Solution()
		ans = obj.floodFill(image, sr, sc, newColor)
		for _ in ans:
			for __ in _:
				print(__, end = " ")
			print()
# } Driver Code Ends
