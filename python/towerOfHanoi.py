from collections import deque


def possible_steps(x):
    for i in range(len(x)):
        if x[i]:
            for j in range(len(x)):
                if not x[j] or x[i][-1] < x[j][-1]:
                    yield (i, j)


def target(x):
    return all([len(x[i]) == 0 for i in range(1, len(x))])


def traverse(x):
    def create_tuple(z):
        return tuple(tuple(t) for t in z)

    def take_step(g, m):
        y = [list(t) for t in g]
        y[m[1]].append(y[m[0]].pop())
        # WLOG sort 2nd-4th stacks by order of largest disk
        y[1:4] = sorted(y[1:4], key=lambda t: t[-1] if t else 0)  
        return create_tuple(y)

    visited = set()

    start = (create_tuple(x), 0)

    Collection_deque = deque([start])
    visited.add(start)

    while Collection_deque:
        node, depth = Collection_deque.popleft()

        if target(node):
            return depth

        for go in possible_steps(node):
            descendent = take_step(node, go)
            if descendent not in visited:
                visited.add(descendent)
                Collection_deque.append((descendent, depth+1))

# load the representation from stdin
N = int(input())
stack_of_TOH = [[] for i in range(4)]
Temp = [int(t) for t in input().split()]
for i in range(N):
    stack_of_TOH[Temp[i]-1] = [(i+1)] + stack_of_TOH[Temp[i]-1]

print(traverse(stack_of_TOH))