def solution(priorities, location):
    answer = 0
    
    out = []
    while 1:
        for i in range(len(priorities)):
            if max(priorities) == priorities[i]:
                out.append(i)
                priorities[i] = -1
            
            if len(out) == len(priorities):
                break
        if len(out) == len(priorities):
                break
    answer = out.index(location) + 1
    return answer