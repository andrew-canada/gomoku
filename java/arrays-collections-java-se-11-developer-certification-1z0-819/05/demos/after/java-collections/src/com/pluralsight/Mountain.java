package com.pluralsight;

public class Mountain implements Comparable<Mountain> {
    private String name;
    private int height;

    public Mountain(String n, int h){
        this.name = n;
        this.height = h;
    }

    public int compareTo(Mountain o) {
        return this.height - o.height;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }
}
