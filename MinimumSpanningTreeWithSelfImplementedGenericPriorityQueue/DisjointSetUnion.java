package com.company;

public class DisjointSetUnion {
    private int [] parent;
    private int [] rank;
    public DisjointSetUnion(int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    public int find(int x) {
        return (parent[x] == x ? x : (parent[x] = find(parent[x])));
    }
    public boolean union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);
        if(x_par == y_par) {
            return false;
        }
        else {
            if(rank[x_par] < rank[y_par]) {
                parent[x_par] = y_par;
            }
            else if(rank[y_par] < rank[x_par]) {
                parent[y_par] = x_par;
            }
            else {
                parent[y_par] = x_par;
                rank[x_par]++;
            }
            return true;
        }
    }
}
