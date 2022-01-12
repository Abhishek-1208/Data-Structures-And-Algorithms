package com.company;
import java.util.Scanner;

public class Main {
    static class Edge implements Comparable {
        public int x, y, weight;
        Edge(int x, int y, int weight) {
            this.x = x;
            this.y = y;
            this.weight = weight;
        }
        @Override
        public int compareTo(Object other) {
            Integer currWeight = this.weight;
            Integer otherWeight = ((Edge)other).weight;
            return currWeight.compareTo(otherWeight);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for(int i = 1, x, y, weight; i <= m; i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            weight = sc.nextInt();
            Edge temp = new Edge(x, y, weight);
            pq.add(temp);
        }
        DisjointSetUnion ds = new DisjointSetUnion(n + 1);
        int EdgeCount = 0, minimumWeight = 0;
        System.out.println("Edges in the Minimum Spanning Tree of Given graph are as follow");
        while(!pq.isEmpty() && EdgeCount < n - 1) {
            Edge temp = pq.poll();
            int x = temp.x, y = temp.y, weight = temp.weight;
            int x_par = ds.find(x), y_par = ds.find(y);
            if(x_par != y_par) {
                EdgeCount++;
                ds.union(x_par, y_par);
                minimumWeight += weight;
                System.out.println(x + " <---> " + y);
            }
        }
        System.out.println("minimum weight of the spanning tree is " + minimumWeight);
    }
}
