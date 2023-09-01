# Course: 
# Author: 
# Assignment: 
# Description:

#from stack_da import *

class UndirectedGraph:
    """
    Class to implement undirected graph
    - duplicate edges not allowed
    - loops not allowed
    - no edge weights
    - vertex names are strings
    """

    def __init__(self, start_edges=None):
        """
        Store graph info as adjacency list
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.adj_list = dict()

        # populate graph with initial vertices and edges (if provided)
        # before using, implement add_vertex() and add_edge() methods
        if start_edges is not None:
            for u, v in start_edges:
                self.add_edge(u, v)

    def __str__(self):
        """
        Return content of the graph in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        out = [f'{v}: {self.adj_list[v]}' for v in self.adj_list]
        out = '\n  '.join(out)
        if len(out) < 70:
            out = out.replace('\n  ', ', ')
            return f'GRAPH: {{{out}}}'
        return f'GRAPH: {{\n  {out}}}'

    # ------------------------------------------------------------------ #

    def add_vertex(self, v: str) -> None:
        self.adj_list[v] = []
        #print("ADDED VERTEX")
        return None           


 
    def add_edge(self, u: str, v: str) -> None:
        """
        TODO: Write this implementation
        """
        #print(self)
        
        #print(self.adj_list[u])
        #if self.adj_list[u] is None:
        #    self.add_vertex(u)
        #if self.adj_list[v] is None:
        #    self.add_vertex(v)

        if u == v:
            return None

        if self.adj_list.get(u) is None:
            self.add_vertex(u)
        if self.adj_list.get(v) is None:
            self.add_vertex(v)
        #self.add_vertex(u)
        #self.add_vertex(v)
       
        v_exists = False
        for i in range(len(self.adj_list[u])):
            if self.adj_list[u][i] == v:
                v_exists = True
             
        if not (v_exists):
            self.adj_list[u].append(v)

        u_exists = False
        for i in range(len(self.adj_list[v])):
            if self.adj_list[v][i] == u:
                u_exists = True
             
        if not (u_exists):
            self.adj_list[v].append(u)
        #self.adj_list[v][len(self.adj_list[v])-1] = u
        #self.adj_list[v] = u
        return None
        

    def remove_edge(self, v: str, u: str) -> None:
        if self.adj_list.get(u) is None:
            #raise Exception
            return None
        if self.adj_list.get(v) is None:
            #raise Exception
            return None
        
        for i in range(len(self.adj_list[v])):
            if self.adj_list[v][i] == u:
                del self.adj_list[v][i]
                break

        for i in range(len(self.adj_list[u])):
            if self.adj_list[u][i] == v:
                del self.adj_list[u][i]
                break
        pass  

    def remove_vertex(self, v: str) -> None:
        if self.adj_list.get(v) is None:
            return None
        else:
            del self.adj_list[v] 
        

        vert_list = self.adj_list.keys()

        for i in self.adj_list:
            thing = i
            #thang = self.adj_list[vert_list[i]]
            for j in range(len(self.adj_list[thing])):
                if self.adj_list[thing][j] == v:
                    del self.adj_list[thing][j]
                    break
                    
        pass

    def get_vertices(self) -> []:
        vert_list = []

        vert_list = self.adj_list.keys()

        real_vert_list = []

        for i in vert_list:
            real_vert_list.append(i)

        return real_vert_list

    def get_edges(self) -> []:
        edges = []
        gotten = []
        vert_list = self.adj_list.keys()

        new = True
        for i in self.adj_list:
            for j in self.adj_list[i]:
                for k in gotten:
                    if j == k:
                        new = False

                if new == True:
                    edges.append((i, j))
                new = True
            gotten += i
        return edges 

    def is_valid_path(self, path: []) -> bool:
        if len(path) == 0:
            return True

        for i in range(len(path)):
            if self.adj_list.get(path[i]) is None:
                return False
  
        if len(path) == 1:
            return True

        curr = self.adj_list[path[0]]
        #print(curr)
        i = 1
        token = True
        while token == True:
            if i == len(path):
                return True
            next_thing = path[i]
            for j in range(len(curr)):
                #print("CURR[j] ", curr[j])
                #print("Compare: ", next_thing)
                if curr[j] == next_thing:
                    #print("====MOVED FORWARD=====")
                    #print("Next Thing ", next_thing)
                    curr = self.adj_list[next_thing]
                    i += 1
                    token = True
                    break
                else:
                    token = False

        return False



    def dfs(self, v_start, v_end=None) -> []:
        verts = self.get_vertices()

        if verts.count(v_start) == 0:
            return []

        reachable = [v_start]
        stack = [v_start]

        if v_start == v_end:
            return reachable

        prev_curr = 0
        curr = v_start
        done = False
        if done == False:     #IGNOREIGNOREIGNORE
            #print("Stack: ", stack)
            #print("Reach: ", reachable)

            for i in self.adj_list[curr]:
                stack.insert(0, i)

            working_stack = []

            for i in range(len(stack)):
                working_stack.append(min(stack))
                stack.remove(min(stack))
                
            #print("Working Stack: ", working_stack)

            gotten = False
            done = True
            explore = []
            #reachable.append(curr)

            for i in working_stack:
                #print("In for loop")
                #print("i: ", i)
                #print(reachable)
                if reachable.count(i) == 0:
                    #print("If state")
                    curr = i
                    explore.append(i)
                else:
                    continue
            #print("=====", explore, "======")
            for i in explore:
                #print("Next Up: ", i)
                #print(reachable)
                self.dfs_helper(i, reachable)

            real_reachable = []            #clear out doubles
            for i in reachable:
                if real_reachable.count(i) == 0:
                    real_reachable.append(i)


            """ 
            if v_end != None:
                takeoff = []
                for v in real_reachable:
                    if v < v_start:
                        takeoff.append(v)
                    elif v > v_end:
                        takeoff.append(v)
                for i in takeoff:
                    real_reachable.remove(i)
            for i in real_reachable:
                thang = self.adj_list[i]
                key = True
                for j in thang:
                    #print("j: ",j)
                    if real_reachable.count(j) == 0:
                        curr = i
                        #print("New_curr: ", curr)
                        
                    else:
                        key = False
                if key == False:
                    return real_reachable
            """

        if v_end is not None:
            for i in real_reachable:
                if v_end == i:
                    stop = i
                    for ex in range(len(real_reachable)-1, real_reachable.index(stop), -1):
                        del real_reachable[ex]

        
        return real_reachable


    def dfs_helper(self, curr, reachable):
        #print(reachable)
        stack = [curr]
        for i in self.adj_list[curr]:
            stack.insert(0, i)

        #print("Stack: ", stack)
        working_stack = []

        for i in range(len(stack)):
            working_stack.append(min(stack))
            stack.remove(min(stack))
                
        gotten = False
        done = True
        explore = []
        #print("Working Stack: ", curr,  working_stack)
        #print("Curr: ", curr)
        #if reachable.count(curr == 0):
        reachable.append(curr)
        
        for i in working_stack:
            #print("In for loop")
            #print("i: ", i)
            #print(reachable)
            if reachable.count(i) == 0:
                #print("If state")
                curr = i
                explore.append(i)
                self.dfs_helper(curr, reachable)
            else:
                continue





    def bfs(self, v_start, v_end=None) -> []:
        verts = self.get_vertices()

        if verts.count(v_start) == 0:
            return []


        reachable = [v_start]
        stack = [v_start]

        if v_start == v_end:
            return reachable

        prev_curr = 0
        curr = v_start
        done = False
        if done == False:     #IGNOREIGNOREIGNORE
            #print("Stack: ", stack)
            #print("Reach: ", reachable)

            for i in self.adj_list[curr]:
                stack.insert(0, i)

            working_stack = []

            for i in range(len(stack)):
                working_stack.append(min(stack))
                stack.remove(min(stack))
                
            #print("Working Stack: ", working_stack)

            gotten = False
            done = True
            explore = []
            for i in working_stack:
                #print("In for loop")
                #print("i: ", i)
                #print(reachable)
                if reachable.count(i) == 0:
                    #print("If state")
                    reachable.append(i)
                    curr = i
                    explore.append(i)
                else:
                    continue
            for i in explore:
                #print("Next Up: ", i)
                #print(reachable)
                self.bfs_helper(i, reachable)

        
        if v_end is not None:
            for i in reachable:
                if v_end == i:
                    stop = i
                    for ex in range(len(reachable)-1, reachable.index(stop), -1):
                        del reachable[ex]

        return reachable

    def bfs_helper(self, curr, reachable):
        stack = [curr]
        for i in self.adj_list[curr]:
            stack.insert(0, i)

        #print("Stack: ", stack)
        working_stack = []

        for i in range(len(stack)):
            working_stack.append(min(stack))
            stack.remove(min(stack))
                
        gotten = False
        done = True
        explore = []
        #print("Working Stack: ", curr,  working_stack)
        for i in working_stack:
            #print("In for loop")
            #print("i: ", i)
            #print(reachable)
            if reachable.count(i) == 0:
                #print("If state")
                reachable.append(i)
                curr = i
                explore.append(i)
            else:
                continue

        for i in explore:
            #print("Next up: ", i)
            #print(reachable)
            self.bfs_helper(i, reachable)


    def count_connected_components(self) -> int:
        vert_list = []
        vert_list = self.adj_list.keys()
        real_vert_list = []
        for i in vert_list:
            real_vert_list.append(i)

        visited = [False for i in range(len(self.adj_list))]
        count = 0

        for i in self.adj_list:
            idx = real_vert_list.index(i)
            if (visited[idx] == False):
                self.THANG(idx, visited)
                count += 1

        return count

    def THANG(self, idx, visited):
        #print(visited)
        vert_list = []
        vert_list = self.adj_list.keys()
        real_vert_list = []
        for i in vert_list:
            real_vert_list.append(i)

        visited[idx] = True
        for i in self.adj_list[real_vert_list[idx]]:
            idx2 = real_vert_list.index(i)
            if not visited[idx2]:
                self.THANG(idx2, visited)
        pass

    def has_cycle(self) -> bool:
        Cycle = False
        #v_start = self.get_vertices()[0]

        for v_start in self.get_vertices():

            reachable = [v_start]
            stack = [v_start]

            prev_curr = 0
            curr = v_start
            done = False
            if done == False:     #IGNOREIGNOREIGNORE
                #print("Stack: ", stack)
                #print("Reach: ", reachable)

                for i in self.adj_list[curr]:
                    stack.insert(0, i)

                working_stack = []

                for i in range(len(stack)):
                    working_stack.append(min(stack))
                    stack.remove(min(stack))
                
                #print("Working Stack: ", working_stack)

                gotten = False
                done = True
                explore = []
                for i in working_stack:
                    #print("In for loop")
                    #print("i: ", i)
                    #print(reachable)
                    if reachable.count(i) == 0:
                        #print("If state")
                        reachable.append(i)
                        curr = i
                        explore.append(i)
                    else:
                        continue
                for i in explore:
                    #print("Next Up: ", i)
                    #print(reachable)
                    Cycle = self.cycle_helper(i, reachable, Cycle)
                    if Cycle == True:
                        return True
    

        
        return Cycle

    def cycle_helper(self, curr, reachable, Cycle) -> bool:
        #print(curr)
   
        stack = [curr]
        for i in self.adj_list[curr]:
            stack.insert(0, i)

        #print("Stack: ", stack)
        working_stack = []

        for i in range(len(stack)):
            working_stack.append(min(stack))
            stack.remove(min(stack))
                
        gotten = False
        done = True
        explore = []
        #print("Working Stack: ", curr,  working_stack)
        for i in working_stack:
            #print("In for loop")
            #print("i: ", i)
            #print(reachable)
            if reachable.count(i) == 0:
                #print("If state")
                reachable.append(i)
                curr = i
                explore.append(i)
            else:
                if len(reachable) > 2:
                    for j in range(len(reachable)-3):
                        print(reachable)
                        print(reachable[j])
                        print(i)
                        if reachable[j] == i:
                            #print("CYCLE")
                            return True 
                continue

        for i in explore:
            #print("Next up: ", i)
            #print(reachable)
            self.cycle_helper(i, reachable, Cycle)
        return False




