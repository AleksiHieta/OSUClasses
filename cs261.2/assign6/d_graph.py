# Course: CS261 - Data Structures
# Author: 
# Assignment: 
# Description: 


class DirectedGraph:
    """
    Class to implement directed weighted graph
    - duplicate edges not allowed
    - loops not allowed
    - only positive edge weights
    - vertex names are integers
    """

    def __init__(self, start_edges=None):
        """
        Store graph info as adjacency list
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.v_count = 0
        self.adj_matrix = []

        # populate graph with initial vertices and edges (if provided)
        # before using, implement add_vertex() and add_edge() methods
        if start_edges is not None:
            v_count = 0
            for u, v, _ in start_edges:
                v_count = max(v_count, u, v)
            for _ in range(v_count + 1):
                self.add_vertex()
            for u, v, weight in start_edges:
                self.add_edge(u, v, weight)

    def __str__(self):
        """
        Return content of the graph in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        if self.v_count == 0:
            return 'EMPTY GRAPH\n'
        out = '   |'
        out += ' '.join(['{:2}'.format(i) for i in range(self.v_count)]) + '\n'
        out += '-' * (self.v_count * 3 + 3) + '\n'
        for i in range(self.v_count):
            row = self.adj_matrix[i]
            out += '{:2} |'.format(i)
            out += ' '.join(['{:2}'.format(w) for w in row]) + '\n'
        out = f"GRAPH ({self.v_count} vertices):\n{out}"
        return out

    # ------------------------------------------------------------------ #

    def add_vertex(self) -> int:
        self.adj_matrix.append([]) 
        self.v_count += 1
        
        for i in range(len(self.adj_matrix)):
            for j in range(self.v_count):
                if (len(self.adj_matrix[i]) < self.v_count):
                    self.adj_matrix[i].append(0)
        return self.v_count

    def add_edge(self, src: int, dst: int, weight=1) -> None:
        if src > self.v_count - 1:
            return None
        if dst > self.v_count - 1:
            return None
        if dst == src:
            return None
        self.adj_matrix[src][dst] = weight
       

 
    def remove_edge(self, src: int, dst: int) -> None:
        if src > self.v_count - 1:
            return None
        if dst > self.v_count - 1:
            return None
        if src < 0:
            return None
        if dst < 0:
            return None
        self.adj_matrix[src][dst] = 0

    def get_vertices(self) -> []:
        vert_list = []

        for i in range(len(self.adj_matrix)):
            vert_list.append(i)

        return vert_list 

    def get_edges(self) -> []:
        gotten = []
        edges = []
        
        new = True
        for i in range(len(self.adj_matrix)):
            y = 0
            for j in self.adj_matrix[i]:
                if j == 0:
                    pass
                else:
                    for k in gotten:
                        if j == k:
                            new = False
                    if new == True:
                        if i != y:
                            edges.append((i, y, j))
                    new = True
                y += 1
            num = i
            #gotten += num
        return edges

    def is_valid_path(self, path: []) -> bool:
        
        if len(path) == 0:
            return True
        for i in range(len(path)):
            if i > self.v_count:
                return False

        if len(path) == 1:
            return True

        curr = self.adj_matrix[path[0]]
        i = 1
        token = True
        while token == True:
            if i == len(path):
                return True
            next_thing = path[i]
            for j in range(len(curr)):
                if j == next_thing:
                    if curr[j] != 0:
                        curr = self.adj_matrix[next_thing]
                        i += 1
                        token = True
                        break
                    else:
                        token = False
        
        return False

    def dfs(self, v_start, v_end=None) -> []:
        reachable = [v_start]
        stack = [v_start]
        

        curr = v_start
        while len(stack) != 0:
            #print("Stack: ", stack)
            #print("Reach: ", reachable)
            stack.remove(curr)
            for i in range(len(self.adj_matrix)-1, -1, -1):
                if self.adj_matrix[curr][i] != 0:
                    #other_key = True
                    #for j in stack:
                    #    if i == j:
                    #        other_key = False
                    #if other_key == True:
                    stack.insert(0, i)
            #print("Stack after adding: ", stack)

            toberemoved = []
            for i in reachable:
                for j in stack:
                    if i == j:
                        toberemoved.append(j)
            for i in toberemoved:
                stack.remove(i)

            if len(stack) == 0:
                return reachable


            addable = True
            for thing in reachable:
                if thing == stack[0]:
                    addable = False
            if addable == True:
                reachable.append(stack[0])
            curr = stack[0] 
        return reachable
        

    def bfs(self, v_start, v_end=None) -> []:
        reachable = [v_start]
        stack = [v_start]
        

        curr = v_start
        while len(stack) != 0:
            #print("Stack: ", stack)
            #print("Reach: ", reachable)
            stack.remove(curr)
            for i in range(len(self.adj_matrix)):
                if self.adj_matrix[curr][i] != 0:
                    #other_key = True
                    #for j in stack:
                    #    if i == j:
                    #        other_key = False
                    #if other_key == True:
                    stack.insert(0, i)
            #print("Stack after adding: ", stack)

            toberemoved = []
            for i in reachable:
                for j in stack:
                    if i == j:
                        toberemoved.append(j)
            for i in toberemoved:
                stack.remove(i)

            if len(stack) == 0:
                return reachable


            addable = True
            for thing in reachable:
                if thing == stack[len(stack)-1]:
                    addable = False
            if addable == True:
                reachable.append(stack[len(stack)-1])
            curr = stack[len(stack)-1] 
        return reachable

    def has_cycle(self):
        for v_start in range(len(self.adj_matrix)):
            reachable = [v_start]
            stack = [v_start]
        

            curr = v_start
            while len(stack) != 0:
                #print("Stack: ", stack)
                #print("Reach: ", reachable)
                stack.remove(curr)
                for i in range(len(self.adj_matrix)-1, -1, -1):
                    if self.adj_matrix[curr][i] != 0:
                        #other_key = True
                        #for j in stack:
                        #    if i == j:
                        #        other_key = False
                        #if other_key == True:
                        stack.insert(0, i)
                #print("Stack after adding: ", stack)
                for i in stack:
                    for j in range(0, len(reachable)-2):
                        if i == reachable[j]:
                            return True


                toberemoved = []
                for i in reachable:
                    for j in stack:
                        if i == j:
                            toberemoved.append(j)
                for i in toberemoved:
                    stack.remove(i)

                if len(stack) == 0:
                    return False


                addable = True
                for thing in reachable:
                    if thing == stack[0]:
                        addable = False
                if addable == True:
                    reachable.append(stack[0])
                curr = stack[0] 
            return False
        

    def dijkstra(self, src: int) -> []:
        reachable = [src]
        """
        stack = [src]
        

        curr = src
        while len(stack) != 0:
            #print("Stack: ", stack)
            #print("Reach: ", reachable)
            stack.remove(curr)
            for i in range(len(self.adj_matrix)-1, -1, -1):
                if self.adj_matrix[curr][i] != 0:
                    #other_key = True
                    #for j in stack:
                    #    if i == j:
                    #        other_key = False
                    #if other_key == True:
                    stack.insert(0, i)
            #print("Stack after adding: ", stack)

            toberemoved = []
            for i in reachable:
                for j in stack:
                    if i == j:
                        toberemoved.append(j)
            for i in toberemoved:
                print(i)
                print(stack)
                stack.remove(i)

            if len(stack) == 0:
                return reachable


            addable = True
            for thing in reachable:
                if thing == stack[0]:
                    addable = False
            if addable == True:
                #reachable.append(stack[0])
                print(stack[0])
                print(curr)
                print(self.adj_matrix[curr][stack[0]])
                reachable.append(self.adj_matrix[curr][stack[0]])
            curr = stack[0]
            print(reachable) 
        """
        return reachable
        
         



