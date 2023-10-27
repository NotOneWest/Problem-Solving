visited = []
ans = 0

def dfs(n, size, index, k, dungeons):
    global ans
    if n == size:
        cnt = 0
        for i in range(size):
            if k < dungeons[index[i]][0]:
                continue
            k -= dungeons[index[i]][1]
            cnt+=1
        if ans < cnt:
            ans = cnt
        
    for i in range(size):
        if visited[i] == 1:
            continue
        visited[i] = 1
        index.append(i)
        dfs(n+1, size, index, k, dungeons)
        visited[i] = 0
        index.pop()

def solution(k, dungeons):
    for i in range(len(dungeons)):
        visited.append(0)
    dfs(0, len(dungeons), [], k, dungeons)
    return ans