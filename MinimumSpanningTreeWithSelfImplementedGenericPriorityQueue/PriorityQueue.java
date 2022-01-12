package com.company;

import java.util.Arrays;
import java.util.Comparator;

public class PriorityQueue<T> {
    private T []arr;
    private int size, cap;
    private Comparator cmp;
    public PriorityQueue() {
        arr = (T[])new Object[25];
        cap = 25;
        size = 0;
        cmp = null;
    }
    public PriorityQueue(Comparator cmp) {
        this();
        this.cmp = cmp;
        if(cmp == null && (arr[0] instanceof Comparable) == false) {
            cmp = new Comparator() {
                @Override
                public int compare(Object o1, Object o2) {
                    System.out.println("hello");
                    double x = (double)o1;
                    double y = (double)o2;
                    if(x < y) {
                        return -1;
                    }
                    else if(x == y) {
                        return 0;
                    }
                    else {
                        return 1;
                    }
                }
            };
        }
        if(cmp == null) {
            System.out.println("No method to compare is available given data structure");
            System.exit(0);
        }
    }

    private int compare(T x, T y) {
        if(cmp != null) {
            return cmp.compare(x, y);
        }
        else {
            Comparable xth = (Comparable)x;
            Comparable yth = (Comparable)y;
            return xth.compareTo(yth);
        }
    }


    private int parent(int idx) {
        return (idx - 1) / 2;
    }
    private int leftChild(int idx) {
        return 2 * idx + 1;
    }
    private int rightChild(int idx) {
        return 2 * idx + 2;
    }
    public int getSize() {
        return size;
    }
    public int getCapacity() {
        return cap;
    }
    public boolean isEmpty() {
        return size == 0;
    }
    private void resize() {
        arr = Arrays.copyOf(arr, this.cap * 2);
        this.cap *= 2;
    }

    private void swap(int l, int r) {
        T temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }

    private void upHeapify(int idx) {

        int par = parent(idx);
        while(idx > 0 && compare(arr[idx], arr[par]) < 0) {
            swap(idx, par);
            idx = par;
            par = parent(idx);
        }

    }
    private void downHeapify(int idx) {
        while(true) {
            int smallest = idx, left = leftChild(idx), right = rightChild(idx);
            if(left < size && compare(arr[smallest], arr[left]) > 0) {
                smallest = left;
            }
            if(right < size && compare(arr[smallest], arr[right]) > 0) {
                smallest = right;
            }
            if(smallest == idx) {
                break;
            }
            else {
                swap(idx, smallest);
                idx = smallest;
            }
        }
    }
    public void delete(int idx) {
        if(idx < 0 || idx >= size) {
            System.out.println("Index out of bound");
            System.exit(0);
        }
        else {
            swap(idx, --size);
            upHeapify(idx);
            downHeapify(idx);
        }
    }
    public void add(T val) {
        if (this.size == this.cap) {
            resize();
        }
        arr[this.size++] = val;
        upHeapify(this.size - 1);
    }



    public T peek() {
        if(isEmpty()) {
            System.out.println("Underflow");
            System.exit(0);
            return null;
        }
        else {
            return arr[0];
        }
    }

    public T poll() {
        if(isEmpty()) {
            System.out.println("Underflow");
            System.exit(0);
            return null;
        }
        else {
            T ans = arr[0];
            delete(0);
            return ans;
        }
    }

}

