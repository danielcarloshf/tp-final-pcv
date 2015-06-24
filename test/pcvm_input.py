#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import sys

def generate_graph(v, e):
  costs = [random.randint(1,100) for k in range(v)]
  graph = dict()
  for k in range(e):
    while True:
      i = random.randint(0,v-1)
      j = random.randint(0,v-1)
      if not (i == j) and not (graph.has_key((min(i,j), max(i,j)))):
        graph[(min(i,j), max(i,j))] = True
        break
  return graph, costs

def glpk_output(graph, costs, v, e, filename):
  fo = open(filename, "w")
  
  fo.write("param I := %d;\n"%(v))
  
  fo.write("set A :=\n")
  for i, k in enumerate(graph.keys()):
    sep = ",\n" if i+1 < e else ";\n"
    fo.write("%d %d%s"%(k[0]+1, k[1]+1, sep))
    
  fo.write("param c :=\n")
  for k in range(v):
    sep = ",\n" if k+1 < v else ";\n"
    fo.write("%d %d%s"%((k+1), costs[k], sep))

  fo.write("end;\n")  
  fo.close()

def heur_output(graph, costs, v, e, filename):
  fo = open(filename, "w")
  
  fo.write("%d %d\n"%(v, e))
  for k in range(v):
    fo.write("%d\n"%(costs[k]))
  
  d = {}
  for k in graph.keys():
    if d.has_key(k[0]):
      d[k[0]].append("%d"%(k[1]+1))
    else:
      d[k[0]] = ["%d"%(k[1]+1)]
  
  for k in range(v):
    if d.has_key(k):
      fo.write("%d %s\n"%(k+1, " ".join(d[k])))
    else:
      fo.write("%d\n"%(k+1))
  
  fo.close()

def write_files(v):
  print "Creating input for %d vertexes." % v
  glpk = "solver/input_v%04d.glpk" % v
  heur = "heuristica/input_v%04d.heur" % v
  e = random.randint(int(v/2), int((v*(v-1))/2))
  graph, costs = generate_graph(v, e)
  heur_output(graph, costs, v, e, heur)
  glpk_output(graph, costs, v, e, glpk)

def main():
  write_files(10)
  write_files(20)
  write_files(30)
  write_files(40)
  write_files(50)
  write_files(60)
  write_files(70)
  write_files(80)
  write_files(90)
  write_files(100)
  print "Done!"

if __name__=='__main__':
  main()