if __name__ == '__main__':
    print("\nPDF - method add_vertex() / add_edge example 1")
    print("----------------------------------------------")
    g = DirectedGraph()
    print(g)
    for _ in range(5):
        g.add_vertex()
    print(g)

    edges = [(0, 1, 10), (4, 0, 12), (1, 4, 15), (4, 3, 3),
             (3, 1, 5), (2, 1, 23), (3, 2, 7), (22, 2, 1)]
    for src, dst, weight in edges:
        g.add_edge(src, dst, weight)
    print(g)


    print("\nPDF - method get_edges() example 1")
    print("----------------------------------")
    g = DirectedGraph()
    print(g.get_edges(), g.get_vertices(), sep='\n')
    edges = [(0, 1, 10), (4, 0, 12), (1, 4, 15), (4, 3, 3),
             (3, 1, 5), (2, 1, 23), (3, 2, 7)]
    g = DirectedGraph(edges)
    print(g.get_edges(), g.get_vertices(), sep='\n')


    print("\nPDF - method is_valid_path() example 1")
    print("--------------------------------------")
    edges = [(0, 1, 10), (4, 0, 12), (1, 4, 15), (4, 3, 3),
             (3, 1, 5), (2, 1, 23), (3, 2, 7)]
    g = DirectedGraph(edges)
    print(g)
    test_cases = [[0, 1, 4, 3], [1, 3, 2, 1], [0, 4], [4, 0], [], [2]]
    for path in test_cases:
        print(path, g.is_valid_path(path))


    print("\nPDF - method dfs() and bfs() example 1")
    print("--------------------------------------")
    edges = [(0, 1, 10), (4, 0, 12), (1, 4, 15), (4, 3, 3),
             (3, 1, 5), (2, 1, 23), (3, 2, 7)]
    g = DirectedGraph(edges)
    edges2 = [(0, 1, 1), (0, 2, 1), (0, 3, 1), (1, 2, 1),
             (2, 4, 1), (2, 6, 1), (3, 5, 1), (5, 6, 1)]
    g2 = DirectedGraph(edges2)
    print(g)
    for start in range(5):
        print(f'{start} DFS:{g.dfs(start)} BFS:{g.bfs(start)}')


    print("\nPDF - method has_cycle() example 1")
    print("----------------------------------")
    edges = [(0, 1, 10), (4, 0, 12), (1, 4, 15), (4, 3, 3),
             (3, 1, 5), (2, 1, 23), (3, 2, 7)]
    g = DirectedGraph(edges)

    edges_to_remove = [(3, 1), (4, 0), (3, 2)]
    for src, dst in edges_to_remove:
        g.remove_edge(src, dst)
        print(g.get_edges(), g.has_cycle(), sep='\n')

    edges_to_add = [(4, 3), (2, 3), (1, 3), (4, 0)]
    for src, dst in edges_to_add:
        g.add_edge(src, dst)
        print(g.get_edges(), g.has_cycle(), sep='\n')
    print('\n', g)


    print("\nPDF - dijkstra() example 1")
    print("--------------------------")
    edges = [(0, 1, 10), (4, 0, 12), (1, 4, 15), (4, 3, 3),
             (3, 1, 5), (2, 1, 23), (3, 2, 7)]
    g = DirectedGraph(edges)
    for i in range(5):
        print(f'DIJKSTRA {i} {g.dijkstra(i)}')
    g.remove_edge(4, 3)
    print('\n', g)
    for i in range(5):
        print(f'DIJKSTRA {i} {g.dijkstra(i)}')
