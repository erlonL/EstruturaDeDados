# -*- coding: utf-8 -*-
import queue

class Graph:
    def __init__(self, n):
        self.num_vertices = n
        self.matrix = [[0 for _ in range(n)] for _ in range(n)]
        self.list = [[] for _ in range(n)]
        

    def print(self):
        print(self.matrix)
        print(self.list)

    def adj_list(self, v):
        return self.list[v] # v = índice da lista de listas
    
    def print_adjs(self):
        print("Listas de adjacências")
        for i in range(self.num_vertices):
            print("{} - {}".format(i, self.list[i]))
        
        
    def bfs(self, source):
        dist = [-1 for _ in range(self.num_vertices)]
        ant = [-1 for _ in range(self.num_vertices)]
        isVisited = [False for _ in range(self.num_vertices)]

        # print("{}, {}, {}".format(dist, ant, isVisited))

        Q = queue.Queue() # criando instância da fila
        Q.put(source) # inserindo o primeiro elemento na fila
        isVisited[source] = True # o primeiro elemento (origem) já foi visitado (é o próprio)
        dist[source] = 0 # a distância da origem pra origem é sempre 0

        visited = []
        
        while Q.empty() != True:
            p = Q.get()
            visited.append(p)

            print("{} - {}".format(p, self.list[p]))
            for v in self.list[p]:
                print("v: {}".format(v))
                if isVisited[v] == False:
                    # print("NÃO VISITADO AINDA!")
                    dist[v] = dist[p] + 1
                    print("dist[{}] = dist[{}] + 1 = {}".format(v, p, dist[v]))
                    ant[v] = p
                    print("ant[{}] = {}".format(v, p))
                    Q.put(v) # adiciona os vértices adjacentes a p à fila
                    isVisited[v] = True
            print()
            
        print("Visitados: {}".format(visited))
        return dist, ant
    
    def bfs_search(self, v1, v2):
        dist = [-1 for _ in range(self.num_vertices)]
        ant = [-1 for _ in range(self.num_vertices)]
        isVisited = [False for _ in range(self.num_vertices)]

        # print("{}, {}, {}".format(dist, ant, isVisited))

        Q = queue.Queue()
        Q.put(v1)
        isVisited[v1] = True
        dist[v1] = 0


        visited = []
        # visited.append(v1)

        while Q.empty() != True:
            p = Q.get()

            for v in self.list[p]:
                if isVisited[v] == False:
                    dist[v] = dist[p] + 1
                    Q.put(v)
                    isVisited[v] = True
                    ant[v] = p

                    if v2 in self.list[v] or v2 == v:
                        # print("v: {}".format(v))
                        # print(visited)
                        if dist[v] > 1:
                            while ant[v] != v1:
                                visited.append(v2)
                                visited.append(v)
                                visited.append(ant[v])
                                v = ant[v]
                        else:
                            visited.append(v2)
                            visited.append(v)
                            
                            # dist[v] = dist[p] + 1
                        # dist[v2] = dist[p] + 1

                        visited.append(v1)
                        visited = visited[::-1]
                        return visited
        print("Não há caminho entre os vértices")
        return None, None