if __name__ == '__main__':

    print("\nPDF - method add_vertex() / add_edge example 1")
    print("----------------------------------------------")
    g = UndirectedGraph()
    print(g)

    for v in 'ABCDE':
        g.add_vertex(v)
    print(g)

    g.add_vertex('A')
    print(g)

    for u, v in ['AB', 'AC', 'BC', 'BD', 'CD', 'CE', 'DE', ('B', 'C'), 'FF']:
        g.add_edge(u, v)
    print(g)


    print("\nPDF - method remove_edge() / remove_vertex example 1")
    print("----------------------------------------------------")
    g = UndirectedGraph(['AB', 'AC', 'BC', 'BD', 'CD', 'CE', 'DE'])
    print(g)
    g.remove_vertex('DOES NOT EXIST')
    g.remove_edge('A', 'B')
    g.remove_edge('X', 'B')
    print(g)
    g.remove_vertex('D')
    print(g)


    print("\nPDF - method get_vertices() / get_edges() example 1")
    print("---------------------------------------------------")
    g = UndirectedGraph()
    print(g.get_edges(), g.get_vertices(), sep='\n')
    g = UndirectedGraph(['AB', 'AC', 'BC', 'BD', 'CD', 'CE'])
    print(g.get_edges(), g.get_vertices(), sep='\n')


    print("\nPDF - method is_valid_path() example 1")
    print("--------------------------------------")
    g = UndirectedGraph(['AB', 'AC', 'BC', 'BD', 'CD', 'CE', 'DE'])
    print(g)
    test_cases = ['ABC', 'ADE', 'ECABDCBE', 'ACDECB', '', 'D', 'Z']
    for path in test_cases:
        #print(path)
        print(list(path), g.is_valid_path(list(path)))


    print("\nPDF - method dfs() and bfs() example 1")
    print("--------------------------------------")
    edges = ['AE', 'AC', 'BE', 'CE', 'CD', 'CB', 'BD', 'ED', 'BH', 'QG', 'FG']
    g = UndirectedGraph(edges)
    print(g)
    test_cases = 'ABCDEGH'
    for case in test_cases:
        print(f'{case} DFS:{g.dfs(case)} BFS:{g.bfs(case)}')
    print('-----')
    for i in range(1, len(test_cases)):
        v1, v2 = test_cases[i], test_cases[-1 - i]
        print(f'{v1}-{v2} DFS:{g.dfs(v1, v2)} BFS:{g.bfs(v1, v2)}')


    print("\nPDF - method count_connected_components() example 1")
    print("---------------------------------------------------")
    edges = ['AE', 'AC', 'BE', 'CE', 'CD', 'CB', 'BD', 'ED', 'BH', 'QG', 'FG']
    g = UndirectedGraph(edges)
    test_cases = (
        'add QH', 'remove FG', 'remove GQ', 'remove HQ',
        'remove AE', 'remove CA', 'remove EB', 'remove CE', 'remove DE',
        'remove BC', 'add EA', 'add EF', 'add GQ', 'add AC', 'add DQ',
        'add EG', 'add QH', 'remove CD', 'remove BD', 'remove QG')
    for case in test_cases:
        #print(g)
        command, edge = case.split()
        u, v = edge
        g.add_edge(u, v) if command == 'add' else g.remove_edge(u, v)
        print(g.count_connected_components(), end=' ')
    print()


    print("\nPDF - method has_cycle() example 1")
    print("----------------------------------")
    edges = ['AE', 'AC', 'BE', 'CE', 'CD', 'CB', 'BD', 'ED', 'BH', 'QG', 'FG']
    g = UndirectedGraph(edges)
    test_cases = (
        'add QH', 'remove FG', 'remove GQ', 'remove HQ',
        'remove AE', 'remove CA', 'remove EB', 'remove CE', 'remove DE',
        'remove BC', 'add EA', 'add EF', 'add GQ', 'add AC', 'add DQ',
        'add EG', 'add QH', 'remove CD', 'remove BD', 'remove QG',
        'add FG', 'remove GE')
    print(g)
    for case in test_cases:
        command, edge = case.split()
        u, v = edge
        g.add_edge(u, v) if command == 'add' else g.remove_edge(u, v)
        print('{:<10}'.format(case), g.has_cycle())
